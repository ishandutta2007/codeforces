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
int T, n, a[200001];
void Solve() {
  std::cin >> n;
  std::vector<std::vector<int>> pos(n + 1);
  std::vector<std::size_t> cur(n + 1, 0);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
  std::vector<int> ans;
  int now = 0;
  while (true) {
    int p = 0, nxt = 0;
    for (; p <= n; p++) {
      while (cur[p] < pos[p].size() && pos[p][cur[p]] < now) cur[p]++;
      if (cur[p] < pos[p].size())
        checkmax(nxt, pos[p][cur[p]++]);
      else
        break;
    }
    if (p == 0) break;
    ans.push_back(p), now = nxt;
  }
  for (int i = 1; i <= n; i++) {
    while (cur[i] < pos[i].size() && pos[i][cur[i]] < now) cur[i]++;
    for (std::size_t j = cur[i]; j < pos[i].size(); j++) ans.push_back(0);
  }
  std::cout << ans.size() << '\n' << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}