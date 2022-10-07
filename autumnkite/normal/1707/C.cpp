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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  disjoint_set D(n);
  std::vector<std::vector<int>> E(n);
  std::vector<std::pair<int, int>> other;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    if (D.merge(u, v)) {
      E[u].push_back(v);
      E[v].push_back(u);
    } else {
      other.emplace_back(u, v);
    }
  }

  int idx = 0;
  std::vector<int> dfn(n), end(n);

  auto dfs = [&](auto &self, int u, int fa) -> void {
    if (fa != -1) {
      E[u].erase(std::find(E[u].begin(), E[u].end(), fa));
    }
    dfn[u] = idx++;
    for (int v : E[u]) {
      self(self, v, u);
    }
    end[u] = idx;
  };

  dfs(dfs, 0, -1);

  std::vector<int> c(n + 1);
  for (auto [u, v] : other) {
    if (dfn[u] > dfn[v]) {
      std::swap(u, v);
    }
    ++c[dfn[v]];
    --c[end[v]];
    if (dfn[v] < end[u]) {
      auto it = std::upper_bound(E[u].begin(), E[u].end(), v, [&](int x, int y) {
        return dfn[x] < dfn[y];
      });
      int z = *--it;
      ++c[0];
      --c[dfn[z]];
      ++c[end[z]];
      --c[n];
    } else {
      ++c[dfn[u]];
      --c[end[u]];
    }
  }
  for (int i = 0; i < n; ++i) {
    c[i + 1] += c[i];
  }
  for (int i = 0; i < n; ++i) {
    if (c[dfn[i]] == (int)other.size()) {
      std::cout << 1;
    } else {
      std::cout << 0;
    }
  }
  std::cout << "\n";
}