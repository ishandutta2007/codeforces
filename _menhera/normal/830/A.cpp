#include<bits/stdc++.h>
using namespace std;
int n, k;
long long p;
long long a[10101];
long long b[10101];
long long dp[2020][1010]; //until key k, n person took it 
int main()
{
    scanf("%d%d%lld",&n,&k,&p);
    for(int i=1; i<=n; ++i)
        scanf("%lld", a+i);
    sort(a+1, a+n+1);
    for(int i=1; i<=k; ++i)
        scanf("%lld", b+i);
    sort(b+1, b+k+1);
    memset(dp, 0x3f, sizeof(dp));
    for(int i=0; i<=k; ++i)
        dp[i][0] = 0;
    
    for(int i=1; i<=k; ++i)
        for(int j=1; j<=n; ++j)
        {
            dp[i][j] = dp[i-1][j];
            dp[i][j] = min(dp[i][j], max(dp[i-1][j-1], abs(a[j]-b[i]) + abs(b[i]-p)));
        }
    printf("%lld\n", dp[k][n]);
    return 0;
}