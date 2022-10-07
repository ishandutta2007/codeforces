#include <bits/stdc++.h>

class graph {
  int n, m;
  std::vector<std::vector<std::tuple<int, int, bool>>> E;

  std::vector<std::size_t> hd;
  std::vector<bool> vis;

  void dfs(int u, std::vector<std::tuple<int, int, bool>> &res) {
    for (std::size_t &i = hd[u]; i != E[u].size(); ++i) {
      auto [v, id, dir] = E[u][i];
      if (vis[id]) {
        continue;
      }
      vis[id] = true;
      dfs(v, res);
      res.emplace_back(v, id, !dir);
      if (i == E[u].size()) {
        break;
      }
    }
  }

public:
  graph(int t_n = 0) : n(t_n), m(0), E(n) {}

  void add_edge(int u, int v) {
    E[u].emplace_back(v, m, false);
    E[v].emplace_back(u, m, true);
    ++m;
  }

  std::vector<std::vector<std::tuple<int, int, bool>>> cycles() {
    hd.assign(n, 0);
    vis.assign(m, false);
    std::vector<std::vector<std::tuple<int, int, bool>>> res;
    for (int i = 0; i < n; ++i) {
      std::vector<std::tuple<int, int, bool>> t;
      dfs(i, t);
      if (!t.empty()) {
        res.emplace_back(t);
      }
    }
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  graph G1(n + 1), G2(n + 1);
  std::vector<int> deg1(n), deg2(n);
  std::vector<int> edge1, edge2;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    --u, --v;
    if (w == 1) {
      G1.add_edge(u, v);
      ++deg1[u], ++deg1[v];
      edge1.emplace_back(i);
    } else {
      G2.add_edge(u, v);
      ++deg2[u], ++deg2[v];
      edge2.emplace_back(i);
    }
  }
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += deg1[i] & 1;
  }
  std::vector<int> ans(m);

  for (int i = 0; i < n; ++i) {
    if (deg2[i] & 1) {
      G2.add_edge(n, i);
    }
  }
  auto res2 = G2.cycles();
  std::vector<std::vector<int>> id;
  for (auto &p : res2) {
    int lst = -1, fst = -1;
    for (int i = 0; i < (int)p.size(); ++i) {
      if (std::get<1>(p[i]) < (int)edge2.size()) {
        ans[edge2[std::get<1>(p[i])]] = std::get<2>(p[i]);
      }
      if (std::get<0>(p[i]) == n) {
        if (lst != -1) {
          id.emplace_back();
          for (int j = lst + 1; j + 1 < i; ++j) {
            id.back().emplace_back(edge2[std::get<1>(p[j])]);
          }
          int u = std::get<0>(p[lst + 1]), v = std::get<0>(p[i - 1]);
          G1.add_edge(u, v); 
          ++deg1[u], ++deg1[v];
        }
        lst = i;
        if (fst == -1) {
          fst = i;
        }
      }
    }
    if (lst != -1) {
      id.emplace_back();
      int L = p.size();
      for (int j = (lst + 1) % L; (j + 1) % L != fst; j = (j + 1) % L) {
        id.back().emplace_back(edge2[std::get<1>(p[j])]);
      }
      int u = std::get<0>(p[(lst + 1) % L]);
      int v = std::get<0>(p[(fst + L - 1) % L]);
      G1.add_edge(u, v);
      ++deg1[u], ++deg1[v];
    }
  }

  for (int i = 0; i < n; ++i) {
    if (deg1[i] & 1) {
      G1.add_edge(n, i);
    }
  }
  auto res1 = G1.cycles();
  for (auto &p : res1) {
    for (int i = 0; i < (int)p.size(); ++i) {
      int e = std::get<1>(p[i]);
      if (e < (int)edge1.size()) {
        ans[edge1[e]] = std::get<2>(p[i]);
      } else if (e - (int)edge1.size() < (int)id.size()) {
        for (int k : id[e - edge1.size()]) {
          ans[k] ^= std::get<2>(p[i]);
        }
      }
    }
  }

  std::cout << tot << "\n";
  for (int i = 0; i < m; ++i) {
    std::cout << ans[i] + 1;
  }
  std::cout << "\n";
}