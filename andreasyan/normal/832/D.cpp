#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, l;
vector<int> a[N];

int tin[N], tout[N], ti;

int p[N][20];

int d[N];
void dfs(int x, int pp)
{
    tin[x] = ti++;
    d[x] = d[pp] + 1;

    p[x][0] = pp;
    for (int i = 1; i <= l; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
    }

    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h, x);
    }
    tout[x] = ti++;
}
bool par(int x, int y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int lca(int x, int y)
{
    if (par(x, y))
        return x;
    if (par(y, x))
        return y;
    for (int i = l; i >= 0; --i)
    {
        if (!par(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int dis(int x, int y)
{
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

int qry(int u, int x, int y)
{
    if (par(u, x) && !par(u, y))
        return 0;
    if (!par(u, x) && par(u, y))
        return 0;
    if (par(u, x) && par(u, y))
        return dis(u, lca(x, y));
    if (par(x, u) && par(y, u))
        return min(dis(x, u), dis(y, u));
    if (par(lca(x, y), u))
        return min(dis(lca(y, u), u), dis(lca(x, u), u));
    else
        return dis(u, lca(x, y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for (int y = 2; y <= n; ++y)
    {
        int x;
        cin >> x;
        a[x].push_back(y);
    }
    while ((1 << l) <= n)
        ++l;
    dfs(1, 1);
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cout << max(max(qry(x, y, z), qry(y, x, z)), qry(z, x, y)) + 1 << endl;;
    }
    return 0;
}