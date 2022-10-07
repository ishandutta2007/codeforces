#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int lim;
    std::cin >> lim;
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> X(n + 1), Y(n + 1);
    for (int i = 0; i < n; ++i) {
      X[i + 1] = X[i], Y[i + 1] = Y[i];
      if (s[i] == 'D') {
        ++X[i + 1];
      } else {
        ++Y[i + 1];
      }
    }
    long long ans = n;
    if (X[n] == 0) {
      ans += lim - Y[n];
    } else if (Y[n] == 0) {
      ans += lim - X[n];
    } else {
      ans += 1ll * (lim - X[n]) * (lim - Y[n]);
    }
    for (int i = 1; i < n; ++i) {
      int limX = lim - X[n] + X[i], limY = lim - Y[n] + Y[i];
      if (Y[i] > 0 && X[i + 1] != X[i]) {
        ans += std::max(limY - Y[i] - 1, 0);
      }
      if (X[i] > 0 && Y[i + 1] != Y[i]) {
        ans += std::max(limX - X[i] - 1, 0);
      }
    }
    std::cout << ans << "\n";
  }
}