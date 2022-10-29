#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() 
{
    long long n,l;
    cin>>n>>l;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long max=(v[0]-0)*2;
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1]-v[i]>max)
        {
            max=v[i+1]-v[i];
        }
    }
    if(2*(l-v[n-1])>max)
    {
        max=(l-v[n-1])*2;
    }
    double ans=(double)max/2;
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    std::cout <<ans;

    
    return 0;
}