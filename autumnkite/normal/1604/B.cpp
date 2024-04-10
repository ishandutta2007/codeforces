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
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      ok &= a[i - 1] < a[i];
    }
    if (n & 1 && ok) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}