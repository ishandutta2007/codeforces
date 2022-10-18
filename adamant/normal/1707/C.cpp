#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

int par[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

bool uni(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return false;
    } else {
        par[a] = b;
        return true;
    }
}

const int logn = 20;
int up[maxn][logn];

string main_sol(int n, vector<pair<int, int>> G) {
    memset(up, 0, sizeof up);
    iota(par, par + maxn, 0);
    int m = G.size();
    vector<int> g[n];
    int u[m], v[m];
    bool in_mst[m];
    for(int i = 0; i < m; i++) {
        tie(u[i], v[i]) = G[i];
        u[i]--, v[i]--;
        in_mst[i] = uni(u[i], v[i]);
        if(in_mst[i]) {
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
    }
    int in[n], out[n], h[n];
    int t = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        in[v] = t++;
        for(auto u: g[v]) {
            if(u != p) {
                h[u] = h[v] + 1;
                up[u][0] = v;
                for(int i = 1; i < logn; i++) {
                    up[u][i] = up[up[u][i - 1]][i - 1];
                }
                dfs(u, v);
            }
        }
        out[v] = t;
    };
    dfs(0, 0);
    auto is_par = [&](int a, int b) {
        return in[a] <= in[b] && out[b] <= out[a];
    };
    auto lca = [&](int a, int b) {
        if(is_par(a, b)) {
            return a;
        } else if(is_par(b, a)) {
            return b;
        } else {
            for(int i = logn - 1; i >= 0; i--) {
                if(!is_par(up[a][i], b)) {
                    a = up[a][i];
                }
            }
            return up[a][0];
        }
    };
    auto la = [&](int a, int th) {
        for(int i = logn - 1; i >= 0; i--) {
            if(h[up[a][i]] >= th) {
                a = up[a][i];
            }
        }
        return a;
    };
    vector<int> add(n);
    for(int i = 0; i < m; i++) {
        if(!in_mst[i]) {
            int U = u[i], V = v[i], W = lca(u[i], v[i]);
            if(U == W) {
                add[la(V, h[U] + 1)]++;
                add[V]--;
            } else if(V == W) {
                add[la(U, h[V] + 1)]++;
                add[U]--;
            } else {
                add[0]++;
                add[U]--;
                add[V]--;
            }
        }
    }
    function<void(int, int)> dfs_sum = [&](int v, int p) {
        for(auto u: g[v]) {
            if(u != p) {
                add[u] += add[v];
                dfs_sum(u, v);
            }
        }
    };
    dfs_sum(0, 0);
    string ans(n, '0');
    for(int i = 0; i < n; i++) {
        if(add[i] == 0) {
            ans[i] = '1';
        }
    }
    return ans;
}



void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> G(m);
    for(int i = 0; i < m; i++) {
        cin >> G[i].first >> G[i].second;
    }
    cout << main_sol(n, G) << "\n";
}
 
signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}