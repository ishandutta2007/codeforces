#include <bits/stdc++.h>

class disjoint_set {
public:
  typedef std::size_t size_type;

protected:
  std::vector<size_type> fa;

public:
  disjoint_set(size_type n = 0) : fa(n) {
    std::iota(fa.begin(), fa.end(), 0);
  }

  size_type find(size_type x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
  }

  bool merge(size_type x, size_type y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    fa[y] = x;
    return true;
  }
};

class tree {
  int n;
  std::vector<std::vector<int>> E;
  std::vector<int> fa, dep, col, size, son, top;

  void dfs(int u) {
    col[u] = dep[u] & 1;
    size[u] = 1;
    son[u] = -1;
    for (int v : E[u]) {
      if (v != fa[u]) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
        size[u] += size[v];
        if (son[u] == -1 || size[v] > size[son[u]]) {
          son[u] = v;
        }
      }
    }
  }

  void dfs(int u, int tp) {
    top[u] = tp;
    if (son[u] != -1) {
      dfs(son[u], tp);
    }
    for (int v : E[u]) {
      if (v != fa[u] && v != son[u]) {
        dfs(v, v);
      }
    }
  }

  void solve(int u, std::vector<int> &a) const {
    for (int v : E[u]) {
      if (v != fa[u]) {
        solve(v, a);
        a[u] += a[v];
      }
    }
  }

public:
  tree(int t_n) : n(t_n), E(n) {}

  void add_edge(int u, int v) {
    E[u].push_back(v);
    E[v].push_back(u);
  }

  void init() {
    fa.assign(n, -1);
    dep.assign(n, 0);
    col.resize(n);
    size.resize(n);
    son.resize(n);
    top.resize(n);
    dfs(0);
    dfs(0, 0);
  }

  int LCA(int u, int v) const {
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) {
        std::swap(u, v);
      }
      u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
  }

  int color(int u) const {
    return col[u];
  }

  void solve(std::vector<int> &a) const {
    solve(0, a);
  }

  void change(int u) {
    col[u] ^= 1;
    for (int v : E[u]) {
      if (v != fa[u]) {
        change(v);
      }
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    disjoint_set D(n);
    tree T(n);
    std::vector<std::pair<int, int>> out;
    for (int i = 0; i < m; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      if (D.merge(u, v)) {
        T.add_edge(u, v);
      } else {
        out.emplace_back(u, v);
      }
    }
    T.init();

    int cnt = 0;
    for (auto [u, v] : out) {
      cnt += T.color(u) == T.color(v);
    }
    if (cnt <= 1) {
      for (auto [u, v] : out) {
        if (!T.color(u) && !T.color(v)) {
          T.change(0);
          break;
        }
      }
      std::cout << "YES\n";
      for (int u = 0; u < n; ++u) {
        std::cout << T.color(u);
      }
      std::cout << "\n";
      continue;
    }

    std::vector<int> c0(n), c1(n);
    for (auto [u, v] : out) {
      if (T.color(u) == T.color(v)) {
        ++c0[u], ++c0[v];
        c0[T.LCA(u, v)] -= 2;
      } else {
        ++c1[u], ++c1[v];
        c1[T.LCA(u, v)] -= 2;
      }
    }
    T.solve(c0);
    T.solve(c1);
    bool ok = false;
    for (int u = 1; u < n; ++u) {
      if (c0[u] == cnt && !c1[u]) {
        T.change(u);
        if (!T.color(u)) {
          T.change(0);
        }
        ok = true;
        break;
      }
    }
    if (ok) {
      std::cout << "YES\n";
      for (int u = 0; u < n; ++u) {
        std::cout << T.color(u);
      }
      std::cout << "\n";
    } else {
      std::cout << "NO\n";
    }
  }
}