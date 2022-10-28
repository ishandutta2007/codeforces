#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    double s, a, b, c;
    cin>>s>>a>>b>>c;
    double ansa, ansb, ansc;
    if(a==0 && b==0 && c==0)
        ansa=0, ansb=0, ansc=0;
    else
    {
        ansa=(s*a)/(a+b+c);
        ansb=(s*b)/(a+b+c);
        ansc=(s*c)/(a+b+c);
    }
    cout<<fixed<<setprecision(12)<<ansa<<" "<<ansb<<" "<<ansc;
    return 0;
}