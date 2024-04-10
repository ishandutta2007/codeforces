#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <queue>

#define CHECK_IMPL1(cond)                \
    if (!(cond)) {                       \
      DEBUG("expected cond: " << #cond); \
      assert(cond);                      \
    }

#define CHECK_IMPL2(cond, message)                                              \
    if (!(cond)) {                                                              \
      DEBUG("expected cond: " << #cond << " failed with message: " << message); \
      assert(cond);                                                             \
    }

#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __APPLE__
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

struct Edge {
  int a, b, c;
};

class Dsu {
public:
  Dsu(int n): p_(n), sz_(n) {
    reset();
  }

  void reset() {
    std::iota(p_.begin(), p_.end(), 0);
    std::fill(sz_.begin(), sz_.end(), 1);
  }

  int get(int v) {
    if (v == p_[v]) {
      return v;
    }
    return p_[v] = get(p_[v]);
  }

  void merge(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
      return;
    }

    if (sz_[v] > sz_[u]) {
      std::swap(u, v);
    }

    p_[v] = u;
    sz_[u] += sz_[v];
  }

private:
  std::vector<int> p_;
  std::vector<int> sz_;
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a;
    --b;
    edges.push_back(Edge{a, b, c});
  }

  std::sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.c < rhs.c;
  });

  Dsu dsu(n);
  int64_t ans = 0;
  int max_edge = 0;
  for (int i = 0; i < m; ++i) {
    auto [a, b, c] = edges[i];
    if (dsu.get(a) != dsu.get(b)) {
      dsu.merge(a, b);
      
      max_edge = std::max(max_edge, c);
      if (c > k) {
        ans += c - k;
      }
    }
  }
  if (max_edge < k) {
    ans = k - max_edge;
    for (int i = 0; i < m; ++i) {
      auto [a, b, c] = edges[i];
      if (c > max_edge) {
        ans = std::min<int64_t>(ans, std::abs(k - c));
      }
    }
  }
  std::cout << ans << '\n';
}

int main() {
#ifdef __APPLE__
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}