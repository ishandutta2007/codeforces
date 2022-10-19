#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int x, d;
    ban(){}
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};

int n;
vector<ban> a[N];

int q[N];
void dfsq(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p)
            continue;
        dfsq(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p)
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

long long d[N];
void dfsd(int x, int p, int dp)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + dp;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p)
            continue;
        dfsd(h, x, a[x][i].d);
    }
}

long long solvmax()
{
    dfsq(1, 1);
    int c = dfsc(1, 1, 1);
    dfsd(c, c, 0);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += d[i];
    return ans;
}

long long dp[N];
bool z[N];

void dfs(int x, int p)
{
    int q = 1;
    dp[x] = 0;
    z[x] = false;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].x;
        if (h == p)
            continue;
        dfs(h, x);
        dp[x] += dp[h];
        if (!z[h])
        {
            ++q;
            dp[x] += a[x][i].d;
        }
    }
    if (q % 2 == 0)
        z[x] = true;
}

long long solvmin()
{
    dfs(1, 1);
    return dp[1];
}

void solv()
{
    scanf("%d", &n);
    n *= 2;
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(ban(y, z));
        a[y].push_back(ban(x, z));
    }
    printf("%lld %lld\n", solvmin(), solvmax());
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}