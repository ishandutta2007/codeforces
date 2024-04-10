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
int T, n;
char s[20001];
void Solve() {
  std::cin >> n >> (s + 1);
  if (!std::count(s + 1, s + n + 1, '0')) {
    std::cout << "1 " << n / 2 << ' ' << n - n / 2 + 1 << ' ' << n << '\n';
    return;
  }
  int fp = 0, lp = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '0') {
      fp = i;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (s[i] == '0') lp = i;
  if (n - fp >= n / 2 && fp < n) {
    std::cout << fp << ' ' << n << ' ' << fp + 1 << ' ' << n << '\n';
    return;
  }
  if (lp - 1 >= n / 2 && lp > 1) {
    std::cout << "1 " << lp << " 1 " << lp - 1 << '\n';
    return;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}