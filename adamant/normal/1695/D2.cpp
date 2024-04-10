#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;
const int inf = 1e16;

void solve() {
    int n;
    cin >> n;
    vector<set<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    int leafs = 0;
    set<int> pars;
    for(int v = 0; v < n; v++) {
        if(g[v].size() == 1) {
            int w = *begin(g[v]);
            while(g[w].size() == 2) {
                int u = -1;
                for(auto it: g[w]) {
                    if(it != v) {
                        u = it;
                    }
                }
                assert(u >= 0);
                g[u].erase(w);
                g[v].erase(w);
                g[v].insert(u);
                g[u].insert(v);
                w = *begin(g[v]);
            }
            leafs++;
            pars.insert(*begin(g[v]));
        }
    }
    int result = leafs - pars.size();
    if(result == 0 && n > 1) {
        result++;
    }
    cout << result << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}