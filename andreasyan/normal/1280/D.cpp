#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 3003;

int n, m;
int g[N];
vector<int> a[N];

pair<int, long long> sum(const pair<int, long long>& a, const pair<int, long long>& b)
{
    return m_p(a.first + b.first, a.second + b.second);
}

pair<int, long long> sum1(const pair<int, long long>& a, const pair<int, long long>& b)
{
    return m_p(a.first + b.first + (b.second > 0), a.second);
}

int q[N];
pair<int, long long> dp[N][N];
pair<int, long long> ndp[N];
void dfs(int x, int p)
{
    q[x] = 1;
    dp[x][0] = m_p(0, g[x]);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        for (int j = 0; j <= q[x] + q[h]; ++j)
            ndp[j] = m_p(-N, 0);
        for (int j = 0; j <= q[x]; ++j)
        {
            for (int k = 0; k <= q[h]; ++k)
            {
                ndp[j + k] = max(ndp[j + k], sum(dp[x][j], dp[h][k]));
                ndp[j + k + 1] = max(ndp[j + k + 1], sum1(dp[x][j], dp[h][k]));
            }
        }
        q[x] += q[h];
        for (int j = 0; j <= q[x]; ++j)
            dp[x][j] = ndp[j];
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &g[i]);
        g[i] *= (-1);
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        g[i] += x;
    }
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
            dp[i][j] = m_p(-N, 0);
    }
    dfs(1, 1);
    int ans = dp[1][m - 1].first;
    if (dp[1][m - 1].second > 0)
        ++ans;
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}