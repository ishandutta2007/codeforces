#include<iostream>
using namespace std;

#define ll long long

const int N = 5002;

ll dp[N][N];
ll a[N];

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        a[i] += a[i-1];
    }
    for(int i=0;i<=n;++i)
        for(int j=0;j<=k;++j)
            dp[i][j] = -2e18;
    dp[0][0] = 0;
    for(int i=1;i<=n;++i)
    {
        dp[i][0] = 0;
        for(int j=1;j<=k;++j)
        {   
            dp[i][j] = dp[i-1][j];
            if(i>=m)
                dp[i][j] = max(dp[i][j],a[i]-a[i-m]+dp[i-m][j-1]);
        }
    }
    printf("%lld\n",dp[n][k]);
}