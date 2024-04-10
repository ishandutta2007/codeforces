#include <bits/stdc++.h>

template <class Flow>
class mf_network {
public:
  typedef std::size_t size_type;

  static const Flow INF_flow = std::numeric_limits<Flow>::max();

protected:
  struct edge {
    size_type u, v;
    Flow flow;

    edge(size_type t_u, size_type t_v, Flow t_flow)
    : u(t_u), v(t_v), flow(t_flow) {}
  };

  static const size_type npos = static_cast<size_type>(-1);

  size_type n, S, T;
  std::vector<edge> edges;
  std::vector<std::vector<size_type>> E;

  std::vector<size_type> dep;

  bool bfs() {
    std::fill(dep.begin(), dep.end(), npos);
    std::vector<size_type> Q;
    dep[S] = 0;
    Q.push_back(S);
    if (S == T) {
      return true;
    }
    for (size_type i = 0; i < Q.size(); ++i) {
      size_type u = Q[i];
      for (size_type id : E[u]) {
        size_type v = edges[id].v;
        Flow flow = edges[id].flow;
        if (flow && dep[v] == npos) {
          dep[v] = dep[u] + 1;
          Q.push_back(v);
          if (v == T) {
            return true;
          }
        }
      }
    }
    return false;
  }

  std::vector<size_type> iter;

  Flow dfs(size_type u, Flow all) {
    if (u == T || !all) {
      return all;
    }
    Flow res = 0;
    for (size_type &i = iter[u]; i < E[u].size(); ++i) {
      size_type id = E[u][i];
      size_type v = edges[id].v;
      Flow flow = edges[id].flow;
      if (dep[v] == dep[u] + 1) {
        Flow tmp = dfs(v, std::min(all, flow));
        if (tmp) {
          edges[id].flow -= tmp, edges[id ^ 1].flow += tmp;
          res += tmp, all -= tmp;
          if (!all) {
            break;
          }
        }
      }
    }
    if (!res) {
      dep[u] = npos;
    }
    return res;
  }

public:
  mf_network(size_type t_n) : n(t_n), E(n), dep(n), iter(n) {}

  void add_edge(size_type u, size_type v, Flow c) {
    E[u].push_back(edges.size()), edges.emplace_back(u, v, c);
    E[v].push_back(edges.size()), edges.emplace_back(v, u, 0);
  }

  size_type edge_size() {
    return edges.size() >> 1;
  }

  void slope(size_type t_S, size_type t_T, Flow &flow) {
    S = t_S, T = t_T;
    flow = 0;
    while (bfs()) {
      std::fill(iter.begin(), iter.end(), 0);
      flow += dfs(S, INF_flow);
    }
  }

  Flow edge_flow(size_type id) {
    return edges[id << 1 | 1].flow;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  for (int i = 0; i < n; ++i) {
    if (2 * a[i] >= m) {
      std::cout << -1 << "\n";
      return 0;
    }
  }

  mf_network<int> G(n + 2);
  int S = n, T = n + 1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (3 * a[i] > m) {
      ++cnt;
      G.add_edge(S, i, 1);
      for (int j = 0; j < n; ++j) {
        if (3 * a[j] <= m && a[i] % a[j] == 0 && 2 * a[i] + a[j] <= m) {
          G.add_edge(i, j, 1);
        }
      }
    } else {
      G.add_edge(i, T, 1);
    }
  }

  int flow;
  G.slope(S, T, flow);

  if (flow != cnt) {
    std::cout << -1 << "\n";
    return 0;
  }

  std::vector<std::pair<int, int>> ans;
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    if (3 * a[i] > m) {
      ++idx;
      for (int j = 0; j < n; ++j) {
        if (3 * a[j] <= m && a[i] % a[j] == 0 && 2 * a[i] + a[j] <= m) {
          if (G.edge_flow(idx)) {
            ans.emplace_back(2 * a[i] + a[j], a[i] + a[j]);
          }
          ++idx;
        }
      }
    } else {
      if (!G.edge_flow(idx)) {
        ans.emplace_back(3 * a[i], 2 * a[i]);
      }
      ++idx;
    }
  }
  std::cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    std::cout << x << " " << y << "\n";
  }
}