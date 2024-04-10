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
char s[101];
void Solve() {
  std::cin >> n >> (s + 1);
  if (std::count(s + 1, s + n + 1, '?') == n) {
    for (int i = 1; i <= n; i++) std::cout << (i & 1 ? 'R' : 'B');
    std::cout << '\n';
    return;
  }
  char c = 'A';
  for (int i = 1; i <= n; i++)
    if (s[i] == '?') {
      if (c != 'A') {
        if (c == 'R')
          c = 'B';
        else
          c = 'R';
        s[i] = c;
      }
    } else {
      c = s[i];
    }
  c = 'A';
  for (int i = n; i >= 1; i--)
    if (s[i] == '?') {
      if (c != 'A') {
        if (c == 'R')
          c = 'B';
        else
          c = 'R';
        s[i] = c;
      }
    } else {
      c = s[i];
    }
  std::cout << (s + 1) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}