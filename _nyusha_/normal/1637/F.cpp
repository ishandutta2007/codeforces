#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2e5 + 5;
int h[maxn];
int dp[maxn];
vector < int > g[maxn];
ll ans = 0;
multiset < int > Q;

void dfs(int v, int p) {
    dp[v] = h[v];
    for (auto u : g[v]) {
        if (u != p) dfs(u, v), dp[v] = max(dp[v], dp[u]);
    }
}

void solve(int v, int p, int oth) {
    int mx1 = -maxn, cnt = 0, mx2 = -maxn;
    multiset < int > Q = {h[v]};
    for (auto u : g[v]) if (u != p) Q.insert(dp[u]);
    int child = 0;
    for (auto u : g[v]) {
        if (u != p) {
            child++;
            if (dp[u] >= h[v]) cnt++;
            else {
                if (dp[u] > mx1) mx2 = mx1, mx1 = dp[u];
                else if (dp[u] > mx2) mx2 = dp[u];
            }
        }
    }
    if (child == 0) {
        if (oth < h[v]) ans += 2 * h[v] - oth;
        else ans += h[v];
        return;
    }
    if (cnt == 1) {
        if (oth < h[v]) ans += min(h[v] - oth, h[v] - mx1);
    }
    else if (cnt == 0) {
        ans += h[v] - mx1;
        if (oth < h[v]) {
            ans += min(h[v] - oth, h[v] - mx2);
        }
    }
    for (auto u : g[v]) {
        if (u == p) continue;
        Q.erase(Q.find(dp[u]));
        solve(u, v, max(oth, (*Q.rbegin())));
        Q.insert(dp[u]);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    if (n == 2) {
        cout << 2 * max(h[1], h[2]);
        exit(0);
    }
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int node = 1;
    for (int i = 1; i < n; ++i) {
        if ((int)g[i].size() > 1) node = i;
    }
    dfs(node, 0);
    solve(node, 0, -maxn);
    cout << ans;
    return 0;
}