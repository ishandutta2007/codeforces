#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 3003;

int n;
vector<int> a[N];
pair<int, int> b[N];

int d[N][N];

void dfs(int x, int p, int xx)
{
    if (x != p)
    {
        d[xx][x] = d[xx][p] + 1;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x, xx);
    }
}

int q[N];
vector<int> qq[N];
void dfs1(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        q[x] += q[h];
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            qq[x].push_back(n - q[x]);
            continue;
        }
        qq[x].push_back(q[h]);
    }
}

long long dp[N][N];
bool c[N][N];

long long rec(int x, int y)
{
    if (c[x][y])
        return dp[x][y];
    c[x][y] = true;
    int qx;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (d[x][y] > d[h][y])
            qx = n - qq[x][i];
    }
    int qy;
    for (int i = 0; i < a[y].size(); ++i)
    {
        int h = a[y][i];
        if (d[y][x] > d[h][x])
            qy = n - qq[y][i];
    }
    dp[x][y] = qx * qy;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (d[x][y] > d[h][y])
            continue;
        dp[x][y] = max(dp[x][y], rec(h, y) + qx * qy);
    }
    for (int i = 0; i < a[y].size(); ++i)
    {
        int h = a[y][i];
        if (d[y][x] > d[h][x])
            continue;
        dp[x][y] = max(dp[x][y], rec(x, h) + qx * qy);
    }
    return dp[x][y];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
        b[i] = m_p(x, y);
    }
    for (int i = 1; i <= n; ++i)
    {
        dfs(i, i, i);
    }
    dfs1(1, 1);
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        ans = max(ans, rec(b[i].first, b[i].second));
    }
    printf("%lld\n", ans);
    return 0;
}