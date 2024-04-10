#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}"; }
const int MAX = 5e5 + 5;
const int INF = 1e9;
vector<int> adj[MAX][2];
vector<pair<int, int>> rev[MAX];
int dist[MAX];
bool vis[MAX];
bool add[MAX];
int ans[MAX];
vector<int> level[MAX];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t; cin >> u >> v >> t;
        u--; v--;
        adj[u][t].push_back(v);
        rev[v].emplace_back(u, t);
    }
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[n - 1] = 0;
    ans[n - 1] = 0;
    level[0].push_back(n - 1);
    add[n - 1] = true;
    vis[n - 1] = true;
    for (int i = 0; i < n; i++) {
        if (level[i].size() == 0) break;
        for (int src: level[i]) {
            vis[src] = true;
        }
        for (int src: level[i]) {
            for (auto nxt: rev[src]) {
                if (dist[nxt.first] <= i || vis[nxt.first]) continue;
                ans[nxt.first] = (nxt.second ^ 1);
                vis[nxt.first] = true;
            }
        }
        for (int src: level[i]) {
            for (auto nxt: rev[src]) {
                if (dist[nxt.first] <= i || add[nxt.first]) continue;
                if (nxt.second == ans[nxt.first]) {
                    dist[nxt.first] = i + 1;
                    level[i + 1].push_back(nxt.first);
                    add[nxt.first] = true;
                }
            }
        }
    }
    if (dist[0] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dist[0] << '\n';
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
    return 0;
}