#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()

const int maxn = 3009;
vector<int> g[maxn];
int n;
int dp[maxn][maxn];
int sz[maxn];
int pr[maxn];

void find_sz(int v, int p)
{
    pr[v] = p;
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to == p)
            continue;
        find_sz(to, v);
        sz[v] += sz[to];
    }
}

void dfs(int v, int u)
{
    dp[v][pr[u]] = max(dp[v][u], dp[pr[v]][pr[u]]) + sz[v] * (n - sz[u]);
    dp[pr[u]][v] = dp[v][pr[u]];
    for (int to : g[v])
    {
        if (to == pr[v])
            continue;
        dfs(to, u);
    }
}

void update(int v, int p)
{
    for (int to : g[v])
    {
        if (to != p)
            update(to, v);
    }
    if (p != -1)
    {
        for (int to : g[v])
        {
            if (to != p)
                dfs(to, v);
        }
    }
}

int get(int v, int u)
{
    if (v == u)
        return 0;
    if (dp[v][u] == -1)
        dp[v][u] = max(get(pr[v], u), get(v, pr[u])) + sz[u] * sz[v];
    return dp[v][u];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
            dp[i][e] = -1;
    }
    find_sz(0, -1);
    for (int v = 0; v < n; v++)
    {
        for (int to : g[v])
        {
            if (to != pr[v])
            {
                dp[v][to] = sz[to] * (n - sz[to]);
                dp[to][v] = dp[v][to];
            }
        }
    }
    update(0, -1);
    int ans = 0;
    for (int v = 0; v < n; v++)
    {
        for (int u = 0; u < n; u++)
            ans = max(ans, get(v, u));
    }
    cout << ans;
}