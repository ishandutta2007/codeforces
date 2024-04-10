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
int T, n, a[101], ans;
char s[101];
void Dfs(int now, int s) {
  if (now == n + 1) {
    ans += s;
    return;
  }
  Dfs(now + 1, s * (a[now] + 1));
  if (now + 2 <= n) {
    bool f = !!a[now + 2];
    for (int x = now + 4; x <= n; x += 2) f |= !!a[x];
    if (f) {
      a[now + 2]--;
      for (int x = now + 2; x <= n; x += 2)
        if (a[x] < 0)
          a[x] += 10, a[x + 2]--;
        else
          break;
      Dfs(now + 1, s * (9 - a[now]));
      a[now + 2]++;
      for (int x = now + 2; x <= n; x += 2)
        if (a[x] > 9)
          a[x] -= 10, a[x + 2]++;
        else
          break;
    }
  }
}
void Solve() {
  std::cin >> (s + 1), n = std::strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
  std::reverse(a + 1, a + n + 1);
  ans = 0;
  Dfs(1, 1);
  std::cout << ans - 2 << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}