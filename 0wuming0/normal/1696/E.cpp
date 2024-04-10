#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll jie[400005];
ll dev[400005];
ll devjie[400005];
ll a[400005];
ll C(int n,int m)
{
    return jie[n]*devjie[m]%mod*devjie[n-m]%mod;
}
int main()
{
    jie[0]=devjie[0]=dev[1]=1;;
    for(int i=2;i<400005;i++)dev[i]=(mod-mod/i)*dev[mod%i]%mod;
    for(int i=1;i<400005;i++)
    {
        jie[i]=jie[i-1]*i%mod;
        devjie[i]=devjie[i-1]*dev[i]%mod;
    }
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)scanf("%lld",a+i);
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        a[i]--;
        if(a[i]>=0)ans+=C(i+a[i]+1,i+1);
    }
    cout<<ans%mod<<endl;
    return 0;
}