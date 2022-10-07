#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::tuple<int, int, int>> edges;
  std::vector<std::vector<std::pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w, t;
    std::cin >> u >> v >> w >> t;
    --u, --v;
    edges.emplace_back(-w, u, v);
    E[u].emplace_back(v, t);
    E[v].emplace_back(u, t);
  }
  for (int i = 0; i < q; ++i) {
    int v, x;
    std::cin >> v >> x;
    --x;
    edges.emplace_back(-v, n + i, x);
  }
  std::sort(edges.begin(), edges.end());

  int LG = std::__lg(n) + 1;
  std::vector<int> dep(n);
  std::vector<std::vector<int>> fa(n, std::vector<int>(LG, -1));
  std::vector<std::vector<int>> max(n, std::vector<int>(LG));

  auto dfs = [&](auto &self, int u) -> void {
    for (int i = 1; i < LG && fa[u][i - 1] != -1; ++i) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
      max[u][i] = std::max(max[u][i - 1], max[fa[u][i - 1]][i - 1]);
    }
    for (auto [v, w] : E[u]) {
      if (v != fa[u][0]) {
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        max[v][0] = w;
        self(self, v);
      }
    }
  };

  dfs(dfs, 0);

  auto max_toll = [&](int u, int v) {
    int res = 0;
    if (dep[u] < dep[v]) {
      std::swap(u, v);
    }
    for (int i = LG - 1; i >= 0; --i) {
      if (fa[u][i] != -1 && dep[fa[u][i]] >= dep[v]) {
        res = std::max(res, max[u][i]);
        u = fa[u][i];
      }
    }
    if (u == v) {
      return res;
    }
    for (int i = LG - 1; i >= 0; --i) {
      if (fa[u][i] != fa[v][i]) {
        res = std::max(res, std::max(max[u][i], max[v][i]));
        u = fa[u][i], v = fa[v][i];
      }
    }
    res = std::max(res, std::max(max[u][0], max[v][0]));
    return res;
  };

  std::vector<int> f(n);
  std::vector<int> id(n);
  std::vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    f[i] = i;
    id[i] = i;
    s[i] = 0;
  }

  std::function<int(int)> find = [&](int x) {
    return f[x] == x ? x : (f[x] = find(f[x]));
  };

  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    f[y] = x;
    if (a[id[x]] == a[id[y]]) {
      s[x] = std::max(std::max(s[x], s[y]), max_toll(id[x], id[y]));
    } else if (a[id[y]] > a[id[x]]) {
      id[x] = id[y];
      s[x] = s[y];
    }
    return true;
  };

  std::vector<std::pair<int, int>> ans(q);
  for (auto [w, u, v] : edges) {
    if (u >= n) {
      int t = find(v);
      ans[u - n] = std::pair(a[id[t]], std::max(max_toll(v, id[t]), s[t]));
    } else {
      merge(u, v);
    }
  }
  for (auto [x, y] : ans) {
    std::cout << x << " " << y << "\n";
  }
}