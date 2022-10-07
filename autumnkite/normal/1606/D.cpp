#include <bits/stdc++.h>

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> id(n);
  std::iota(id.begin(), id.end(), 0);
  std::sort(id.begin(), id.end(), [&](int x, int y) {
    return a[x][0] < a[y][0];
  });
  std::vector<std::vector<int>> tmp(n);
  for (int i = 0; i < n; ++i) {
    tmp[i] = std::move(a[id[i]]);
  }
  a = std::move(tmp);

  std::vector<std::vector<int>> pmax(a), pmin(a), smax(a), smin(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      pmax[i][j] = std::max(pmax[i][j], pmax[i][j - 1]);
      pmin[i][j] = std::min(pmin[i][j], pmin[i][j - 1]);
    }
    for (int j = m - 2; j >= 0; --j) {
      smax[i][j] = std::max(smax[i][j], smax[i][j + 1]);
      smin[i][j] = std::min(smin[i][j], smin[i][j + 1]);
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 1; i < n; ++i) {
      pmax[i][j] = std::max(pmax[i][j], pmax[i - 1][j]);
      smin[i][j] = std::min(smin[i][j], smin[i - 1][j]);
    }
    for (int i = n - 2; i >= 0; --i) {
      smax[i][j] = std::max(smax[i][j], smax[i + 1][j]);
      pmin[i][j] = std::min(pmin[i][j], pmin[i + 1][j]);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (pmax[i - 1][j - 1] < pmin[i][j - 1] && smax[i][j] < smin[i - 1][j]) {
        std::cout << "YES\n";
        std::string s(n, 'R');
        for (int k = 0; k < i; ++k) {
          s[id[k]] = 'B';
        }
        std::cout << s << " " << j << "\n";
        return;
      }
    }
  }
  std::cout << "NO\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}