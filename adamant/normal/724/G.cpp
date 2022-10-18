#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;
vector<pair<int, int>> g[maxn];
vector<pair<int, int>> G[maxn];
int xr[maxn], used[maxn];

vector<int> basis;

void add(int x)
{
    for(auto it: basis)
        if((x ^ it) < x)
            x ^= it;
    if(x)
        basis.push_back(x);
}

void dfs(int v)
{
    used[v] = 1;
    for(auto it: g[v])
    {
        int u = it.first;
        int c = it.second;
        if(used[u] == 1)
        {
            add(xr[v] ^ xr[u] ^ c);
        }
        else if(used[u] == 0)
        {
            xr[u] = xr[v] ^ c;
            G[v].push_back({u, c});
            dfs(u);
        }
    }
}

int sz[maxn];
void tree_dfs(int v, vector<int> &st)
{
    sz[v] = 1;
    st.push_back(v);
    for(auto it: G[v])
    {
        int u = it.first;
        tree_dfs(u, st);
        sz[v] += sz[u];
    }
}

int bpow(int x, int n)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    int t = bpow(x, n / 2);
    if(n % 2 == 1)
        return t * t % mod * x % mod;
    else
        return t * t % mod;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        g[u - 1].push_back({v - 1, t});
        g[v - 1].push_back({u - 1, t});
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(used[i])
            continue;
        basis.clear();
        dfs(i);
        int mask = 0;
        for(auto it: basis)
            mask |= it;
        vector<int> st;
        tree_dfs(i, st);
        int m = st.size();
        ans += m * (m - 1) / 2 % mod * (mask % mod) % mod * bpow(2, basis.size() - 1) % mod;
        ans %= mod;
        int cnt[62];
        memset(cnt, 0, sizeof(cnt));
        for(auto it: st)
            for(int i = 0; i < 62; i++)
                cnt[i] += ((xr[it] & (~mask)) >> i) & 1;
        for(int i = 0; i < 62; i++)
            ans += cnt[i] * (m - cnt[i]) % mod * bpow(2, i) % mod * bpow(2, basis.size()) % mod;
        ans %= mod;

    }
    cout << ans << "\n";
    return 0;
}