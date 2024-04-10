#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 402;

int n, m;
char s[N], t[N];

int dp[N][N];

bool solv()
{
    scanf(" %s", s);
    scanf(" %s", t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 0; i <= m; ++i)
    {
        memset(dp, 0, sizeof dp);
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= i; ++k)
            {
                dp[j][k] = -1;
            }
        }
        dp[0][0] = 0;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k <= i; ++k)
            {
                if (dp[j][k] == -1)
                    continue;
                dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
                if (s[j] == t[k])
                    dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k]);
                if (s[j] == t[i + dp[j][k]])
                    dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + 1);
            }
        }
        if (dp[n][i] == m - i)
            return true;
    }
    return false;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}