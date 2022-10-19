#line 2 "/Users/alex/Code/Templates/graph/maxflow.hpp"

#include <vector>
#include <cassert>

#line 2 "/Users/alex/Code/Templates/ds/queue.hpp"

#line 4 "/Users/alex/Code/Templates/ds/queue.hpp"

namespace Quark {

using std::vector;

template <typename T> struct simple_queue {
  vector<T> arr;
  int pos = 0;
  void reserve(int n) { arr.reserve(n); }
  int size() const { return int(arr.size()) - pos; }
  bool empty() const { return pos == int(arr.size()); }
  void push(const T &t) { arr.push_back(t); }
  T &front() { return arr[pos]; }
  void clear() {
    arr.clear();
    pos = 0;
  }
  void pop() { pos++; }
};
} // namespace Quark
#line 2 "/Users/alex/Code/Templates/util/y_combinator.hpp"

#include <functional>
#include <utility>

namespace Quark {

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace Quark
#line 8 "/Users/alex/Code/Templates/graph/maxflow.hpp"

using std::min;
using std::numeric_limits;
using std::pair;
using std::vector;

namespace Quark {
template <typename Cap> struct MfGraph {
public:
  MfGraph() : _n(0) {}
  MfGraph(int n) : _n(n), g(n) {}

  virtual int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to) {
      to_id++;
    }
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
    vector<edge> res;
    for (int i = 0; i < m; i++) {
      res.push_back(get_edge(i));
    }
    return res;
  }

  Cap flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max()); }

  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    vector<int> level(_n), iter(_n);
    simple_queue<int> q;

    auto bfs = [&]() {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.clear();
      q.push(s);
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : g[v]) {
          if (e.cap == 0 || level[e.to] >= 0) {
            continue;
          }
          level[e.to] = level[v] + 1;
          if (e.to == t) {
            return;
          }
          q.push(e.to);
        }
      }
    };
    auto dfs = y_combinator([&](auto self, int v, Cap up) -> Cap {
      if (v == s) {
        return up;
      }
      Cap res = 0;
      int level_v = level[v];
      for (int &i = iter[v]; i < int(g[v].size()); i++) {
        _edge &e = g[v][i];
        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) {
          continue;
        }
        Cap d = self(e.to, min(up - res, g[e.to][e.rev].cap));
        if (d <= 0) {
          continue;
        }
        g[v][i].cap += d;
        g[e.to][e.rev].cap -= d;
        res += d;
        if (res == up) {
          return res;
        }
      }
      level[v] = _n;
      return res;
    });

    Cap flow = 0;
    while (flow < flow_limit) {
      bfs();
      if (level[t] == -1) {
        break;
      }
      fill(iter.begin(), iter.end(), 0);
      Cap f = dfs(t, flow_limit - flow);
      if (!f) {
        break;
      }
      flow += f;
    }
    return flow;
  }

  vector<bool> min_cut(int s) {
    vector<bool> visited(_n);
    simple_queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      visited[v] = true;
      for (auto e : g[v]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          q.push(e.to);
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
} // namespace Quark
#line 2 "/Users/alex/Code/Templates/template/template.hpp"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

namespace Quark {
void solve();
};

int main() { Quark::solve(); }
#line 3 "main.cpp"

const ll INF = 1e18 + 228;

void Quark::solve() {
    int n, m;
    cin >> n >> m;
    MfGraph<ll> g(2 * n + 2);
    int s = 2 * n;
    int t = 2 * n + 1;
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g.add_edge(s, a, INF);
    g.add_edge(s, b + n, INF);
    g.add_edge(a + n, t, INF);
    g.add_edge(b, t, INF);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        g.add_edge(u, v + n, l);
        g.add_edge(u + n, v, l);
        g.add_edge(v, u + n, l);
        g.add_edge(v + n, u, l);
    }
    cout << g.flow(s, t) << endl;
    auto cut = g.min_cut(s);
    for (int i = 0; i < n; i++) {
        if (cut[i] == cut[i + n]) {
            cout << "C";
        } else if (cut[i]) {
            cout << "A";
        } else {
            cout << "B";
        }
    }
    cout << endl;
}