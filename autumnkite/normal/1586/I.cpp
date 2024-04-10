#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  if (n & 1) {
    std::cout << "NONE\n";
    return 0;
  }
  std::vector<std::vector<int>> X(n, std::vector<int>(n));
  std::vector<std::vector<int>> Y(n, std::vector<int>(n));
  std::vector<std::array<bool, 2>> ok(n / 2, {true, true});
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x, y;
      if ((i + j) & 1) {
        if (i > j) {
          x = (i - j - 1) / 2;
          y = (i + x + 1) & 1;
        } else {
          x = (j - i - 1) / 2;
          y = (i + x) & 1;
        }
      } else {
        if (i + j < n) {
          x = (i + j) / 2;
          y = (i + x) & 1;
        } else {
          x = n - (i + j) / 2 - 1;
          y = (i + x + 1) & 1;
        }
      }
      if (a[i][j] != '.') {
        ok[x][y ^ (a[i][j] == 'S')] = false;
      }
      X[i][j] = x;
      Y[i][j] = y;
    }
  }
  for (int i = 0; i < n / 2; ++i) {
    if (!ok[i][0] && !ok[i][1]) {
      std::cout << "NONE\n";
      return 0;
    }
  }
  for (int i = 0; i < n / 2; ++i) {
    if (ok[i][0] && ok[i][1]) {
      std::cout << "MULTIPLE\n";
      return 0;
    }
  }
  std::cout << "UNIQUE\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = X[i][j], y = Y[i][j];
      if (y ^ ok[x][0]) {
        std::cout << 'S';
      } else {
        std::cout << 'G';
      }
    }
    std::cout << "\n";
  }
}