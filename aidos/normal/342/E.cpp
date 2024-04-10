#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 3e5 + 100;
const int mod = (int)998244353 ;
int n, m;
vector<int> g[maxn];
int del[maxn];
vector<int> ord;
int mx[maxn];
int sz[maxn];
vector< pair<int, int> > C[maxn];
void dfs(int v, int p) {
    sz[v] = 1;
    mx[v] = 0;
    ord.push_back(v);
    for(int to: g[v]) {
        if(del[to]) continue;
        if(to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        mx[v] = max(mx[v], sz[to]);
    }
}
int dist[maxn];
int min_dist[maxn];

void dfs2(int v, int p, int len) {
    dist[v] = len;
    for(int to: g[v]) {
        if(del[to]) continue;
        if(to == p) continue;
        dfs2(to, v, len + 1);
    }
}
void rec(int v) {
    ord.clear();
    dfs(v, -1);
    int c = v;
    for(int to: ord) {
        if(max((int)ord.size() - sz[to], mx[to]) < max((int)ord.size() - sz[c], mx[c]) ) {
            c = to;
        }
    }
    dfs2(c, -1, 0);
    for(int to: ord) {
        C[to].push_back(make_pair(c, dist[to]));
    }
    del[c] = 1;
    for(int to: g[c]) {
        if(!del[to]) rec(to);
    }
}
void upd(int v) {
    for(auto x: C[v]) {
        min_dist[x.first] = min(min_dist[x.first], x.second);
    }
}
int get(int v) {
    int res = 1e9;
    for(auto x: C[v]) {
        res = min(min_dist[x.first]+x.second, res);
    }
    return res;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        min_dist[i] = 1e9;
    }
    rec(1);
    upd(1);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 1) {
            upd(y);
        } else {
            cout << get(y) << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}