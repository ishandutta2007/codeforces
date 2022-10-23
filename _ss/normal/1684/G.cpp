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
using vll = vector<ll>;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 1e5 + 10;
int a[N], n, m, mark[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Dinic flow(n + 2, 0, n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] > m / 3) flow.add_edge(0, i, 1), cnt++;
        else flow.add_edge(i, n + 1, 1);
    for (int i = 1; i <= n; ++i)
        if (a[i] > m / 3)
            for (int j = 1; j <= n; ++j)
                if (a[i] * 2 + a[j] <= m && a[i] % a[j] == 0)
                    flow.add_edge(i, j, 1);
    if (flow.flow() < cnt)
    {
        cout << -1;
        return 0;
    }
    vector<pii> ans;
    for (auto e : flow.edges)
        if (e.flow == 1 && e.v > 0 && e.u <= n)
        {
            ans.eb(a[e.v] * 2 + a[e.u], a[e.v] + a[e.u]);
            mark[e.v] = mark[e.u] = 1;
        }
    for (int i = 1; i <= n; ++i)
        if (!mark[i]) ans.eb(a[i] * 3, a[i] * 2);
    cout << ans.size() << "\n";
    for (pii pa : ans) cout << pa.fi << " " << pa.se << "\n";
    return 0;
}