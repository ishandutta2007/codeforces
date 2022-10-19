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
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n;
long long Query(int l, int r) {
  std::cout << "? " << l << ' ' << r << std::endl;
  long long res;
  std::cin >> res;
  return res;
}
void Solve() {
  std::cin >> n;
  long long tot = Query(1, n);
  long long l = 1, r = n, L = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Query(1, mid) > 0) {
      L = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  L--;
  long long s = Query(L + 1, n), len = tot - s;
  long long md = L + len + 1;
  tot -= (md - L) * (md - L - 1) / 2;
  long long kj = (std::sqrt(8.0L * tot + 1) - 1) / 2;
  long long k = md + kj;
  std::cout << "! " << L << ' ' << md << ' ' << k << std::endl;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}