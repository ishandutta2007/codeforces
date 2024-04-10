#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n, m, q;
vector<int> a[N];

int p[N];
int d[N];
int maxu[N];
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

bool c[N];
int dn[N];
void dfs(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        dn[x] = max(dn[x], dn[h] + 1);
    }
}

void dfs1(int x, int p, int dp)
{
    d[fi(x)] = min(d[fi(x)], max(dp + 1, dn[x]));
    int max1 = -1;
    int max2 = -1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            if (dp >= max1)
            {
                max2 = max1;
                max1 = dp;
            }
            else if (dp >= max2)
                max2 = dp;
            continue;
        }
        if (dn[h] >= max1)
        {
            max2 = max1;
            max1 = dn[h];
        }
        else if (dn[h] >= max2)
            max2 = dn[h];
    }
    maxu[fi(x)] = max(maxu[fi(x)], max1 + max2 + 2);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (dn[h] == max1)
            dfs1(h, x, max2 + 1);
        else
            dfs1(h, x, max1 + 1);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        d[i] = N;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        kpc(x, y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            dfs(i, i);
            dfs1(i, i, -1);
        }
    }
    while (q--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", maxu[fi(x)]);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x = fi(x);
            y = fi(y);
            if (x == y)
                continue;
            p[x] = y;
            maxu[y] = max(max(maxu[y], maxu[x]), d[x] + d[y] + 1);
            if (d[x] == d[y])
                ++d[y];
            else
                d[y] = max(d[x], d[y]);
        }
    }
    return 0;
}