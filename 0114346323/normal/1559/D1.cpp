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
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m1, m2;
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
  bool Check(int x, int y) {
    x = Find(x), y = Find(y);
    return x == y;
  }
  ~DisjointSet() {}

 private:
  int fa_[100001];
} T1, T2;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m1 >> m2;
  T1.Init(n), T2.Init(n);
  for (int i = 1; i <= m1; i++) {
    int u, v;
    std::cin >> u >> v;
    T1.Merge(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    std::cin >> u >> v;
    T2.Merge(u, v);
  }
  std::vector<std::pair<int, int>> ans;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!T1.Check(i, j) && !T2.Check(i, j)) {
        ans.emplace_back(i, j);
        T1.Merge(i, j), T2.Merge(i, j);
      }
  std::cout << ans.size() << '\n';
  for (auto &&[u, v] : ans) std::cout << u << ' ' << v << '\n';
  return 0;
}