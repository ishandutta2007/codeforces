#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
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
    }
    par[a] = b;
    return true;
}

int fin[maxn];
vector<pair<int, int>> g[maxn];
vector<pair<int, int>> up[maxn];

void dfs1(int v = 0, int p = 0) {
    if(fin[v]) {
        up[v] = {{0, v}};
    }
    for(auto it: g[v]) {
        int u = it.first;
        int c = it.second;
        if(u != p) {
            dfs1(u, v);
            if(up[u].size()) {
                up[v].push_back({max(up[u].back().first, c), u});
                sort(all(up[v]));
                while(up[v].size() > 2) {
                    up[v].erase(begin(up[v]));
                }
            }
        }
    }
}

void dfs2(int v = 0, int p = 0) {
    for(auto it: g[v]) {
        int u = it.first;
        int c = it.second;
        if(u != p) {
            for(auto it: up[v]) {
                if(it.second != u) {
                    up[u].push_back({max(it.first, c), v});
                }
            }
            sort(all(up[u]));
            while(up[u].size() > 2) {
                up[u].erase(begin(up[u]));
            }
            dfs2(u, v);
        }
    }
}

signed main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    int n, m, k;
    cin >> n >> m >> k;
    int x[k];
    for(int i = 0; i < k; i++) {
        cin >> x[i];
        x[i]--;
        fin[x[i]] = 1;
    }
    int u[m], v[m], w[m];
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }
    int p[m];
    iota(p, p + m, 0);
    sort(p, p + m, [&](int a, int b) {return w[a] < w[b];});
    for(int i = 0; i < m; i++) {
        if(uni(u[p[i]], v[p[i]])) {
            g[u[p[i]]].push_back({v[p[i]], w[p[i]]});
            g[v[p[i]]].push_back({u[p[i]], w[p[i]]});
            //cout << "! " << u[p[i]] << ' ' << v[p[i]] << ' ' << w[p[i]] << endl;
        }
    }
    dfs1();
    dfs2();
    for(int i = 0; i < k; i++) {
        cout << up[x[i]].back().first << ' ';
    }
    return 0;
}