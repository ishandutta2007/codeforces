#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<double> v(n);
    double sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << (sum/n);
    return 0;
}