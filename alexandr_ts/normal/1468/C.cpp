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
  int q;
  std::cin >> q;

  std::set<std::pair<int, int>> polycarp;
  std::queue<int> monocarp;
  std::unordered_set<int> served;
  std::vector<int> ans;

  int id = 0;
  for (int iter = 0; iter < q; ++iter) {
    int t;
    std::cin >> t;

    switch (t) {
      case 1: {
        int m;
        std::cin >> m;
        monocarp.push(id);
        polycarp.insert({-m, id});
        ++id;
        break;
      }
      case 2: {
        while (served.count(monocarp.front())) {
          monocarp.pop();
        }
        ans.push_back(monocarp.front());
        monocarp.pop();
        served.insert(ans.back());
        break;
      }
      case 3: {
        while (served.count(polycarp.begin()->second)) {
          polycarp.erase(polycarp.begin());
        }
        ans.push_back(polycarp.begin()->second);
        polycarp.erase(polycarp.begin());
        served.insert(ans.back());
        break;
      }
    }
  }
  for (auto x : ans) {
    std::cout << x + 1 << ' ';
  }
}

int main() {
#ifdef __APPLE__
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  //std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}