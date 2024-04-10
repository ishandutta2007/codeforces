#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (6666)
#define MOD ((ll)1e9+7)

ll n,a,b,k,dp[2][N];

int main()
{
    cin>>n>>a>>b>>k;
    dp[0][a]=1;
    for(int i=1;i<=k;i++)
    {
        ll cnt=0;
        for(int j=1;j<b;j++)
            dp[i&1][j]=cnt,cnt+=dp[!(i&1)][j],dp[i&1][j]%=MOD,cnt%=MOD;
        cnt=0;  
        for(int j=n;j>b;j--)
            dp[(i&1)][j]=cnt,cnt+=dp[!(i&1)][j],dp[(i&1)][j]%=MOD,cnt%=MOD;
        dp[i&1][b]=0;   
        ll dp2[N]={};
        for(int j=b;j>=1;j--)
        {
            dp2[j-1]+=dp[!(i&1)][j],dp2[j-1]%=MOD;
            if(2*j-b>=1)dp2[2*j-b]-=dp[!(i&1)][j],dp2[2*j-b]%=MOD,dp2[2*j-b]+=MOD,dp2[2*j-b]%=MOD;
            dp2[j]+=((j==b)?0:dp2[j+1]),dp[(i&1)][j]+=dp2[j],dp2[j]%=MOD,dp[(i&1)][j]%=MOD;;
            
        }
                
        for(int j=b;j<=n;j++)
        {
            dp2[j+1]+=dp[!(i&1)][j],dp2[j+1]%=MOD;
            if(2*j-b<=n)dp2[2*j-b]-=dp[!(i&1)][j],dp2[2*j-b]%=MOD,dp2[2*j-b]+=MOD,dp2[2*j-b]%=MOD;
            dp2[j]+=((j==b)?0:dp2[j-1]),dp[(i&1)][j]+=dp2[j],dp2[j]%=MOD,dp[(i&1)][j]%=MOD;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=dp[k&1][i],ans%=MOD;
    cout<<ans;
    return 0;
}