#include <iostream>
#include <string>
using namespace std;

struct Tree
{
    int temperature;
    int time;
    string model;
    string district;
    Tree *left;
    Tree *right;
};

Tree* creationOfFirstElement(int temperature, int time, const string& model, const string& district)
{
    Tree *first = new Tree;
    first->temperature = temperature;
    first->time = time;
    first->model = model;
    first->district = district;
    first->left = 0;
    first->right = 0;
    return first;
}

Tree* insertion(Tree* root, int temperature, int time, const string& model, const string& district)
{
    if (root == 0)
    {
        root = creationOfFirstElement(temperature, time, model, district);
    }
    else if (temperature < root->temperature)
    {
        root->left = insertion(root->left, temperature, time, model, district);
    }
    else
    {
        root->right = insertion(root->right, temperature, time, model, district);
    }
    return root;
}

double calculateAverageTemperatureForDistricts(Tree* root, const string& district)
{
    int sum = 0;
    int count = 0;
    if (root == 0)
    {
        return 0;
    }
    if (root->district == district)
    {
        sum += root->temperature;
        count++;
    }

    double leftAverage = calculateAverageTemperatureForDistricts(root->left, district);
    double rightAverage = calculateAverageTemperatureForDistricts(root->right, district);

    sum += leftAverage + rightAverage;
    count += (leftAverage != 0) + (rightAverage != 0);

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return double(sum) / count;
    }
}

int findMinTemperature(Tree* root, const string& model)
{
    int max=1000;
    if (root == 0)
    {
        return max;
    }
    if (root->model == model)
    {
        return min(root->temperature, min(findMinTemperature(root->left, model), findMinTemperature(root->right, model)));
    }
    else if (model < root->model)
    {
        return findMinTemperature(root->left, model);
    }
    else
    {
        return findMinTemperature(root->right, model);
    }
}
int findMaxTemperature(Tree* root, const string& model)
{
    int min=-1000;
    if (root == 0)
    {
        return min;
    }
    if (root->model == model)
    {
        return max(root->temperature, max(findMaxTemperature(root->left, model), findMaxTemperature(root->right, model)));
    }
    else if (model < root->model)
    {
        return findMaxTemperature(root->left, model);
    }
    else
    {
        return findMaxTemperature(root->right, model);
    }
}
double calculateAverageBetween12and16(Tree *root, int time, const string& district, int startClock=12, int endClock=16)
{
    float sum=0;
    float count=0;
    if (root == 0)
    {
        return 0;
    }
    if (root->time>startClock&&root->time<endClock)
    {
        sum += root->temperature;
        count++;
    }
    double leftAverage = calculateAverageTemperatureForDistricts(root->left, district);
    double rightAverage = calculateAverageTemperatureForDistricts(root->right, district);

    sum += leftAverage + rightAverage;
    count += (leftAverage != 0) + (rightAverage != 0);

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return double(sum) / count;
    }
}
void printTree(Tree* root)
{
    if (root==0)
    {
        return;
    }
    printTree(root->left);
    cout << "Temperature: " << root->temperature <<" | "<< " Time: " << root->time <<" | " << " Model: " << root->model <<" | "<< " District: "<<root->district<< endl;
    printTree(root->right);
}


int main()
{
    Tree* root=0;
    int START_CLOCK=12, END_CLOCK=16;
    root = insertion(root, 20, 8, "analog", "Bukovynskyi");
    root = insertion(root, 22, 10, "digital", "Shevchenkivskyi");
    root = insertion(root, 18, 12, "analog", "Pershotravnevyi");
    root = insertion(root, 25, 14, "digital", "Bukovynskyi");
    root = insertion(root, 23, 16, "digital", "Shevchenkivskyi");
    root = insertion(root, 21, 18, "analog", "Pershotravnevyi");
    root = insertion(root, 19, 20, "digital", "Bukovynskyi");
    root = insertion(root, 24, 22, "analog", "Shevchenkivskyi");
    root = insertion(root, 17, 24, "analog", "Pershotravnevyi");
    root = insertion(root, 26, 2, "digital", "Shevchenkivskyi");
    root = insertion(root, 27, 4, "digital", "Bukovynskyi");
    root = insertion(root, 28, 6, "analog", "Shevchenkivskyi");
    printTree(root);
    cout<<"⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎"<<endl;
    double averageTempBukovynskyi = calculateAverageTemperatureForDistricts(root, "Bukovynskyi");
    cout<<"Average temperature in Bukovynskyi district: " << averageTempBukovynskyi << " Celsius" << endl;

    double averageTempShevchenkivskyi = calculateAverageTemperatureForDistricts(root, "Shevchenkivskyi");
    cout<<"Average temperature in Shevchenkivskyi district: " << averageTempShevchenkivskyi << " Celsius" << endl;
    
    double averageTempPershotravnevyi = calculateAverageTemperatureForDistricts(root, "Pershotravnevyi");
    cout<<"Average temperature in Pershotravnevyi district: " << averageTempPershotravnevyi << " Celsius" << endl;
    
    cout<<"⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎"<<endl;
    
    int minTempAnalog = findMinTemperature(root, "analog");
    int maxTempAnalog = findMaxTemperature(root, "analog");
    cout << "Minimum temperature measured with analog thermometer: " << minTempAnalog << " Celsius" << endl;
    cout << "Maximum temperature measured with analog thermometer: " << maxTempAnalog << " Celsius" << endl;

    int minTempDigital = findMinTemperature(root, "digital");
    int maxTempDigital = findMaxTemperature(root, "digital");
    cout << "Minimum temperature measured with digital thermometer: " << minTempDigital << " Celsius" << endl;
    cout << "Maximum temperature measured with digital thermometer: " << maxTempDigital << " Celsius" << endl;

    cout<<"⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎⭐︎"<<endl;
    
    double averageTempBetween12and16_Bukovynskyi = calculateAverageBetween12and16(root, START_CLOCK, "Bukovynskyi", START_CLOCK, END_CLOCK);
    cout<<"Average temperature between 12 and 16 o'clock in Bukovynskyi district: " << averageTempBetween12and16_Bukovynskyi << " Celsius" << endl;

    double averageTempBetween12and16_Shevchenkivskyi = calculateAverageBetween12and16(root, START_CLOCK, "Shevchenkivskyi", START_CLOCK, END_CLOCK);
    cout<<"Average temperature between 12 and 16 o'clock in Shevchenkivskyi district: " << averageTempBetween12and16_Shevchenkivskyi << " Celsius" <<endl;
        
    double averageTempBetween12and16_Pershotravnevyi = calculateAverageBetween12and16(root, START_CLOCK, "Pershotravnevyi", START_CLOCK, END_CLOCK);
    cout<<"Average temperature between 12 and 16 o'clock in Pershotravnevyi district: " << averageTempBetween12and16_Pershotravnevyi << " Celsius" <<endl;
    cout<<endl;


}
