#include <bits/stdc++.h>

constexpr int INF = std::numeric_limits<int>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int k = 0; k < 2; ++k) {
      for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        a[i] |= (c == '*') << k;
      }
    }

    auto solve = [&](std::vector<int> a) {
      int n = a.size();
      std::vector<std::vector<int>> f(n + 1, std::vector<int>(4, INF));
      f[0][0] = 0;
      for (int i = 0; i < n; ++i) {
        for (int S = 0; S < 4; ++S) {
          f[i + 1][a[i] | S] = std::min(f[i + 1][a[i] | S],
                                        f[i][S] + (S & 1) + (S >> 1 & 1));
        }
        f[i + 1][1] = std::min(f[i + 1][1], f[i + 1][3] + 1);
        f[i + 1][2] = std::min(f[i + 1][2], f[i + 1][3] + 1);
      }
      return f;
    };

    auto f = solve(a);
    std::reverse(a.begin(), a.end());
    auto g = solve(a);
    int ans = INF;
    for (int i = 0; i < n; ++i) {
      ans = std::min(ans, f[i + 1][1] + g[n - i][1]);
      ans = std::min(ans, f[i + 1][2] + g[n - i][2]);
      ans = std::min(ans, f[i + 1][3] + g[n - i][3] + 1);
    }
    std::cout << ans << "\n";
  }
}