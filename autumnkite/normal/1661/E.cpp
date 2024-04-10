#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(3, std::vector<int>(n));
  for (int i = 0; i < 3; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; ++j) {
      a[i][j] = s[j] - '0';
    }
  }

  std::vector<int> s0(n + 1);
  for (int i = 0; i < n; ++i) {
    int v = a[0][i] + a[1][i] + a[2][i];
    v -= (a[0][i] & a[1][i]) + (a[1][i] & a[2][i]);
    s0[i + 1] = s0[i] + v;
  }
  std::vector<int> s1(n);
  for (int i = 0; i + 1 < n; ++i) {
    int x = a[0][i] & a[0][i + 1];
    int y = a[1][i] & a[1][i + 1];
    int z = a[2][i] & a[2][i + 1];
    int v = x + y + z - (x & y) - (y & z);
    s1[i + 1] = s1[i] + v;
  }

  std::vector<int> L(n), R(n);
  for (int i = 0, j = 0; i < n; i = j) {
    if (a[0][i] && a[1][i] && a[2][i]) {
      j = i + 1;
      while (j < n && a[0][j] && !a[1][j] && a[2][j]) {
        ++j;
      }
      if (i + 1 < j && j < n && a[0][j] && a[1][j] && a[2][j]) {
        ++L[i + 1], ++R[j];
      }
    } else {
      j = i + 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    L[i] += L[i - 1];
    R[i] += R[i - 1];
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l, --r;
    std::cout << s0[r + 1] - s0[l] - s1[r] + s1[l] + std::max(0, R[r] - L[l])
              << "\n";
  }
}