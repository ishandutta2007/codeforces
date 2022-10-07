#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> a[i];
      --a[i];
    }
    std::sort(a.begin(), a.end());
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      b[i] = (a[(i + 1) % m] - a[i] - 1 + n) % n;
    }
    std::sort(b.begin(), b.end(), std::greater<int>());
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      if (b[i] <= 4 * i) {
        break;
      }
      if (b[i] == 4 * i + 1) {
        ++ans;
        break;
      }
      ans += b[i] - 4 * i - 1;
    }
    std::cout << n - ans << "\n";
  }
}