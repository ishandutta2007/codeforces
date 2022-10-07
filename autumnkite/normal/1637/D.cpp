#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int S = 0, S2 = 0;
    for (int &x : a) {
      std::cin >> x;
      S += x;
      S2 += x * x;
    }
    for (int &x : b) {
      std::cin >> x;
      S += x;
      S2 += x * x;
    }
    std::bitset<10001> f;
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
      f = f << a[i] | f << b[i];
    }
    int ans = S * S;
    for (int i = 0; i <= S; ++i) {
      if (f[i]) {
        ans = std::min(ans, i * i + (S - i) * (S - i));
      }
    }
    std::cout << ans + (n - 2) * S2 << "\n";
  }
}