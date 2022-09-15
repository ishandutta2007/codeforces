#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 5000;
int dp[MAXN+1][MAXN+1];
void fillDP()
{
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i=3; i<=MAXN; ++i)
        dp[0][i] = 1;
    for(int k=0; k<=MAXN; ++k)
    {
        for(int n=0; n<=2*k && n<=MAXN; ++n)
            dp[k][n] = 0;
        int sum = 1;
        for(int n=2*k+1; n<=MAXN; ++n)
        {
            if(k==0)
                dp[k][n] = 1;
            else
            {
                dp[k][n] = (dp[k][n-1] + sum)%MOD;
                sum += dp[k-1][n-1];
                sum %= MOD;
            }
        }
    }
}
int N, M, K;
int main()
{
    fillDP();
    scanf("%d%d%d", &N, &M, &K);
    printf("%lld\n", 1LL * dp[K][N] * dp[K][M] % MOD);
}