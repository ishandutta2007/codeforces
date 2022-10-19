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
int p[200001], tot;
bool np[200001];
void Init(int n) {
  np[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p[++tot] = i;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      np[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
int T;
long long n;
void Solve() {
  __int128_t k = 1LL;
  std::cin >> n;
  __int128_t t = n;
  while (~t & 1) k *= 2, t >>= 1;
  k *= 2;
  if (k * (k + 1) / 2 <= n) {
    std::cout << k << '\n';
    return;
  }
  if (t != 1 && t * (t + 1) / 2 <= n) {
    std::cout << t << '\n';
    return;
  }
  for (int i = 1; p[i] * p[i] <= t; i++) {
    if (t % p[i] == 0) {
      if (p[i] * (p[i] + 1) / 2 <= n) {
        std::cout << p[i] << '\n';
        return;
      } else {
        std::cout << "-1\n";
        return;
      }
    }
  }
  std::cout << "-1\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(200000);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}