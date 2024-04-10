#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, qq;
vector<int> a[N];

int tin[N], tout[N], ti;
const int m = 18;
int p[N][m];

int d[N];

int q[N];
ll dp[N];
void dfs(int x, int p0)
{
    tin[x] = ++ti;
    d[x] = d[p0] + 1;
    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p0)
            continue;
        dfs(h, x);
        q[x] += q[h];
        dp[x] += dp[h];
        dp[x] += q[h];
    }
    tout[x] = ti;
}

ll dpp[N];
void dfs1(int x, int p0)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p0)
            continue;
        dpp[h] = dp[x] - dp[h] - q[h];
        dpp[h] += dpp[x] + (n - q[x]);
        dfs1(h, x);
    }
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

int go(int x, int y)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return x;
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    dfs1(1, 1);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int z = lca(x, y);
        if (z == x)
            swap(x, y);
        ll ans = 0;
        if (z == y)
        {
            int xx = go(x, y);
            ans += (q[x] * 1LL * (n - q[xx]) * (d[x] + d[y] - 2 * d[z] + 1));
            ans += (dp[x] * 1LL * (n - q[xx]) + (dp[y] - dp[xx] - q[xx] + dpp[y] + (n - q[y])) * 1LL * q[x]);
            printf("%.9f\n", (double)ans / (q[x] * 1LL * (n - q[xx])));
            continue;
        }
        ans += (q[x] * 1LL * q[y] * (d[x] + d[y] - 2 * d[z] + 1));
        ans += (dp[x] * 1LL * q[y] + dp[y] * 1LL * q[x]);
        printf("%.9f\n", (double)ans / (q[x] * 1LL * q[y]));
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}