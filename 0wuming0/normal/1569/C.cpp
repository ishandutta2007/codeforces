#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll jie[200005];
ll dev[200005];
ll devjie[200005];
ll C(ll n,ll m)
{
    return jie[n]*devjie[m]%mod*devjie[n-m]%mod;
}
int main()
{
    dev[1]=1;jie[0]=devjie[0]=1;
    for(int i=2;i<200005;i++)dev[i]=(mod-mod/i)*dev[mod%i]%mod;
    for(int i=1;i<200005;i++)
    {
        jie[i]=jie[i-1]*i%mod;
        devjie[i]=devjie[i-1]*dev[i]%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a;
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(mp.find(a)==mp.end())
            {
                mp[a]=1;
            }
            else mp[a]++;
        }
        if(mp.size()==1)printf("%lld\n",jie[n]);
        else
        {
            auto it=mp.end();
            it--;int a=it->second;int s1=it->first;
            it--;int b=it->second;int s2=it->first;
            if(a>1)printf("%lld\n",jie[n]);
            else if(s1!=s2+1)printf("0\n");
            else //printf("%lld\n",jie[n-a-b]*C(n,a+b)%mod*jie[a]%mod*jie[b]%mod);
            printf("%lld\n",jie[n-a-b]*C(n,a+b)%mod*jie[a+b-1]%mod*(b)%mod);
        }
    }
    return 0;
}