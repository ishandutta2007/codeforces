#include<iostream>
#include<algorithm>
#include<random>
#include<string>
#include<cstdio>
#include<math.h>
#include <iomanip>
using namespace std;

int main()
{
int n;
cin>>n;
long double r;
cin>>r;


long double x[n];
for (int i = 0; i<n; i++) {cin>>x[i]; }
long double y[n];
for (int i = 0; i<n; i++)
{
    long double stop = r;
    for (int j = 0; j<i; j++)
    {
        if(fabs(x[i]-x[j])<=2*r) stop = max(stop, sqrt(4*r*r - (x[i]-x[j])*(x[i]-x[j]))+y[j]);
    }
    y[i]=stop;
}
for (int i = 0; i<n; i++) cout<<setprecision(14)<<y[i]<<' ';
}