#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll jie[2000005],dev[2000005],devjie[2000005];
ll dev2[2000005];
ll dp[1000105];
ll C(ll n,ll m)
{
    return jie[n]*devjie[m]%mod*devjie[n-m]%mod;
}
int main()
{
    jie[0]=devjie[0]=dev2[0]=1;
    dev[1]=1;
    for(int i=2;i<2000005;i++)dev[i]=(mod-mod/i)*dev[mod%i]%mod;
    for(int i=1;i<2000005;i++)
    {
        jie[i]=jie[i-1]*i%mod;
        devjie[i]=devjie[i-1]*dev[i]%mod;
        dev2[i]=dev2[i-1]*500000004%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,t;
        cin>>n>>m>>t;
        m=n-m;
        for(int i=0;i<=n+5;i++)dp[i]=0;
        for(int i=n;i>=0;i--)dp[i]=(n-i)*(ll)t%mod;/*
        for(int j=m-1;j>=0;j--)for(int i=n-m+j;i>=0;i--)
        {
            dp[i][j]=(dp[i+1][j]+dp[i+1][j+1])*500000004%mod;
        }*/
        ll ans=0;
        ll ds=0;
        for(int i=n-1;i>=m;i--)
        {
            ds=ds*500000004%mod;
            dp[i]-=ds;
            ds+=dp[i];
            ds%=mod;
            //cout<<"<<<"<<i<<" "<<C(i,m)<<"  "<<i<<" "<<m<<endl;
            ans+=C(i,m)*dp[i]%mod*dev2[i]%mod;
        }
        ans%=mod;
        if(ans<0)ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}