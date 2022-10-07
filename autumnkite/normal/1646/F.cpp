#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      std::cin >> x;
      --x;
      ++a[i][x];
    }
  }
  std::vector<std::vector<int>> ans;
  while (true) {
    int st = 0;
    while (st < n && *std::min_element(a[st].begin(), a[st].end()) == 1) {
      ++st;
    }
    if (st == n) {
      break;
    }
    std::vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[(st + i) % n][j] > 1) {
          tmp[(st + i) % n] = j;
          --a[(st + i) % n][j];
          ++a[(st + i + 1) % n][j];
          break;
        }
      }
    }
    ans.push_back(tmp);
  }
  while (true) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= a[i][i] == n;
    }
    if (ok) {
      break;
    }
    std::vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
      tmp[i] = (i + n - 1) % n;
      while (!a[i][tmp[i]]) {
        tmp[i] = (tmp[i] + n - 1) % n;
      }
    }
    for (int i = 0; i < n; ++i) {
      --a[i][tmp[i]];
      ++a[(i + 1) % n][tmp[i]];
    }
    ans.push_back(tmp);
  }
  std::cout << ans.size() << "\n";
  for (const auto &p : ans) {
    for (int x : p) {
      std::cout << x + 1 << " ";
    }
    std::cout << "\n";
  }
}