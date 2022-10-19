#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define all(v) (v).begin(),(v).end()

vector<vector<pair<int, int>>> g;
vector<int> used;
bool bad;

void dfs(int v, int cur) {
    used[v] = cur;
    for (auto [u, c] : g[v]) {
        int cur2;
        if (c == 0)
            cur2 = cur;
        else
            cur2 = 3 - cur;
        if (!used[u]) {
            dfs(u, cur2);
            continue;
        }
        if (used[u] != cur2) {
            bad = 1;
            return;
        }
    } 
}

void solve() {
    bad = false;
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    vector<array<int, 3>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int v;
        cin >> v;
        edges[i] = {a, b, v};
        if (v != -1) {
            v = __builtin_popcount(v) % 2;
            g[a].push_back({b, v});
            g[b].push_back({a, v}); 
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        a--;
        b--;
        g[a].push_back({b, v});
        g[b].push_back({a, v});
    }
    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, 1);
        } 
    }
    for (int i = 0; i < n; i++) {
        used[i]--;
    }
    if (bad) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (auto [a, b, c] : edges) {
        if (c == -1) {
           c = used[a] ^ used[b];
        }
       cout << a + 1 << " " << b + 1 << " " << c << '\n'; 
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}