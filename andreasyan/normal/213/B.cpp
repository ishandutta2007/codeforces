#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 102, M = 1000000007;

int n;
int a[10];

int c[N][N];
int dp[10][N][2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 10; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
    for (int k = a[0]; k <= n; ++k)
    {
        if (k == 0)
            dp[0][k][1] = 1;
        else
            dp[0][k][0] = 1;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int k = 0; k <= n; ++k)
        {
            for (int q = a[i + 1]; q <= (n - k); ++q)
            {
                if (k - 1 >= 0)
                    dp[i + 1][k + q][0] = (dp[i + 1][k + q][0] + dp[i][k][0] * 1LL * c[q + k - 1][k - 1]) % M;
                if (q + k - 1 >= 0)
                    dp[i + 1][k + q][1] = (dp[i + 1][k + q][1] + dp[i][k][0] * 1LL * c[q + k - 1][k]) % M;
                dp[i + 1][k + q][1] = (dp[i + 1][k + q][1] + dp[i][k][1] * 1LL * c[q + k][k]) % M;
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= n; ++k)
        ans = (ans + dp[9][k][1]) % M;
    printf("%d\n", ans);
    return 0;
}