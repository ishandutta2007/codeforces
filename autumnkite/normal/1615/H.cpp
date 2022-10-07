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

  static constexpr size_type npos = static_cast<size_type>(-1);

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

  std::vector<bool> belong() const {
    std::vector<bool> res(n);
    for (size_type i = 0; i < n; ++i) {
      res[i] = dep[i] != npos;
    }
    return res;
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
  auto val = a;
  std::sort(val.begin(), val.end());
  val.erase(std::unique(val.begin(), val.end()), val.end());
  std::vector<std::vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
  }

  std::vector<int> id(n, -1);
  std::vector<int> ans(n);

  auto solve = [&](auto &self, const std::vector<int> &S,
                   int l, int r) -> void {
    if (S.empty()) {
      return;
    }
    for (int i = 0; i < (int)S.size(); ++i) {
      id[S[i]] = i;
    }
    mf_network<long long> G(S.size() + 2);
    for (int u : S) {
      for (int v : E[u]) {
        if (id[v] != -1) {
          G.add_edge(id[u], id[v], G.INF_flow);
        }
      }
    }
    int mid = (l + r) >> 1;
    for (int u : S) {
      long long c = std::abs(a[u] - val[mid]) - std::abs(a[u] - val[mid + 1]);
      if (c > 0) {
        G.add_edge(S.size(), id[u], c);
      } else {
        G.add_edge(id[u], S.size() + 1, -c);
      }
    }
    long long flow;
    G.slope(S.size(), S.size() + 1, flow);
    auto res = G.belong();
    std::vector<int> Sl, Sr;
    for (int u : S) {
      if (res[id[u]]) {
        Sr.push_back(u);
        ans[u] = val[mid + 1];
      } else {
        Sl.push_back(u);
        ans[u] = val[mid];
      }
      id[u] = -1;
    }
    if (l + 1 < r) {
      self(self, Sl, l, mid);
      self(self, Sr, mid, r);
    }
  };

  std::vector<int> all(n);
  std::iota(all.begin(), all.end(), 0);
  solve(solve, all, 0, val.size() - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
}