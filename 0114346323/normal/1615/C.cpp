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
int T, n;
void Solve() {
  std::string s, t;
  std::cin >> n >> s >> t;
  if (s == t) {
    std::cout << "0\n";
    return;
  }
  int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && t[i] == '0') c00++;
    if (s[i] == '0' && t[i] == '1') c01++;
    if (s[i] == '1' && t[i] == '0') c10++;
    if (s[i] == '1' && t[i] == '1') c11++;
  }
  int ans = 0x3f3f3f3f;
  if (c10 == c01) checkmin(ans, c10 + c01);
  if (c11 == c00 + 1) checkmin(ans, c00 + c11);
  if (ans == 0x3f3f3f3f) ans = -1;
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}