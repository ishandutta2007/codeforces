#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int a, b, c;
    cin>>a;
    if(a<=2)
    {
        cout<<"-1";
        return 0;
    }
    int store=1;
    while(a%2==0)
    {
        a/=2;
        store*=2;
    }
    if(a==1)
    {
        store/=4;
        a=4*store;
        b=3*store;
        c=5*store;
    }
    else
    {
        b=(a*a-1)/2 * store;
        c=(a*a+1)/2 * store;
    }
    cout<<b<<" "<<c; 
}