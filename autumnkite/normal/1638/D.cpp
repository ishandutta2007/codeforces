#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto color = [&](int x, int y) {
    int c = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (c == 0 || a[x + i][y + j] == 0 || c == a[x + i][y + j]) {
          c |= a[x + i][y + j];
        } else {
          return 0;
        }
      }
    }
    return c;
  };

  std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
  std::vector<std::pair<int, int>> Q;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (color(i, j)) {
        Q.emplace_back(i, j);
        vis[i][j] = true;
      }
    }
  }
  std::vector<std::tuple<int, int, int>> ans;
  for (int k = 0; k < (int)Q.size(); ++k) {
    auto [x, y] = Q[k];
    int c = color(x, y);
    if (!c) {
      continue;
    }
    ans.emplace_back(x, y, c);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        a[x + i][y + j] = 0;
      }
    }
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        if (0 <= x + i && x + i < n - 1 && 0 <= y + j && y + j < m - 1 &&
            color(x + i, y + j) && !vis[x + i][y + j]) {
          Q.emplace_back(x + i, y + j);
          vis[x + i][y + j] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j]) {
        std::cout << -1 << "\n";
        return 0;
      }
    }
  }
  std::reverse(ans.begin(), ans.end());
  std::cout << ans.size() << "\n";
  for (auto [x, y, c] : ans) {
    std::cout << x + 1 << " " << y + 1 << " " << c << "\n";
  }
}