#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;

const int N = 1e3 + 10;

int d[N][N];

struct edge {int u, v, w;};


void bfs(int n, vector<vi>& G, int st) {
    vi vis(n + 1);
    vis[st] = 1;
    d[st][st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u])
            if (!vis[v]) {
                d[st][v] = d[st][u] + 1;
                vis[v] = 1;
                q.push(v);
            }
    }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vi> G(n + 1);
        vector<edge> E(m);
        vi best(n + 1, 1e9);
        for (int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            G[u].eb(v);
            G[v].eb(u);
            E[i] = {u, v, w};
            best[u] = min(best[u], w);
            best[v] = min(best[v], w);
        }
        for (int i = 1; i <= n; ++i) bfs(n, G, i);
        ll res = 1e18;
        for (edge e : E) {
            int u = e.u, v = e.v;
            ll w = e.w;
            res = min(res, w * (min(d[1][u] + d[n][v], d[1][v] + d[n][u]) + 1));
        }
        for (int u = 1; u <= n; ++u) {
            int dist = 1e9;
            for (int v = 1; v <= n; ++v) dist = min(dist, d[v][u] + d[v][1] + d[v][n]);
            res = min(res, (ll)best[u] * (dist + 2));
        }
        cout << res << "\n";
    }
    return 0;
}