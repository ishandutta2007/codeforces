#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 3e5 + 42;

vector<pair<int, int>> g[maxn];
vector<pair<int, int>> up[maxn];
int w[maxn];


void dfs1(int v = 0, int p = 0) {
    up[v] = {{w[v], v}};
    for(auto it: g[v]) {
        int u = it.first;
        int c = it.second;
        if(u != p) {
            dfs1(u, v);
            if(up[u][0].first >= c) {
                up[v].push_back({w[v] + up[u][0].first - c, u});
                sort(all(up[v]), greater<pair<int, int>>());
                if(up[v].size() > 2) {
                    up[v].resize(2);
                }
            }
        }
    }
}

int dfs2(int v = 0, int p = 0) {
    int res = up[v][0].first;
    for(auto it: g[v]) {
        int u = it.first;
        int c = it.second;
        if(u != p) {
            for(auto jt: up[v]) {
                if(jt.second != u && jt.first >= c) {
                    up[u].push_back({w[u] + jt.first - c, v});
                    sort(all(up[u]), greater<pair<int, int>>());
                    if(up[u].size() > 2) {
                        up[u].resize(2);
                    }
                }
            }
            res = max(res, dfs2(u, v));
        }
    }
    return res;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    dfs1();
    cout << dfs2() << "\n";
    
    return 0;
}