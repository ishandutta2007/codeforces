#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
char s[5005];
ll dp[5005][2];
ll jie[10005],dev[10005],devjie[10005];
ll C(ll n,ll m)
{
    if(m>n||m<0)return 0;
    return jie[n]*devjie[m]%mod*devjie[n-m]%mod;
}
int main()
{
    dev[1]=1;
    for(int i=2;i<10005;i++)dev[i]=(mod-mod/i)*dev[mod%i]%mod;
    jie[0]=1;devjie[0]=1;
    for(int i=1;i<10005;i++)
    {
        jie[i]=jie[i-1]*i%mod;
        devjie[i]=devjie[i-1]*dev[i]%mod;
    }
    int n,k;
    cin>>n>>k;
    ll ans=0;
    scanf("%s",s);
    {
        int num=0;
        for(int i=0;s[i];i++)if(s[i]=='1')num++;
        if(num<k)
        {
            cout<<1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        int n0=0,n1=0;
        int j;
        for(j=i;j<n;j++)
        {
            if(s[j]=='0')n0++;else n1++;
            if(n1>k)
            {
                j--;
                n1--;
                break;
            }//cout<<"???"<<j<<" "<<n0<<" "<<n1<<" "<<k<<endl;
        }//cout<<"<<"<<i<<" "<<n0<<" "<<n1<<endl;
        if(s[i]=='0')n1--;
        else n0--;//cout<<C(n0+n1,n0)<<endl;
        ans+=C(n0+n1,n0);
    }
    ans++;
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}