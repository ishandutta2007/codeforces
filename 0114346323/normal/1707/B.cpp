// #pragma GCC optimize("O3,unroll-loops")
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
int T, n, a[100001], b[100001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int rem = 0;
  while (n > 1) {
    std::adjacent_difference(a + 1, a + n + 1, b + 1);
    std::copy(b + 2, b + n + 1, a + 1), n--;
    std::sort(a + 1, a + n + 1);
    int p = 0;
    while (p < n && !a[p + 1]) p++;
    if (p == n) {
      std::cout << a[n] << '\n';
      return;
    }
    rem += p;
    if (rem) {
      std::memmove(a + 2, a + p + 1, 4 * (n - p)), a[1] = 0, n = n - p + 1;
      rem--;
    } else {
      std::copy(a + p + 1, a + n + 1, a + 1), n = n - p;
    }
  }
  std::cout << a[n] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}