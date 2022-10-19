#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005, INF = 1000000009;

int n;
int a[N];

pair<int, int> mer(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p(min(a.first, b.first), max(a.second, b.second));
}

pair<int, int> dp[N][1 << 3];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; ++i)
    {
        for (int x = 0; x < (1 << 3); ++x)
            dp[i][x] = m_p(INF, -INF);
    }
    dp[0][0] = m_p(0, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int x = 0; x < (1 << 3); ++x)
        {
            int y = 0;
            if (a[i - 1] == a[i])
            {
                y = x;
            }
            if (a[i - 1] == a[i] - 1)
            {
                y = (x >> 1);
            }
            if (a[i - 1] == a[i] - 2)
            {
                y = (x >> 2);
            }
            for (int j = 0; j < 3; ++j)
            {
                if ((y & (1 << j)))
                    dp[i][(y | (1 << j))] = mer(dp[i][(y | (1 << j))], dp[i - 1][x]);
                else
                    dp[i][(y | (1 << j))] = mer(dp[i][(y | (1 << j))], m_p(dp[i - 1][x].first + 1, dp[i - 1][x].second + 1));
            }
        }
    }
    pair<int, int> ans = m_p(INF, -INF);
    for (int x = 0; x < (1 << 3); ++x)
        ans = mer(ans, dp[n][x]);
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}