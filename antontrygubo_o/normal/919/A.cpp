#include<bits/stdc++.h>
using namespace std;


int main()
{
double n, m;
cin>>n>>m;
double min1 = 100; double min2 = 1;
for (int i = 0; i<n; i++)
{
    int a, b;
    cin>>a>>b;
    if (min1*b>min2*a) {min1 = a; min2 = b;}
}
double k = (min1*m)/min2;
cout<<setprecision(10)<<k;

}