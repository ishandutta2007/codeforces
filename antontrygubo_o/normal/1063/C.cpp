#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string temp;
    ll l = 0;
    ll r = 1;
    for (int i = 0; i<29; i++) r*=2;
    cout<<0<<' '<<1<<endl;
    cout.flush();
    cin>>temp;
    if (temp=="white")
    {
        for (int i = 1; i<n; i++)
        {
            ll k = (l+r)/2;
            cout<<k<<' '<<1<<endl;
            cout.flush();
            cin>>temp;
            if (temp=="white") l = k;
            else r = k;
        }
    }
    else
    {
        for (int i = 1; i<n; i++)
        {
            ll k = (l+r)/2;
            cout<<k<<' '<<1<<endl;
            cout.flush();
            cin>>temp;
            if (temp=="black") l = k;
            else r = k;
        }
    }
    cout<<l<<' '<<2<<' '<<r<<' '<<0;
}