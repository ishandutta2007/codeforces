#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      ++cnt[x];
    }
    std::set<std::pair<int, int>> bad;
    for (int i = 0; i < m; ++i) {
      int x, y;
      std::cin >> x >> y;
      bad.emplace(x, y);
      bad.emplace(y, x);
    }
    std::map<int, std::vector<int>> mp;
    for (auto [x, c] : cnt) {
      mp[c].push_back(x);
    }
    for (auto &[x, xv] : mp) {
      std::reverse(xv.begin(), xv.end());
    }
    long long ans = 0;
    for (auto &[x, xv] : mp) {
      for (auto &[y, yv] : mp) {
        if (x >= y) {
          for (int i : xv) {
            for (int j : yv) {
              if (i != j && !bad.count(std::make_pair(i, j))) {
                ans = std::max(ans, 1ll * (x + y) * (i + j));
                break;
              }
            }
          }
        }
      }
    }
    std::cout << ans << "\n";
  }
}