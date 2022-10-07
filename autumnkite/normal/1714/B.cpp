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
      --a[i];
    }
    std::vector<bool> vis(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (vis[a[i]]) {
        ans = i + 1;
        break;
      }
      vis[a[i]] = true;
    }
    std::cout << ans << "\n";
  }
}