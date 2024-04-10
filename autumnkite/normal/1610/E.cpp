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
    int ans = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && a[i] == a[j]) {
        ++j;
      }
      if (j == n) {
        ans = std::max(ans, j - i);
      } else {
        int now = a[j];
        int cnt = j - i + 1;
        while (1) {
          auto it = std::lower_bound(a.begin(), a.end(), now + now - a[i]);
          if (it != a.end()) {
            now = *it;
            ++cnt;
          } else {
            break;
          }
        }
        ans = std::max(ans, cnt);
      }
    }
    std::cout << n - ans << "\n";
  }
}