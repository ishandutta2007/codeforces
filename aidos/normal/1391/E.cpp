#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;

vector<int> g[maxn];
vector<int> L[maxn];
int n, m;
int u[maxn];
int p[maxn];
void dfs(int v, int lev) {
    L[lev].push_back(v);
    u[v] = 1;
    for(int to: g[v]) {
        if(!u[to]) {
            p[to] = v;
            dfs(to, lev + 1);
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        L[i].clear();
        u[i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    int cur = (n + 1)/2;
    if(L[cur].size() > 0) {
        int v = L[cur].back();
        vector<int> path;
        while(v != 1) {
            path.push_back(v);
            v = p[v];
        }
        path.push_back(1);
        cout << "PATH\n";
        cout << path.size() << "\n";
        for(int v: path) {
            cout << v << " ";
        }
        cout << "\n";
        return;
    }
    vector<pair<int, int>> d;
    for(int i = 1; i <= cur; i++) {
        for(int j = 1; j < L[i].size(); j += 2) {
            d.push_back({L[i][j], L[i][j-1]});
        }
    }
    cout << "PAIRING\n";
    cout << d.size() << "\n";
    for(auto x: d) {
        cout<< x.first << " " << x.second << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}