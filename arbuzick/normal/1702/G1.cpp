#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5, l = 20;

vector<int> g[maxn];

int tin[maxn], tout[maxn];

int t = 0;

int go[l][maxn];

void dfs(int v, int pr) {
    tin[v] = ++t;
    go[0][v] = pr;
    for (auto u : g[v]) {
        if (u != pr) {
            dfs(u, v);
        }
    }
    tout[v] = ++t;
}

int lca(int a, int b) {
    if (tin[a] <= tin[b] && tout[b] <= tout[a]) {
        return a;
    }
    if (tin[b] <= tin[a] && tout[a] <= tout[b]) {
        return b;
    }
    int v = a;
    for (int i = l - 1; i >= 0; --i) {
        if (!(tin[go[i][v]] <= tin[b] && tout[b] <= tout[go[i][v]])) {
            v = go[i][v];
        }
    }
    return go[0][v];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    for (int i = 1; i < l; ++i) {
        for (int j = 0; j < n; ++j) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<pair<int, int>> v(k);
        for (int i = 0; i < k; ++i) {
            cin >> v[i].second;
            v[i].second--;
            v[i].first = tin[v[i].second];
        }
        sort(v.begin(), v.end());
        bool ch = true, fl = false;
        for (int i = 1; i < (int)v.size(); ++i) {
            if (!(tin[v[i - 1].second] <= tin[v[i].second] && tout[v[i].second] <= tout[v[i - 1].second])) {
                if (fl) {
                    ch = false;
                } else {
                    for (int j = 1; j < i; ++j) {
                        if (tin[v[j].second] <= tin[v[i].second] && tout[v[i].second] <= tout[v[j].second]) {
                            ch = false;
                        }
                    }
                    if (i != 1) {
                        int c = lca(v[1].second, v[i].second);
                        if (!(tin[c] <= tin[v[0].second] && tout[v[0].second] <= tout[c])) {
                            ch = false;
                        }
                    }
                    fl = true;
                }
            }
        }
        if (ch) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}