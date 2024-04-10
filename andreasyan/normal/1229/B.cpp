#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 1000000007;
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
long long t[N];
vector<int> a[N];

const int m = 20;

int d[N];
int p[N][m];
long long g[N][m];
void dfs(int x, int pp)
{
    d[x] = d[pp] + 1;
    p[x][0] = pp;
    g[x][0] = gcd(t[x], t[pp]);
    for (int i = 1; i < m; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
        g[x][i] = gcd(g[x][i - 1], g[p[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == pp)
            continue;
        dfs(h, x);
    }
}

int go(int x, long long y)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if (gcd(y, g[x][i]) == y)
        {
            x = p[x][i];
        }
    }
    return x;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &t[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    long long ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        long long y = t[x];
        int u = x;
        while (1)
        {
            int uu = go(u, y);
            ans = (ans + (d[u] - d[uu] + 1) * y) % M;
            if (uu == 1)
                break;
            y = gcd(y, g[uu][0]);
            u = p[uu][0];
        }
    }
    cout << ans << endl;
    return 0;
}