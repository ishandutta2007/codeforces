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
std::string s[100001], t[100001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> s[i];
  for (int i = 1; i <= n; i++) t[i] = s[i];
  for (int i = 1; i <= n; i++) std::reverse(t[i].begin(), t[i].end());
  for (int i = 1; i <= n; i++) {
    if (s[i].size() == 1) {
      std::cout << "YES\n";
      return;
    }
    if (s[i].size() == 2 && s[i][0] == s[i][1]) {
      std::cout << "YES\n";
      return;
    }
    if (s[i].size() == 3 && s[i][0] == s[i][2]) {
      std::cout << "YES\n";
      return;
    }
  }
  std::set<std::string> mp;
  for (int i = 1; i <= n; i++) {
    if (mp.count(t[i])) {
      std::cout << "YES\n";
      return;
    }
    mp.emplace(s[i]);
  }
  mp.clear();
  for (int i = 1; i <= n; i++) {
    if (s[i].size() == 2) {
      mp.emplace(t[i]);
    } else if (mp.count(s[i].substr(1))) {
      std::cout << "YES\n";
      return;
    }
  }
  mp.clear();
  for (int i = 1; i <= n; i++) {
    if (s[i].size() == 3) {
      mp.emplace(s[i].substr(0, 2));
    } else if (mp.count(t[i])) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}