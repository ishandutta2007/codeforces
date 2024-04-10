#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
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
    if (T1.Find(i) != T1.Find(1) && T2.Find(i) != T2.Find(1)) {
      ans.emplace_back(1, i);
      T1.Merge(1, i), T2.Merge(1, i);
    }
  std::vector<int> v1, v2;
  for (int i = 1; i <= n; i++)
    if (T1.Find(i) != T1.Find(1)) {
      v1.emplace_back(i);
      T1.Merge(1, i);
    }
  for (int i = 1; i <= n; i++)
    if (T2.Find(i) != T2.Find(1)) {
      v2.emplace_back(i);
      T2.Merge(1, i);
    }
  std::cout << ans.size() + std::min(v1.size(), v2.size()) << '\n';
  for (auto &&[u, v] : ans) std::cout << u << ' ' << v << '\n';
  for (std::size_t i = 0; i < v1.size() && i < v2.size(); i++)
    std::cout << v1[i] << ' ' << v2[i] << '\n';
  return 0;
}