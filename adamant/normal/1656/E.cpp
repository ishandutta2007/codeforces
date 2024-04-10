#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

const int maxn = 1e5 + 42;
vector<int> g[maxn];
int b[maxn], a[maxn];

void dfs(int v = 0, int p = 0, int h = 1) {
    b[v] = h;
    a[v] = b[v] * g[v].size();
    for(auto u: g[v]) {
        if(u != p) {
            dfs(u, v, -h);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        g[i].clear();
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}