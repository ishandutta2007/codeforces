#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 500005;
const long long INF = 1000006000000009;

int n, q;
int p[N];
vector<pair<int, long long> > a[N];

long long d[N];
int tout[N];
void dfs0(int x)
{
    tout[x] = x;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        d[h] = d[x] + a[x][i].second;
        dfs0(h);
        tout[x] = max(tout[x], tout[h]);
    }
}

long long t[N * 4];
long long laz[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        if (a[tl].empty())
            t[pos] = d[tl];
        else
            t[pos] = INF;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}
void shi(int pos)
{
    t[pos * 2] += laz[pos];
    t[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}
void ubd(int tl, int tr, int l, int r, long long y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}
long long qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    shi(pos);
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return min(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long ans[N];
vector<pair<pair<int, int>, int> > v[N];

void dfs(int x)
{
    for (int i = 0; i < v[x].size(); ++i)
    {
        int l = v[x][i].first.first;
        int r = v[x][i].first.second;
        ans[v[x][i].second] = qry(1, n, l, r, 1);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        ubd(1, n, 1, h - 1, a[x][i].second, 1);
        ubd(1, n, h, tout[h], -a[x][i].second, 1);
        ubd(1, n, tout[h] + 1, n, a[x][i].second, 1);
        dfs(h);
        ubd(1, n, 1, h - 1, -a[x][i].second, 1);
        ubd(1, n, h, tout[h], a[x][i].second, 1);
        ubd(1, n, tout[h] + 1, n, -a[x][i].second, 1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for (int x = 2; x <= n; ++x)
    {
        int z;
        scanf("%d%d", &p[x], &z);
        a[p[x]].push_back(m_p(x, z));
    }
    for (int i = 0; i < q; ++i)
    {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        v[x].push_back(m_p(m_p(l, r), i));
    }
    dfs0(1);
    bil(1, n, 1);
    dfs(1);
    for (int i = 0; i < q; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}