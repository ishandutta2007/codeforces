#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = (1 << 17);
const int LOG_N = 20;
vector<int> g[MAX_N];
int n, q;
int tin[MAX_N];
int tout[MAX_N];
int timer;
int h[MAX_N];
int d[2 * MAX_N];
int anc[LOG_N][MAX_N];
int mod = 1000 * 1000 * 1000 + 7;
int dp[2][309];

void dfs(int v, int pr)
{
    if (pr != -1)
        h[v] = h[pr] + 1;
    if (pr != -1)
        anc[0][v] = pr;
    else
        anc[0][v] = v;
    for (int j = 1; j < LOG_N; j++)
        anc[j][v] = anc[j - 1][anc[j - 1][v]];
    tin[v] = timer;
    timer++;
    for (int to : g[v])
    {
        if (to != pr)
            dfs(to, v);
    }
    tout[v] = timer;
}

void add(int i, int l, int r, int left, int right, int x)
{
    if (l == left && r == right)
    {
        d[i] += x;
        return;
    }
    int m = (l + r) / 2;
    if (right <= m)
        add(i * 2, l, m, left, right, x);
    else if (left >= m)
        add(i * 2 + 1, m, r, left, right, x);
    else
    {
        add(i * 2, l, m, left, m, x);
        add(i * 2 + 1, m, r, m, right, x);
    }
}

int get(int i, int l, int r, int x, int cur)
{
    if (l == x && r == l + 1)
        return cur + d[i];
    cur += d[i];
    int m = (l + r) / 2;
    if (x < m)
        return get(i * 2, l, m, x, cur);
    return get(i * 2 + 1, m, r, x, cur);
}

int find_lca(int a, int b)
{
    for (int j = LOG_N - 1; j >= 0; j--)
    {
        int cur = anc[j][a];
        if (!(tin[cur] <= tin[b] && tout[b] <= tout[cur]))
            a = cur;
    }
    if (!(tin[a] <= tin[b] && tout[b] <= tout[a]))
        a = anc[0][a];
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    for (int j = 0; j < q; j++)
    {
        int k, m, r;
        cin >> k >> m >> r;
        r--;
        vector<pair<int, int> > a(k);
        for (int e = 0; e < k; e++)
        {
            cin >> a[e].second;
            a[e].second--;
            int lca = find_lca(a[e].second, r);
            a[e].first = h[a[e].second] + h[r] - 2 * h[lca];
        }
        sort(a.begin(), a.end());
        for (int i = 1; i <= m; i++)
            dp[0][i] = 0;
        dp[0][0] = 1;
        for (int u = 0; u < k; u++)
        {
            int v = a[u].second;
            int e = 1 - u % 2;
            int cnt = get(1, 0, MAX_N, tin[v], 0);
            for (int i = 0; i <= cnt; i++)
                dp[e][i] = 0;
            for (int i = cnt + 1; i <= m; i++)
            {
                dp[e][i] = (dp[1 - e][i - 1] + dp[1 - e][i] * (i - cnt)) % mod;
            }
            if (v == r)
                add(1, 0, MAX_N, 0, MAX_N, 1);
            else if (tin[v] <= tin[r] && tout[r] <= tout[v])
            {
                add(1, 0, MAX_N, 0, MAX_N, 1);
                for (int to : g[v])
                {
                    if (tin[to] <= tin[r] &&  tout[r] <= tout[to] && tin[to] > tin[v])
                    {
                        add(1, 0, MAX_N, tin[to], tout[to], -1);
                    }
                }
            }
            else
                add(1, 0, MAX_N, tin[v], tout[v], 1);
        }
        int ans = 0;
        for (int i = 0; i <= m; i++)
        {
            ans += dp[k % 2][i];
            if (ans >= mod)
                ans -= mod;
        }
        cout << ans << "\n";
        for (int u = 0; u < k; u++)
        {
            int v = a[u].second;
            if (v == r)
                add(1, 0, MAX_N, 0, MAX_N, -1);
            else if (tin[v] <= tin[r] &&  tout[r] <= tout[v])
            {
                add(1, 0, MAX_N, 0, MAX_N, -1);
                for (int to : g[v])
                {
                    if (tin[to] <= tin[r] &&  tout[r] <= tout[to] && tin[to] > tin[v])
                        add(1, 0, MAX_N, tin[to], tout[to], 1);
                }
            }
            else
                add(1, 0, MAX_N, tin[v], tout[v], -1);
        }
    }
}