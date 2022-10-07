#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    ++k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      int v = 1;
      for (int j = 0; j < a[i + 1] - a[i]; ++j) {
        v *= 10;
      }
      v = std::min(v - 1, k);
      k -= v;
      int pw = 1;
      for (int j = 0; j < a[i]; ++j) {
        pw *= 10;
      }
      ans += 1ll * v * pw;
    }
    int pw = 1;
    for (int j = 0; j < a[n - 1]; ++j) {
      pw *= 10;
    }
    ans += 1ll * k * pw;
    std::cout << ans << "\n";
  }
}