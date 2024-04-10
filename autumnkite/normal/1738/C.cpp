#include <bits/stdc++.h>

int f[101][101][2];

void init() {
  f[0][0][0] = 1;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (i > 0 && !f[i - 1][j][!((j & 1) ^ k)]) {
          f[i][j][k] = 1;
        }
        if (j > 0 && !f[i][j - 1][!((j & 1) ^ k)]) {
          f[i][j][k] = 1;
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  init();

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int c = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      c += x & 1;
    }
    if (f[n - c][c][0]) {
      std::cout << "Alice\n";
    } else {
      std::cout << "Bob\n";
    }
  }
}