#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
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
int T, k;
long long n, m, a[100001], b[100001];
void Solve() {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) std::cin >> a[i], b[i] = a[i] / m;
  std::sort(b + 1, b + k + 1, std::greater<>());
  long long s = 0LL;
  for (int i = 1; i <= k && b[i] >= 2; i++) {
    if (s + b[i] < n) {
      s += b[i];
    } else if (s + b[i] == n) {
      std::cout << "Yes\n";
      return;
    } else {
      if (s == n - 1) {
        if (b[1] > 2) {
          std::cout << "Yes\n";
          return;
        }
      } else {
        std::cout << "Yes\n";
        return;
      }
      break;
    }
  }
  std::swap(n, m);
  for (int i = 1; i <= k; i++) b[i] = a[i] / m;
  std::sort(b + 1, b + k + 1, std::greater<>());
  s = 0LL;
  for (int i = 1; i <= k && b[i] >= 2; i++) {
    if (s + b[i] < n) {
      s += b[i];
    } else if (s + b[i] == n) {
      std::cout << "Yes\n";
      return;
    } else {
      if (s == n - 1) {
        if (b[1] > 2) {
          std::cout << "Yes\n";
          return;
        }
      } else {
        std::cout << "Yes\n";
        return;
      }
      break;
    }
  }
  std::cout << "No\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}