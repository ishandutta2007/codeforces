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
int T, n, k, a[100001], b[100001];
void Solve() {
  std::unordered_map<int, int> mp;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i], mp[a[i]] = i;
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  int cnt = 0, p = 1, pos = mp[b[1]];
  while (p <= n) {
    while (pos + 1 <= n && a[pos + 1] == b[p + 1]) p++, pos++;
    cnt++;
    pos = mp[b[++p]];
  }
  if (cnt <= k)
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