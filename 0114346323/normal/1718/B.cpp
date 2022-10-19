#include <functional>
#include <iterator>
#include <utility>
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
int T, n;
long long a[101];
long long fib[1001], sfib[1001];
void Init() {
  fib[1] = fib[2] = 1;
  for (int i = 3; i <= 70; i++) fib[i] = fib[i - 1] + fib[i - 2];
  std::partial_sum(fib + 1, fib + 71, sfib + 1);
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  long long sum = std::accumulate(a + 1, a + n + 1, 0LL);
  if (!std::binary_search(sfib + 1, sfib + 71, sum)) {
    std::cout << "NO\n";
    return;
  }
  std::multiset<std::pair<long long, int>,
                std::greater<std::pair<long long, int>>>
      s;
  for (int i = 1; i <= n; i++) s.emplace(a[i], i);
  int c = std::lower_bound(sfib + 1, sfib + 71, sum) - sfib;
  for (int i = c, pre = 0; i >= 1; i--) {
    auto [cnt, u] = *s.begin();
    if (cnt < fib[i]) {
      std::cout << "NO\n";
      return;
    }
    if (u == pre) {
      if (s.size() == 1) {
        std::cout << "NO\n";
        return;
      }
      auto it = std::next(s.begin());
      cnt = it->first, u = it->second;
      if (cnt < fib[i]) {
        std::cout << "NO\n";
        return;
      }
      s.erase(it);
      cnt -= fib[i], pre = u;
      if (cnt) s.emplace(cnt, u);
    } else {
      s.erase(s.begin());
      cnt -= fib[i], pre = u;
      if (cnt) s.emplace(cnt, u);
    }
  }
  std::cout << "YES\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  Init();
  std::cin >> T;
  while (T--) Solve();
  return 0;
}