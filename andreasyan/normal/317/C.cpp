#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 302;

int n, v, m;
int a[N], b[N];
vector<int> g[N];

vector<pair<pair<int, int>, int> > ans;
void ave(int x, int y, int z)
{
    ans.push_back(m_p(m_p(x, y), z));
    a[x] -= z;
    a[y] += z;
}

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

long long suma[N], sumb[N];

bool c[N];

void dfs1(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        dfs1(h, x);
        if (a[x] + a[h] <= v)
            ave(h, x, a[h]);
        else
            ave(h, x, (v - a[x]));
    }
}

void dfs2(int x, int p)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        dfs2(h, x);
        if (a[h] + a[x] <= v)
            ave(x, h, a[x]);
        else
            ave(x, h, (v - a[h]));
    }
}

int main()
{
    scanf("%d%d%d", &n, &v, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (fi(x) != fi(y))
        {
            g[x].push_back(y);
            g[y].push_back(x);
            kpc(x, y);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        suma[fi(i)] += a[i];
        sumb[fi(i)] += b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (suma[i] != sumb[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    while (1)
    {
        for (int x = 1; x <= n; ++x)
        {
            if (c[x])
                continue;
            int q = 0;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                if (!c[h])
                    ++q;
            }
            if (q == 0)
            {
                c[x] = true;
                continue;
            }
            if (q == 1)
            {
                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i];
                    if (c[h])
                        continue;
                    if (a[x] < b[x])
                    {
                        dfs1(h, x);
                        assert(a[h] >= (b[x] - a[x]));
                        ave(h, x, (b[x] - a[x]));
                    }
                    else
                    {
                        dfs2(h, x);
                        assert(a[h] + (a[x] - b[x]) <= v);
                        ave(x, h, (a[x] - b[x]));
                    }
                    c[x] = true;
                }
            }
        }
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if (!c[i])
            {
                z = false;
                break;
            }
        }
        if (z)
            break;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
    return 0;
}