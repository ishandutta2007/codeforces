#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;
    std::vector<std::array<std::pair<int, int>, 2>> f(n + 1);
    for (int i = 0; i < n; ++i) {
      int v = a[i] - '0';
      for (int j = 0; j < 2; ++j) {
        auto tmp = f[i][j];
        tmp.first += v != j;
        f[i + 1][j] = tmp;
        if (!(i & 1)) {
          auto tmp = f[i][!j];
          tmp.first += v != j;
          tmp.second += 1;
          f[i + 1][j] = std::min(f[i + 1][j], tmp);
        }
      }
    }
    auto ans = std::min(f[n][0], f[n][1]);
    std::cout << ans.first << "\n";
  }
}