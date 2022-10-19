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
int T, a, b;
void Solve() {
  std::cin >> a >> b;
  int x = a - 1, xo;
  switch (x % 4) {
    case 0:
      xo = x;
      break;
    case 1:
      xo = 1;
      break;
    case 2:
      xo = x + 1;
      break;
    default:
      xo = 0;
      break;
  }
  if (xo == b) {
    std::cout << a << '\n';
  } else if ((xo ^ b) == a) {
    std::cout << a + 2 << '\n';
  } else {
    std::cout << a + 1 << '\n';
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}