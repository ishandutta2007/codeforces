#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int k = std::accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    for (int i = 0; i < n - k; ++i) {
      ans += a[i];
    }
    std::cout << ans << "\n";
  }
}