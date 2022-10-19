#include <algorithm>
#include <cmath>
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
constexpr double kEps = 1e-6;
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
int T, n;
double a[71], b[71];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x, a[i] = x;
  }
  if (n == 1) {
    std::cout << "0\n";
    return;
  }
  int ans = n;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double d = (a[j] - a[i]) / (j - i);
      for (int k = 1; k <= n; k++) b[k] = a[i] + (k - i) * d;
      int cnt = 0;
      for (int k = 1; k <= n; k++) cnt += std::fabs(b[k] - a[k]) > kEps;
      checkmin(ans, cnt);
    }
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}