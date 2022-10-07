#include <bits/stdc++.h>

constexpr long long INF = std::numeric_limits<long long>::max();

void upd(long long &a, long long b) {
  a = std::min(a, b);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<long long> t(n + 1), x(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> t[i] >> x[i];
  }

  std::vector<long long> g(n + 1, INF);
  std::vector<std::vector<bool>> f(n + 1, std::vector<bool>(n + 1));
  g[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] + std::abs(x[i] - x[i + 1]) <= t[i + 1]) {
      for (int j = i + 2; j <= n; ++j) {
        f[i + 1][j] = f[i][j];
      }
    }
    if (g[i] <= t[i]) {
      upd(g[i + 1], std::max(g[i] + std::abs(x[i] - x[i + 1]), t[i]));
      for (int j = i + 2; j <= n; ++j) {
        if (std::max(g[i] + std::abs(x[j] - x[i]), t[i])
            + std::abs(x[j] - x[i + 1]) <= t[i + 1]) {
          f[i + 1][j] = true;
        }
      }
    }
    if (f[i][i + 1] && i + 2 <= n) {
      upd(g[i + 2], std::max(t[i] + std::abs(x[i] - x[i + 2]), t[i + 1]));
      for (int j = i + 3; j <= n; ++j) {
        if (std::max(t[i] + std::abs(x[j] - x[i]), t[i + 1])
            + abs(x[j] - x[i + 2]) <= t[i + 2]) {
          f[i + 2][j] = true;
        }
      }
    }
  }
  if (g[n] <= t[n] || f[n - 1][n]) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}