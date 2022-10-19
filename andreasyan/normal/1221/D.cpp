#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const long long INF = 1000000009000000009;

int n;
int a[N], b[N];

long long dp[N][3];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    dp[1][0] = 0;
    dp[1][1] = b[1];
    dp[1][2] = b[1] * 2;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = INF;
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (a[i - 1] + j != a[i] + k)
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + b[i] * k);
            }
        }
    }
    printf("%lld\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}