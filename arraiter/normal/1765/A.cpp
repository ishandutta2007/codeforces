#include <bits/stdc++.h>
using namespace std;

template <class T> struct simple_queue {
    vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    vector<edge> edges() {
        int m = int(pos.size());
        vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        vector<int> level(_n), iter(_n);
        simple_queue<int> que;

        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    vector<bool> min_cut(int s) {
        vector<bool> visited(_n);
        simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    mf_graph<int> G(2 * m + 2);
    int s = 2 * m, t = s + 1;
    for (int i = 0; i < m; i++) {
        G.add_edge(s, i, 1);
        G.add_edge(i + m, t, 1);
    }
    vector eid(m, vector<int>(m, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            bool good = 1, eq = 1;
            for (int k = 0; k < n; k++) {
                good &= a[k][i] >= a[k][j];
                eq &= a[k][i] == a[k][j];
            }
            if (i < j && eq) continue;
            if (good) {
                eid[i][j] = G.add_edge(i, j + m, 1);
            }
        }
    }
    cout << m - G.flow(s, t) << "\n";
    vector<int> nxt(m, -1);
    vector<bool> vis(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (~eid[i][j] && G.get_edge(eid[i][j]).flow) {
                nxt[i] = j, vis[j] = 1;
            }
        }
    }
    int tot = 0;
    vector<int> bel(m), lev(m);
    vector<vector<int>> res(n);
    for (int i = 0; i < m; i++) {
        if (vis[i]) continue;
        tot++;
        vector<int> id;
        for (int j = i; ~j; j = nxt[j]) {
            id.push_back(j);
            lev[j] = id.size(), bel[j] = tot;
        }
        for (int j = 0; j < n; j++) {
            int x = 0;
            for (int k = 0; k < m; k++) {
                if (bel[k] == tot && a[j][k] == '1') {
                    x = max(x, lev[k]);
                }
            }
            res[j].push_back(x);
        }
    }
    for (int x : bel) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : lev) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int x : res[i]) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}