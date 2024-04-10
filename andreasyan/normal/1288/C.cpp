#include <bits/stdc++.h>
using namespace std;
const int N = 1003, MM = 22, M = 1000000007;

int n, m;

int dp[MM][N];
int p[MM][N];

int main()
{
    scanf("%d%d", &n, &m);
    m *= 2;
    dp[0][0] = 1;
    for (int j = 0; j <= n; ++j)
        p[0][j] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = p[i - 1][j];
        }
        for (int j = 1; j <= n; ++j)
        {
            p[i][j] = (p[i][j - 1] + dp[i][j]) % M;
        }
    }
    printf("%d\n", p[m][n]);
    return 0;
}