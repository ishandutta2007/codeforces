#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int a[100005];
int dp[100005][320];
int dp2[100005][320];
int solve(int i,int j)
{
    if(i==0)return 0;
    if(j<320)return dp[i][j];
    int k=a[i]/j;
    if(a[i]%j)k++;
    return dp2[i][k];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<320;j++)
            {
                int k=a[i]/j;
                if(a[i]%j)k++;
                int d;
                d=a[i]/k;
                dp[i][j]=solve(i-1,d)+(k-1ll)*i%mod;
                dp[i][j]%=mod;
            }
            for(int j=1;j<320;j++)
            {
                if(j>a[i])continue;
                int k=j;
                int d;
                d=a[i]/k;
                dp2[i][j]=solve(i-1,d)+(k-1ll)*i%mod;
                dp2[i][j]%=mod;
            }
        }
        ll ans=0;
        for(int i=n;i>=2;i--)
        {
            ans+=solve(i-1,a[i]);
        }
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}