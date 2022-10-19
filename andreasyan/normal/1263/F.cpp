#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2003;

int n;
int nn[2];
vector<int> a[2][N];
int u[2][N];

vector<pair<int, int> > v[N];

int q[2][N];
int l[2][N], r[2][N];
void dfs(int ii, int x)
{
    q[ii][x] = 1;
    if (u[ii][x])
    {
        l[ii][x] = r[ii][x] = u[ii][x];
    }
    else
    {
        l[ii][x] = N;
        r[ii][x] = 0;
    }
    for (int i = 0; i < a[ii][x].size(); ++i)
    {
        int h = a[ii][x][i];
        dfs(ii, h);
        q[ii][x] += q[ii][h];
        l[ii][x] = min(l[ii][x], l[ii][h]);
        r[ii][x] = max(r[ii][x], r[ii][h]);
    }
    if (x != 1)
        v[r[ii][x]].push_back(m_p(l[ii][x], q[ii][x]));
}

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return max(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int dp[N];
int main()
{
    scanf("%d", &n);
    for (int ii = 0; ii < 2; ++ii)
    {
        scanf("%d", &nn[ii]);
        for (int x = 2; x <= nn[ii]; ++x)
        {
            int p;
            scanf("%d", &p);
            a[ii][p].push_back(x);
        }
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            u[ii][x] = i;
        }
    }
    for (int ii = 0; ii < 2; ++ii)
    {
        dfs(ii, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            dp[i] = max(dp[i], qry(1, n, 1, v[i][j].first - 1, 1) + v[i][j].second);
        }
        ubd(1, n, i, dp[i], 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}