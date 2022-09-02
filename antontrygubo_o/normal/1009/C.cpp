#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, m;
    cin>>n>>m;
    long double result = 0;
    long double x, d;
    ll plus = 0;
    ll minus = 0;
    for (int i = 0; i<n; i++) plus+=i;
    for (int i = 0; i<n; i++) minus+=fabs(n/2-i);
    long double n1 = n;
    
    long double result1 = 0;
    
    for (int i = 0; i<m; i++)
    {
        cin>>x>>d;
        result1+=x;
        if (d<0) result+=(d*minus);
        if (d>0) result+=(d*plus);
    }
    cout<<setprecision(10)<<(result/n1)+result1;
}