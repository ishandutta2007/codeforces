#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 3e6;

struct MCMF {
    const long long INF = 1ll << 60;
    struct edge {
        int v, id;
        long long f, c;
        edge (int _v, long long _f, long long _c, int _id) : v(_v), f(_f), c(_c), id(_id) {}
    };
    vector <vector <edge>> adj;
    vector <edge*> rt;
    vector <long long> dis;
    int n, s, t;
    MCMF (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
    }
    void add_edge(int u, int v, long long f, long long c) {
        adj[u].push_back(edge(v, f, c, adj[v].size()));
        adj[v].push_back(edge(u, 0, -c, adj[u].size() - 1));
    }
    bool SPFA() {
        rt.assign(n, NULL);
        dis.assign(n, INF);
        vector <bool> vis(n, false);
        queue <int> q;
        q.push(s);
        dis[s] = 0;
        vis[s] = true;
        while (q.size()) {
            int v = q.front(); q.pop();
            vis[v] = false;
            for (edge &e : adj[v]) if (e.f > 0 && dis[e.v] > dis[v] + e.c) {
                    dis[e.v] = dis[v] + e.c;
                    rt[e.v] = &e;
                    if (!vis[e.v]) {
                        vis[e.v] = true;
                        q.push(e.v);
                    }
                }
        }
        return dis[t] != INF;
    }
    pair <long long, long long> runFlow() { // cost, flow
        long long cost = 0, flow = 0;
        while (SPFA()) {
            vector <edge*> E;
            int v = t;
            long long addflow = INF;
            while (v != s) {
                E.push_back(rt[v]);
                addflow = min(addflow, rt[v]->f);
                v = adj[rt[v]->v][rt[v]->id].v;
            }
            for (edge* &e : E) {
                e->f -= addflow;
                adj[e->v][e->id].f += addflow;
            }
            flow += addflow;
            cost += addflow * dis[t];
        }
        return make_pair(cost, flow);
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, t, ll, rr, v;
    cin >> n >> q;
    vector <int> l(n, 1), r(n, n);
    while (q--) {
        cin >> t >> ll >> rr >> v, --ll;
        for (int i = ll; i < rr; ++i) {
            if (t == 1) l[i] = max(l[i], v);
            else r[i] = min(r[i], v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (l[i] > r[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    MCMF mcmf(n * 2 + 2, n * 2, n * 2 + 1);
    for (int i = 0; i < n; ++i) {
        mcmf.add_edge(n * 2, i, 1, 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = l[i]; j <= r[i]; ++j) {
            mcmf.add_edge(i, j + n - 1, 1, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mcmf.add_edge(i + n, n * 2 + 1, 1, j * 2 + 1);
        }
    }
    cout << mcmf.runFlow().first << endl;
}