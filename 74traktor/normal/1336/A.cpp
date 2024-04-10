#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
vector < int > g[maxn];
int sz[maxn], h[maxn], val[maxn];

void dfs(int v, int p) {
    sz[v] = 1, h[v] = h[p] + 1;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
    if (sz[v] == 1) val[v] = h[v];
    else {
        val[v] = h[v] * sz[v] - (h[v] + 1) * (sz[v] - 1);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, u, v, ans = 0;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[0] = -1;
    dfs(1, 0);
    sort(val + 1, val + n + 1);
    for (int i = n; i >= n - k + 1; i--) ans += val[i];
    cout << ans << '\n';
    return 0;
}