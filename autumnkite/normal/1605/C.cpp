#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n), b(n), c(n);
    bool ok = false;
    for (int i = 0; i < 7; ++i) {
      for (int j = i; j < n; ++j) {
        a[j] += s[j - i] == 'a';
        b[j] += s[j - i] == 'b';
        c[j] += s[j - i] == 'c';
        if (i > 0 && a[j] > b[j] && a[j] > c[j]) {
          ok = true;
          break;
        }
      }
      if (ok) {
        std::cout << i + 1 << "\n";
        break;
      }
    }
    if (!ok) {
      std::cout << -1 << "\n";
    }
  }
}