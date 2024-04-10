#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

long long t[N * 4];

void ubd(int tl, int tr, int l, int r, long long y, int pos)
{
    if (r < l)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

long long qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return t[pos] + qry(tl, m, x, pos * 2);
    else
        return t[pos] + qry(m + 1, tr, x, pos * 2 + 1);
}

int n;
vector<int> a[N];

int m;
vector<pair<int, int> > q[N];

int d[N];

void dfs1(int x, int p)
{
    d[x] = d[p] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
    }
}

long long ans[N];
void dfs(int x, int p)
{
    for (int i = 0; i < q[x].size(); ++i)
    {
        ubd(0, n + 5, d[x], min(n + 1, d[x] + q[x][i].first), q[x][i].second, 1);
    }
    ans[x] = qry(0, n + 5, d[x], 1);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    for (int i = 0; i < q[x].size(); ++i)
    {
        ubd(0, n + 5, d[x], min(n + 1, d[x] + q[x][i].first), -q[x][i].second, 1);
    }
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
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int x, d, y;
        scanf("%d%d%d", &x, &d, &y);
        q[x].push_back(m_p(d, y));
    }
    dfs1(1, 1);
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}