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
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= b[i] == a[i] || b[i] == a[i] + 1;
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}