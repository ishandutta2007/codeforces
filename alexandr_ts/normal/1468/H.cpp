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
  int n, k, m;
  std::cin >> n >> k >> m;
  std::vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
    --b[i];
  }

  if ((n - m) % (k - 1) != 0) {
    std::cout << "NO" << '\n';
    return;
  }

  std::vector<int> u;
  for (int i = 0; i < n; ++i) {
    if (!std::binary_search(b.begin(), b.end(), i)) {
      u.push_back(i);
    }
  }
  CHECK((int)u.size() == n - m);

  std::vector<int> a = {1};
  for (size_t i = 1; i < u.size(); ++i) {
    if (u[i - 1] + 1 == u[i]) {
      a.back() += 1;
    } else {
      a.push_back(1);
    }
  }

  int64_t total_sum = std::accumulate(a.begin(), a.end(), 0LL);;
  int64_t lhs = 0;
  for (size_t i = 0; i + 1 < a.size(); ++i) {
    lhs += a[i];
    auto rhs = total_sum - lhs;

    auto B = std::min(lhs, rhs);
    DEBUG(lhs << " " << rhs);

    if (B >= (k - 1) / 2) {
      std::cout << "YES" << '\n';
      return;
    }
  }
  std::cout << "NO" << '\n';
}

int main() {
#ifdef __APPLE__
  freopen("input.txt", "r", stdin);
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