#include <cstdio>
#include <cstring>

using namespace std;

const int X=10002, MOD=1000000007;

int dp[2][50100];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, j, x, u=1, sol=0;
    scanf("%d", &n);
    for(i=1, u=1;i<=n;i++, u^=1)
    {
        scanf("%d", &x);
        memset(dp[u], 0, sizeof(dp[u]));
        dp[u][x+X]++;
        dp[u][-x+X]++;
        for(j=-10000;j+x<=10000;j++)
        {
            dp[u][j+x+X]=(dp[u][j+x+X]+dp[u^1][j+X])%MOD;
        }
        for(j=10000;j-x>=-10000;j--)
        {
            dp[u][j-x+X]=(dp[u][j-x+X]+dp[u^1][j+X])%MOD;
        }
        sol=(sol+dp[u][X])%MOD;
    }
    printf("%d", sol);
}