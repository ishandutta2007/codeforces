#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define gcd __gcd
ll a[1005];
ll mod=1e9+7;
int main()
{
    a[2]=2;
    for(int i=3;i<=42;i++)a[i]=a[i-1]/gcd(a[i-1],i*1ll)*i;
    for(int i=42;i>=3;i--)a[i]/=a[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=2;n;i++)
        {
            ans+=(n-n/a[i])%mod*i%mod;
            n/=a[i];
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}