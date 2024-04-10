#include"bits/stdc++.h"
using namespace std;
char *a[5000005];
#define ll long long
ll mod=998244353;
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
ll dp[300005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        a[i]=(char *)malloc(sizeof(char)*(m+4));
        scanf("%s",a[i]);
    }
    int num=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(a[i][j]=='o')num++;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)if(a[i][j]=='o')
        {
            int sum=0;
            while(j<m&&a[i][j]=='o')
            {
                j++;
                sum++;
            }
            dp[sum]++;
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)if(a[i][j]=='o')
        {
            int sum=0;
            while(i<n&&a[i][j]=='o')
            {
                i++;
                sum++;
            }
            dp[sum]++;
        }
    }
    for(int i=300000;i>=1;i--)
    {
        dp[i-1]+=dp[i];
        dp[i-1]%=mod;
    }
    for(int i=300000;i>=1;i--)
    {
        dp[i-1]+=dp[i];
        dp[i-1]%=mod;
    }
    ll save=1;
    //for(int i=2;i<=10;i++)printf("%lld%c",dp[i]," \n"[i==10]);
    for(int i=num;i>=2;i--)
    {
        if(i%2)ans-=dp[i]*save;
        else ans+=dp[i]*save;
        ans%=mod;
        save=save*2%mod;
    }
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
    {
        free(a[i]);
    }
    return 0;
}