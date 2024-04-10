#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;
const long long INF = 2000006000000009;

int n, m;
int b[N];
vector<pair<int, int> > a[N];
int s;

bool mos[N];

int ti, tin[N], fup[N];
int c[N];
void dfs0(int x, int p)
{
    c[x] = 1;
    fup[x] = tin[x] = ++ti;
    if (x == 4)
        cout << "";
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (c[h])
            fup[x] = min(fup[x], tin[h]);
        else
        {
            dfs0(h, x);
            if (fup[h] > tin[x])
                mos[a[x][i].second] = true;
            fup[x] = min(fup[x], fup[h]);
        }
    }
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (!mos[a[x][i].second] && !c[h])
            dfs1(h);
    }
}

long long sum[N];
vector<int> g[N];

int qq[N];

long long dp[N][2];
void dfs(int x, int p)
{
    sort(g[x].begin(), g[x].end());
    dp[x][0] = sum[x];
    dp[x][1] = -INF;
    long long sumv = 0;
    bool z = false;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (i && g[x][i] == g[x][i - 1])
            continue;
        dfs(h, x);
        if (dp[h][1] >= 0)
        {
            sumv += dp[h][1];
            z = true;
        }
    }
    if (z || qq[x] > 1)
        dp[x][1] = sum[x] + sumv;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (i && g[x][i] == g[x][i - 1])
            continue;
        if (dp[h][1] >= 0)
        {
            sumv -= dp[h][1];
        }
        dp[x][0] = max(dp[x][0], sum[x] + sumv + dp[h][0]);
        if (dp[h][1] >= 0)
        {
            sumv += dp[h][1];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(m_p(y, i));
        a[y].push_back(m_p(x, i));
    }
    scanf("%d", &s);
    dfs0(1, -1);
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs1(i);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i].first;
            if (c[x] != c[y])
            {
                g[c[x]].push_back(c[y]);
                g[c[y]].push_back(c[x]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sum[c[i]] += b[i];
        qq[c[i]]++;
    }
    dfs(c[s], -1);
    cout << max(dp[c[s]][0], dp[c[s]][1]) << endl;
    return 0;
}