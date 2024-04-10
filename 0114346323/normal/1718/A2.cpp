#include <functional>
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
int T, n, a[100001], b[100001], f[100001];
void Solve() {
  std::cin >> n;
  std::fill(f + 1, f + n + 1, 0x3f3f3f3f);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::partial_sum(a + 1, a + n + 1, b + 1, std::bit_xor());
  std::map<int, int> mp;
  mp[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + 1;
    if (mp.count(b[i])) {
      int j = mp[b[i]];
      checkmin(f[i], f[j] + i - j - 1);
    }
    mp[b[i]] = i;
  }
  std::cout << f[n] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}