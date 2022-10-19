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
constexpr int kDx[] = {1, 0, -1, 0}, kDy[] = {0, 1, 0, -1};
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
int T, n, a[1001][1001], c[1001][1001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) std::cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) c[i][j] = 0;
  int ans = 0;
  auto rev = [&](int x, int y) {
    for (int i = 0; i < 4; i++) {
      int tx = x + kDx[i], ty = y + kDy[i];
      if (tx >= 1 && tx <= n && ty >= 1 && ty <= n) c[tx][ty] ^= 1;
    }
    ans ^= a[x][y];
  };
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n; j++)
      if (c[i][j] == 0) rev(i + 1, j);
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}