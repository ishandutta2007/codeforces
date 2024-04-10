#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,r;
        cin>>n>>r;
        r*(r+1)/2;
        ll ans=r-n;
        if(ans>=0)
        {
            n--;
            ans=n*(n+1)/2+1;
        }
        else ans=r*(r+1)/2;
        cout<<ans<<endl;
    }
    return 0;
}