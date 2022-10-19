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
int T, n, L[50001], s[50001], top;
long long a[50001], sum[50001], dp[50001], f[50001];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int x;
  std::cin >> x;
  for (int i = 1; i <= n; i++) a[i] -= x;
  std::partial_sum(a + 1, a + n + 1, sum + 1);
  top = 0;
  std::iota(L + 1, L + n + 1, 1);
  for (int i = 2; i <= n; i++) {
    while (top && sum[s[top]] <= sum[i - 2]) top--;
    s[++top] = i - 2;
    int l = 1, r = top, best = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (sum[s[mid]] > sum[i])
        best = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (best == -1)
      L[i] = 1;
    else
      L[i] = s[best] + 2;
    checkmax(L[i], L[i - 1]);
  }
  std::memset(dp, 0, sizeof(dp));
  dp[1] = 1, f[1] = -1;
  s[top = 1] = 1;
  for (int i = 2; i <= n; i++) {
    int p = std::lower_bound(s + 1, s + top + 1, L[i]) - s;
    if (p <= top) {
      dp[i] = std::max(dp[i - 1], f[s[p]] + i + 1);
    } else {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + 1);
    }
    f[i] = dp[i - 2] - i;
    while (top && f[s[top]] <= f[i]) top--;
    s[++top] = i;
  }
  std::cout << dp[n] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}