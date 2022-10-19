#include <bits/stdc++.h>
using namespace std;
const int N = 88, M = 200005, INF = 1000000009;
struct ban
{
    int x, s;
};
bool operator<(const ban& a, const ban& b)
{
    return (a.x - a.s) < (b.x - b.s);
}

int n, m;
ban a[N];

int dp[N][M];
int s[N][M];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].s);
    sort(a + 1, a + n + 1);
    int mm = m + m;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j <= mm; ++j)
            dp[i][j] = INF;
    }
    s[0][mm] = dp[0][mm];
    for (int j = mm - 1; j >= 0; --j)
        s[0][j] = min(dp[0][j], s[0][j + 1]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= mm; ++j)
            dp[i][j] = s[i - 1][j];
        for (int j = 0; j <= mm; ++j)
        {
            if (a[i].x + a[i].s + j <= mm)
            {
                if (a[i].x - a[i].s - j - 1 >= 0)
                    dp[i][a[i].x + a[i].s + j] = min(dp[i][a[i].x + a[i].s + j],
                                                     j + s[i - 1][a[i].x - a[i].s - j - 1]);
                else
                    dp[i][a[i].x + a[i].s + j] = min(dp[i][a[i].x + a[i].s + j],
                                                     j);
            }
        }
        s[i][mm] = dp[i][mm];
        for (int j = mm - 1; j >= 0; --j)
            s[i][j] = min(dp[i][j], s[i][j + 1]);
    }
    cout << s[n][m] << endl;
    return 0;
}