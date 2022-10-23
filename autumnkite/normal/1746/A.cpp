#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int s = std::accumulate(a.begin(), a.end(), 0);
    std::cout << (s > 0 ? "YES\n" : "NO\n");
  }
}