#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int n, m;
class DisjointSet {
 public:
  DisjointSet() {}
  void Init(int n) { std::iota(fa_ + 1, fa_ + n + 1, 1); }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    fa_[fx] = fy;
    return true;
  }
  ~DisjointSet() {}

 private:
  int fa_[200001];
} dsu;
std::vector<std::pair<int, int>> g[100001];
bool vis[100001];
int lim1, a[100001], b[100001], dep[100001], ch[100001];
std::set<std::pair<int, int>> hc;
void Dfs(int u, int fa) {
  vis[u] = true;
  dep[u] = dep[fa] + 1;
  for (const auto &[v, w] : g[u]) {
    if (v == fa) {
      ch[u]++;
      continue;
    }
    if (!w) {
      if (!vis[v]) {
        lim1++, a[u]++, a[v]++;
        hc.emplace(v, u);
      } else if (!hc.count({u, v}) && dep[v] < dep[u]) {
        b[g[v][ch[v]].first]++, b[u]--;
      }
    } else {
      Dfs(v, u);
    }
    ch[u]++;
  }
}
void Dfs2(int u, int fa) {
  for (const auto &[v, w] : g[u]) {
    if (v == fa || !w) continue;
    a[v] += a[u];
    b[v] += b[u];
    Dfs2(v, u);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> n >> m;
  dsu.Init(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    int w = dsu.Merge(u, v);
    g[u].emplace_back(v, w), g[v].emplace_back(u, w);
  }
  Dfs(1, 0);
  Dfs2(1, 0);
  for (int i = 1; i <= n; i++) std::cout << (a[i] == lim1 && !b[i]);
  return 0;
}