#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<Val>>
class fenwick_tree {
public:
  typedef std::size_t size_type;

protected:
  const Val E;

  size_type n;
  std::vector<Val> val;

  VV fun;

public:
  fenwick_tree() : fenwick_tree(0) {}

  fenwick_tree(size_type _n)
  : E(), n(_n), val(n + 1, E) {}

  fenwick_tree(size_type _n, const Val &_E)
  : E(_E), n(_n), val(n + 1, E) {}

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    for (++x; x <= n; x += x & -x) {
      val[x] = fun(val[x], v);
    }
  }

  Val query(size_type x) {
    Val s = E;
    for (; x; x ^= x & -x) {
      s = fun(s, val[x]);
    }
    return s;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> fa(n, -1);
  std::vector<std::vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    std::cin >> fa[i];
    --fa[i];
    E[fa[i]].push_back(i);
  }
  
  int idx = 0;
  std::vector<int> dep(n), dfn(n), end(n);

  auto dfs = [&](auto &self, int u) -> void {
    dfn[u] = idx++;
    for (int v : E[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
    }
    end[u] = idx;
  };

  dfs(dfs, 0);

  std::vector<std::pair<int, int>> chain, cross;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x, --y;
    if (dep[x] > dep[y]) {
      std::swap(x, y);
    }
    if (dfn[x] <= dfn[y] && dfn[y] < end[x]) {
      chain.emplace_back(x, y);
    } else {
      cross.emplace_back(x, y);
    }
  }
  std::sort(chain.begin(), chain.end(), [&](auto a, auto b) {
    return dep[a.first] > dep[b.first];
  });

  fenwick_tree<int> T(n);

  auto query = [&](int x) {
    return T.query(end[x]) - T.query(dfn[x]);
  };

  for (auto [x, y] : chain) {
    if (dep[y] - dep[x] <= 1) {
      std::cout << -1 << "\n";
      return 0;
    }
    int p = *std::lower_bound(E[x].begin(), E[x].end(), y, [&](int x, int y) {
      return end[x] < end[y];
    });
    if (query(p) - query(y) == 0) {
      T.modify(dfn[p], 1);
    }
  }

  int tot = query(0);
  bool ok = true;
  for (auto [x, y] : cross) {
    if (tot - query(x) - query(y) == 0) {
      ok = false;
      break;
    }
  }
  std::cout << tot + !ok << "\n";
}