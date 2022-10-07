#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    bool ok = true;
    int now = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == 'A') {
        ++now;
      } else {
        --now;
      }
      ok &= now >= 0;
    }
    ok &= s.back() == 'B';
    if (ok) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}