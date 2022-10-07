#include <bits/stdc++.h>

const int INF = std::numeric_limits<int>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
  }

  std::vector<std::vector<int>> f(m + 1, std::vector<int>(m + 1, INF));
  f[0][m] = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<std::vector<int>> g(m + 1, std::vector<int>(m + 1, INF));
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= m; ++k) {
        if (f[j][k] < INF) {
          for (int l = 0; l <= k && j + l <= m; ++l) {
            g[j + l][l] = std::min(g[j + l][l], f[j][k] + abs(j - sum[i]));
          }
        }
      }
    }
    f.swap(g);
  }
  std::cout << *std::min_element(f[m].begin(), f[m].end()) << "\n";
}