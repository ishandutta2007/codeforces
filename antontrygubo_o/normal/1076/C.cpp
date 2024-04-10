#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

void solve()
{
    double d;
    cin>>d;
    if (d>0.5&&d<3.5) {cout<<'N'<<endl; return;}
    double a = (d+sqrt(d*d-4*d))/2;
    double b = (d-sqrt(d*d-4*d))/2;
    cout<<"Y "<<setprecision(12)<<a<<' '<<b<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for (int i = 0; i<t; i++)
    {
        solve();
    }
}