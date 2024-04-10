#include <cstddef>
#include <functional>
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
int T, n, q;
long long a[200001], sum[11][200001];
bool np[200001];
std::vector<int> pd[200001];
void Init(int n) {
  np[1] = true;
  int sq = 500;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) {
      for (int j = i; j <= n; j += i) pd[j].emplace_back(i);
      if (i <= sq)
        for (int j = i * i; j <= n; j += i) np[j] = true;
    }
  }
}
void Solve() {
  std::cin >> n >> q;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int cnt = 0;
  std::multiset<long long, std::greater<long long>> s;
  for (const auto len : pd[n]) {
    int d = n / len;
    std::fill(sum[cnt], sum[cnt] + d, 0LL);
    for (int i = 0; i < d; i++) {
      for (int j = i; j < n; j += d) sum[cnt][i] += a[j];
      s.emplace(d * sum[cnt][i]);
    }
    cnt++;
  }
  std::cout << *s.begin() << '\n';
  while (q--) {
    int p;
    long long x;
    std::cin >> p >> x, p--;
    for (std::size_t i = 0; i < pd[n].size(); i++) {
      int len = pd[n][i], d = n / len;
      s.erase(s.find(d * sum[i][p % d]));
      sum[i][p % d] += x - a[p];
      s.emplace(d * sum[i][p % d]);
    }
    a[p] = x;
    std::cout << *s.begin() << '\n';
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  Init(200000);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}