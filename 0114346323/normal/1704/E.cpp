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
#include <vector>
constexpr int kMod = 998244353;
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
int T, n, m, deg[1001], d[1001];
long long a[1001];
std::vector<int> g[1001];
int b[1001];
bool vis[1001];
void Add(int &x, int y) {
  if ((x += y) >= kMod) x -= kMod;
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) g[i].clear();
  std::fill(deg + 1, deg + n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].emplace_back(v), deg[v]++;
  }
  for (int T = 1; T <= 2 * n; T++) {
    for (int i = 1; i <= n; i++) vis[i] = !!a[i];
    bool f = false;
    for (int i = 1; i <= n; i++)
      if (vis[i]) {
        f = true;
        a[i]--;
        for (const auto j : g[i]) a[j]++;
      }
    if (!f) {
      std::cout << T - 1 << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!a[i])
      for (const auto j : g[i]) deg[j]--;
  std::queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!deg[i] && a[i]) q.emplace(i);
  for (int i = 1; i <= n; i++) b[i] = a[i] % kMod;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (const auto v : g[u]) {
      Add(b[v], b[u]);
      if (!--deg[v]) q.emplace(v);
    }
  }
  int p = 0;
  for (int i = 1; i <= n; i++)
    if (g[i].empty()) {
      p = i;
      break;
    }
  std::cout << (b[p] + 2 * n) % kMod << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}