#include <bits/stdc++.h>
using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

template <class T> bool ckmin(T& x, T y) { if (x > y) { x = y; return 1; } return 0; }
template <class T> bool ckmax(T& x, T y) { if (x < y) { x = y; return 1; } return 0; }

template <class F> struct Dinic {
    struct Edge { int to; F flow, cap; };
    int n;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> adj;
    std::vector<int> level;
    std::vector<std::vector<int>::iterator> cur;
    void init(int n_) {
        n = n_;
        adj.assign(n, std::vector<int>());
        cur.assign(n, std::vector<int>::iterator());
        edges.clear();
        level.clear();
    }
    void ae(int u, int v, F cap, F rcap = 0) {
        assert(std::min(cap, rcap) >= 0);
        adj[u].push_back((int) edges.size());
        edges.push_back({v, 0, cap});
        adj[v].push_back((int) edges.size());
        edges.push_back({u, 0, rcap});
    }
    bool bfs(int s, int t) {
        level = std::vector<int>(n, -1);
        for (int i = 0; i < n; i++)
            cur[i] = adj[i].begin();
        std::queue<int> q({s});
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& eid : adj[u]) {
                const Edge& e = edges[eid];
                int v = e.to;
                if (level[v] < 0 && e.flow < e.cap) 
                    q.push(v), level[v] = level[u] + 1;
            }
        }
        return level[t] >= 0;
    }
    F dfs(int v, int t, F flow) {
        if (v == t)
            return flow;
        for (; cur[v] != adj[v].end(); cur[v]++) {
            Edge& e = edges[*cur[v]];
            if (level[e.to] != level[v] + 1 || e.flow == e.cap)
                continue;
            F df = dfs(e.to, t, std::min(flow, e.cap - e.flow));
            if (df) {
                e.flow += df;
                edges[*cur[v] ^ 1].flow -= df;
                return df;
            }
        }
        return 0;
    }
    F max_flow(int s, int t) {
        F tot = 0;
        while (bfs(s, t)) 
            while (F df = dfs(s, t, std::numeric_limits<F>::max())) 
                tot += df;
        return tot;
    }
};
template <class F> struct PushRelabel {
    struct Edge {int to, rev; F flow; };
    const F INF = std::numeric_limits<F>::max();  
    int n, s, t, highest, work;
    std::vector<std::vector<Edge>> adj;
    std::vector<std::vector<int>> lst, gap;
    std::vector<int> height, cnt;
    std::vector<F> excess;
    void init(int n_) {
        n = n_;
        adj.clear(); adj.resize(2 * n);
        lst.clear(); lst.resize(2 * n);
        gap.clear(); gap.resize(2 * n);
        height.assign(2 * n, 0);
        cnt.assign(2 * n, 0);
        excess.assign(2 * n, 0);
        work = highest = 0;
        s = 0;
        t = n - 1;
    }
    void ae(int u, int v, F cap) {
        assert(cap >= 0);
        Edge a{v, (int) adj[v].size(), cap};
        Edge b{u, (int) adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    void update_height(int v, int nh) {
        work++;
        if (height[v] != n)
            cnt[height[v]]--;
        height[v] = nh;
        if (nh == n)
            return;
        cnt[nh]++;
        highest = nh;
        gap[nh].push_back(v);
        if (excess[v] > 0)
            lst[nh].push_back(v);
    }
    void global_relabel() {
        work = 0;
        for (int i = 0; i < n; i++)
            height[i] = n, cnt[i] = 0;
        for (int i = 0; i < highest; i++) 
            lst[i].clear(), gap[i].clear();
        height[t] = 0;
        std::queue<int> q({t});
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : adj[v]) 
                if (height[e.to] == n && adj[e.to][e.rev].flow > 0)
                    q.push(e.to), update_height(e.to, height[v] + 1);
            highest = height[v];
        }
    }
    void push(int v, Edge& e) {
        if (excess[e.to] == 0)
            lst[height[e.to]].push_back(e.to);
        F df = std::min(excess[v], e.flow);
        e.flow -= df, adj[e.to][e.rev].flow += df;
        excess[v] -= df, excess[e.to] += df;
    }
    void discharge(int v) {
        int nh = n;
        for (auto& e : adj[v]) 
            if (e.flow > 0)
                if (height[v] == height[e.to] + 1) {
                    push(v, e);
                    if (excess[v] <= 0)
                        return;
                } else {
                    nh = std::min(nh, height[e.to] + 1);
                }
        if (cnt[height[v]] > 1) 
            update_height(v, nh);
        else {
            for (int i = height[v]; i <= highest; i++) {
                for (auto& j : gap[i])
                    update_height(j, n);
                gap[i].clear();
            }
        }
    }
    F max_flow(int s_, int t_) {
        s = s_, t = t_;
        if (s == t)
            return -1;
        for (int i = 0; i < n; i++)
            excess[i] = 0;
        excess[s] = INF, excess[t] = -INF;
        global_relabel();
        for (auto& e : adj[s]) 
            push(s, e);
        for (; highest >= 0; highest--)
            while (!lst[highest].empty()) {
                int v = lst[highest].back();
                lst[highest].pop_back();
                discharge(v);
                if (work > 4 * n)
                    global_relabel();
            }
        return excess[t] + INF;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vi> g(n, vi(m));
    PushRelabel<int> D;
    f0r(i, n) {
        string line; cin >> line;
        f0r(j, m) { 
            if (line[j] == '#') 
                g[i][j] = 1;
        }
    }
    D.init(n*m*4);
    int cnt = 0;
    const int INF = 1e9;
    vi lef;
    vi rig;
    auto valid = [&](int i, int j) -> bool {
        return i>=0&&j>=0&&i<n&&j<m;
    };
    auto good = [&](int i, int j) -> bool {
        return valid(i, j) && g[i][j];
    };
    f0r(i, n) {
        f0r(j, m-1) {
            if (g[i][j] && g[i][j+1]) {
                int cur = cnt;
                {
                    if (good(i-1, j)) {
                        D.ae(cur, cur-m, 1);
                    }
                    if (good(i+1, j)) {
                        D.ae(cur, cur+m-1, 1);
                    }
                    if (good(i-1, j+1)) {
                        D.ae(cur, cur-m+1, 1);
                    }
                    if (good(i+1, j+1)) {
                        D.ae(cur, cur+m, 1);
                    }  
                }
                lef.eb(cnt);
            }
            cnt++;
        }
        if (i == n-1) continue;
        f0r(j, m) {
            if (g[i][j] && g[i+1][j]) {
                rig.eb(cnt);
            }
            cnt++;
        }
    }
    int blocks = 0;
    f0r(i, n) f0r(j, m) blocks += g[i][j];
    int source = cnt++;
    int sink = cnt++;
    for (int x : lef) D.ae(source, x, 1);
    for (int x : rig) D.ae(x, sink, 1);
    int res = D.max_flow(source, sink);
    int tot = sz(lef)+sz(rig)-res;
    int ans = blocks - tot;
    cout << ans << '\n';
    return 0;
}