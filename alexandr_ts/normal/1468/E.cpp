#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <queue>

#define CHECK_IMPL1(cond)                \
    if (!(cond)) {                       \
      DEBUG("expected cond: " << #cond); \
      assert(cond);                      \
    }

#define CHECK_IMPL2(cond, message)                                              \
    if (!(cond)) {                                                              \
      DEBUG("expected cond: " << #cond << " failed with message: " << message); \
      assert(cond);                                                             \
    }

#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __APPLE__
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

void solve() {
  std::vector<int> a(4);
  for (int i = 0; i < 4; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::cout << a[0] * a[2] << '\n';
}

int main() {
#ifdef __APPLE__
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}