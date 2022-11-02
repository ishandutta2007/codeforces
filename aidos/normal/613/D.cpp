#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
const int L = 20;
typedef long long ll;

int tin[maxn];
int tout[maxn];
vector<int> g[maxn];
int timer;
int p[L][maxn];
int lev[maxn];
void dfs(int v, int pa) {
    tin[v] = ++timer;
    p[0][v] = pa;
    lev[v] = lev[pa]+1;
    for(int i = 1; i < L; i++) {
        p[i][v] = p[i-1][p[i-1][v]];
    }
    for(int to: g[v]) {
        if(to != pa) {
            dfs(to, v);
        }
    }
    tout[v] = timer;
}
int n;
int lca(int v, int u) {
    if(lev[v] < lev[u]) swap(v, u);
    for(int i = L - 1; i >= 0; i--) {
        if(lev[v] - (1<<i) >= lev[u]) {
            v = p[i][v];
        }
    }
    if(v == u) {
        return v;
    }
    for(int i = L - 1; i >= 0; i--) {
        if(p[i][v] != p[i][u]) {
            v = p[i][v];
            u = p[i][u];
        }
    }
    return p[0][v];
}
set<pair<int, int> > edges;
set<int> bad;
set< pair<int, int> > ver;
int good;
map<int, pair<int, int> > dp;
void calc(int v) {
    ver.erase({tin[v], v});
    vector< tuple<int, int, int> > s;
    while(true) {
        auto it = ver.lower_bound({tin[v], v});
        if(it == ver.end()) break;
        int to = it->second;
        if(tin[to] > tout[v]) break;
        calc(to);
        if(lev[to] - lev[v] == 1 && bad.count(v) && bad.count(to)) good = false;
        s.push_back({lev[to] - lev[v], dp[to].first, dp[to].second});
    }
    if(s.size() == 0) {
        if(bad.count(v)) {
            dp[v] = {1e7, 0};
        } else {
            dp[v] = {0, 0};
        }
    } else {
        if(bad.count(v)) {
            int cur = 0;
            for(auto [x, y, z]: s) {
                if(x == 1) {
                    cur += y;
                } else {
                    cur += min(y, z + 1);
                }
            }
            dp[v] = {1e7, cur};
        } else {
            long long x1 = 1;
            for(auto [x, y, z]: s) {
                x1 += min(y, z);
            }
            long long x2 = 0;
            for(auto [x, y, z]: s) {
                x2 += y;
            }
            long long y1 = 1e7;
            for(auto [x, y, z]: s) {
                y1 = min(y1, x2 - y + z);
            }
            dp[v] = {min((long long)1e7, min(x1, x2)), min(y1, (long long)1e7)};
        }
    }
}
void solve() {
    int k;
    cin >> k;
    bad.clear();
    ver.clear();
    vector<pair<int, int>> d(k);
    for(int i = 0; i < k; i++) {
        cin >> d[i].second;
        d[i].first = tin[d[i].second];
        ver.insert(d[i]);
        bad.insert(d[i].second);
    }
    if(k == 1) {
        cout << 0 << "\n";
        return;
    }
    sort(d.begin(), d.end());
    for(int i = 1; i < k; i++) {
        int t = lca(d[i-1].second, d[i].second);
        ver.insert({tin[t], t});
    }
    good=true;
    int start = ver.begin()->second;
    dp.clear();
    calc(start);
    if(good) {
        cout << min(dp[start].first, dp[start].second) << "\n";
        return;
    }
    cout<<-1 << "\n";
}

int main(){
    cin >> n;

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.insert({u, v});
        edges.insert({v, u});
    }
    dfs(1, 0);
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        solve();
    }
}