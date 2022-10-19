#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5, inf = 1e9 + 7;

struct edge {
    int to, fl, c, ind;

    edge(int _to, int _c, int _ind) {
        to = _to, fl = 0, c = _c, ind = _ind;
    }
};

vector<edge> g[maxn];

void add_edge(int u, int v, int c) {
    g[u].emplace_back(v, c, g[v].size());
    g[v].emplace_back(u, 0, (int)g[u].size() - 1);
}

int s = 0, t = 1, sz;

bool used[maxn];

int dist[maxn];

int dfs(int v, int flow) {
    if (v == t) {
        return flow;
    }
    used[v] = true;
    for (auto &e : g[v]) {
        if (dist[e.to] == dist[v] + 1 && !used[e.to] && e.fl < e.c) {
            int val = dfs(e.to, min(flow, e.c - e.fl));
            if (val) {
                e.fl += val;
                g[e.to][e.ind].fl -= val;
                return val;
            }
        }
    }
    return 0;
}

bool bfs() {
    for (int i = 0; i < sz; ++i) {
        dist[i] = -1;
    }
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : g[v]) {
            if (dist[e.to] == -1 && e.fl < e.c) {
                dist[e.to] = dist[v] + 1;
                q.push(e.to);
            }
        }
    }
    return dist[t] != -1;
}

void solve() {
    int n, m, g;
    cin >> n >> m >> g;
    sz = n + m + 2;
    vector<int> tp(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> tp[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 0) {
            add_edge(s, i + 2, v[i]);
        } else {
            add_edge(i + 2, t, v[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int t, w, k;
        cin >> t >> w >> k;
        ans += w;
        vector<int> v(k);
        for (int j = 0; j < k; ++j) {
            cin >> v[j];
            v[j]--;
        }
        int fr;
        cin >> fr;
        if (fr) {
            w += g;
        }
        if (t == 0) {
            add_edge(s, i + n + 2, w);
        } else {
            add_edge(i + n + 2, t, w);
        }
        for (int j = 0; j < k; ++j) {
            if (t == 0) {
                add_edge(i + n + 2, v[j] + 2, inf);
            } else {
                add_edge(v[j] + 2, i + n + 2, inf);
            }
        }
    }
    while (bfs()) {
        while (true) {
            for (int i = 0; i < sz; ++i) {
                used[i] = false;
            }
            int val = dfs(s, inf);
            ans -= val;
            if (!val) {
                break;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}