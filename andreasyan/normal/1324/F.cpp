#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int g[N];
vector<int> a[N];

int d[N];

void dfs(int x, int p)
{
    d[x] = g[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        if (d[h] > 0)
            d[x] += d[h];
    }
}

int ans[N];

void dfs1(int x, int p, int dp)
{
    ans[x] = d[x];
    if (dp > 0)
        ans[x] += dp;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (d[h] > 0)
            ans[x] -= d[h];
        dfs1(h, x, ans[x]);
        if (d[h] > 0)
            ans[x] += d[h];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &g[i]);
        if (g[i] == 0)
            --g[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    dfs1(1, 1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}