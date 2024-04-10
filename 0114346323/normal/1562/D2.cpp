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
int T, n, q, sum[300001];
char s[300001];
std::vector<int> p[600001];
void Solve() {
  std::cin >> n >> q >> (s + 1);
  for (int i = 1; i <= n; i++) {
    if ((i & 1) && s[i] == '+') sum[i] = sum[i - 1] + 1;
    if ((i & 1) && s[i] == '-') sum[i] = sum[i - 1] - 1;
    if (!(i & 1) && s[i] == '+') sum[i] = sum[i - 1] - 1;
    if (!(i & 1) && s[i] == '-') sum[i] = sum[i - 1] + 1;
    p[sum[i] + n].emplace_back(i);
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (!((r - l) & 1)) {
      std::cout << "1\n";
      int d = sum[r] - sum[l - 1];
      if (d > 0)
        d = (d + 1) / 2;
      else
        d = (d - 1) / 2;
      d += sum[l - 1] + n;
      std::cout << *std::lower_bound(p[d].begin(), p[d].end(), l) << '\n';
    } else {
      std::cout << (sum[r] - sum[l - 1] ? "2\n" : "0\n");
      if (sum[r] - sum[l - 1]) {
        std::cout << l++ << ' ';
        int d = sum[r] - sum[l - 1];
        if (d > 0)
          d = (d + 1) / 2;
        else
          d = (d - 1) / 2;
        d += sum[l - 1] + n;
        std::cout << *std::lower_bound(p[d].begin(), p[d].end(), l) << '\n';
      }
    }
  }
  for (int i = 1; i <= n; i++) p[sum[i] + n].clear();
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}