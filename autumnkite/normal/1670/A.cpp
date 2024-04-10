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
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      cnt += a[i] < 0;
    }
    for (int i = 0; i < cnt; ++i) {
      a[i] = -abs(a[i]);
    }
    for (int i = cnt; i < n; ++i) {
      a[i] = abs(a[i]);
    }
    std::cout << (std::is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
  }
}