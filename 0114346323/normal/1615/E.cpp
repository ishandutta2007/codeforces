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
int n, k, l[200001], son[200001], fa[200001];
std::vector<int> g[200001], lk;
void Dfs(int u, int f) {
  l[u] = 1, fa[u] = f;
  for (auto &&v : g[u]) {
    if (v == f) continue;
    Dfs(v, u), checkmax(l[u], l[v] + 1);
    if (l[v] > l[son[u]]) son[u] = v;
  }
}
void Dfs2(int u, int t) {
  if (u == t) lk.push_back(l[u]);
  if (son[u]) Dfs2(son[u], t);
  for (auto &&v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    Dfs2(v, v);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  Dfs(1, 0);
  Dfs2(1, 1);
  std::sort(lk.begin(), lk.end(), std::greater<int>());
  int r = std::min(k, n / 2);
  checkmin(k, static_cast<int>(lk.size()));
  int b = n;
  for (int i = 0; i < k; i++) b -= lk[i];
  checkmin(b, n / 2);
  if (k < n / 2) checkmax(k, r);
  std::cout << static_cast<long long>(n - k - b) * (k - b);
  return 0;
}