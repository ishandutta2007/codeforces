#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

template <typename flow_t = int>
struct DinicFlow {
    const flow_t INF = numeric_limits<flow_t>::max() / 2; // 1e9
 
    int n, s, t;
    vector<vector<int>> adj;
    vector<int> d, cur;
    vector<int> to;
    vector<flow_t> c, f;
 
    DinicFlow(int n, int s, int t) : n(n), s(s), t(t), adj(n, vector<int>()), d(n, -1), cur(n, 0) {}
 
    int addEdge(int u, int v, flow_t _c) {
        adj[u].push_back(to.size()); 
        to.push_back(v); f.push_back(0); c.push_back(_c);
        adj[v].push_back(to.size());
        to.push_back(u); f.push_back(0); c.push_back(0);
        return (int)to.size() - 2;
    }
 
    bool bfs() {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto edgeId : adj[u]) {
                int v = to[edgeId];
                if (d[v] == -1 && f[edgeId] < c[edgeId]) {
                    d[v] = d[u] + 1;
                    if (v == t) return 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    }
 
    flow_t dfs(int u, flow_t res) {
        if (u == t || !res) return res;
        for (int &i = cur[u]; i < adj[u].size(); i++) {
            int edgeId = adj[u][i];
            int v = to[edgeId];
            if (d[v] == d[u] + 1 && f[edgeId] < c[edgeId]) {
                flow_t foo = dfs(v, min(res, c[edgeId] - f[edgeId]));
                if (foo) {
                    f[edgeId] += foo;
                    f[edgeId ^ 1] -= foo;
                    return foo;
                }
            }
        }
        return 0;
    }
 
    flow_t maxFlow() {
        flow_t res = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0);
            while (flow_t aug = dfs(s, INF)) res += aug;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    DinicFlow<int> df = DinicFlow<int> (n + 2, n, n + 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            df.addEdge(n, i, b[i]);
            res += b[i];
        } else {
            df.addEdge(i, n + 1, -b[i]);
        }
    }
    vector<int> pos(101, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            if (a[i] % j == 0 && pos[j] != -1) {
                df.addEdge(i, pos[j], INF);
            }
        }
        pos[a[i]] = i;
    }

    cout << res - df.maxFlow() << '\n';

    return 0;
}