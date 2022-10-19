#include <vector>
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
int T, n, k, m;
void Solve() {
  std::cin >> n >> k;
  std::vector<std::pair<int, long long>> A, B;
  for (int i = 1; i <= n; i++) {
    int x, cnt = 1;
    std::cin >> x;
    while (x % k == 0) x /= k, cnt *= k;
    if (!A.empty() && A.back().first == x)
      A.back().second += cnt;
    else
      A.emplace_back(x, cnt);
  }
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, cnt = 1;
    std::cin >> x;
    while (x % k == 0) x /= k, cnt *= k;
    if (!B.empty() && B.back().first == x)
      B.back().second += cnt;
    else
      B.emplace_back(x, cnt);
  }
  if (A == B)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}