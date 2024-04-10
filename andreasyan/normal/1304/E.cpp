#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
vector<int> a[N];

int tin[N], tout[N], ti;
const int m = 19;
int p[N][m];
int d[N];
void dfs(int x, int pp)
{
    tin[x] = ++ti;
    d[x] = d[pp] + 1;
    p[x][0] = pp;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == pp)
            continue;
        dfs(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int dist(int x, int y)
{
    int z = lca(x, y);
    return d[x] + d[y] - 2 * d[z];
}

bool stg()
{
    int a, b, x, y, k;
    scanf("%d%d%d%d%d", &a, &b, &x, &y, &k);
    int kk = k;
    kk -= dist(x, y);
    if (kk >= 0 && kk % 2 == 0)
        return true;
    kk = k;
    kk -= dist(x, a);
    kk--;
    kk -= dist(b, y);
    if (kk >= 0 && kk % 2 == 0)
        return true;
    kk = k;
    kk -= dist(x, b);
    kk--;
    kk -= dist(a, y);
    if (kk >= 0 && kk % 2 == 0)
        return true;
    return false;
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
    dfs(1, 1);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        if (stg())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}