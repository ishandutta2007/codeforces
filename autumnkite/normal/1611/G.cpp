#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> s[i];
    }
    std::vector<std::pair<int, int>> c[2];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '1') {
          c[(i + j) & 1].emplace_back(i + j, i - j);
        }
      }
    }
    int ans = 0;
    for (int p = 0; p < 2; ++p) {
      std::sort(c[p].begin(), c[p].end());
      std::vector<int> v;
      for (auto [x, y] : c[p]) {
        v.emplace_back(-y);
      }
      std::sort(v.begin(), v.end());
      v.erase(std::unique(v.begin(), v.end()), v.end());
      std::vector<int> a;
      for (auto [x, y] : c[p]) {
        a.emplace_back(std::lower_bound(v.begin(), v.end(), -y) - v.begin());
      }
      std::vector<int> sta(a.size() + 1, v.size());
      int max = 0;
      sta[0] = -1;
      for (int x : a) {
        int f = std::lower_bound(sta.begin(), sta.end(), x) - sta.begin();
        max = std::max(max, f);
        sta[f] = x;
      }
      ans += max;
    }
    std::cout << ans << "\n";
  }
}