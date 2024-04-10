#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    std::set<char> S;
    bool ok = true;
    for (int i = 0; i < 6; ++i) {
      if (isupper(s[i]) && !S.count(s[i] ^ 32)) {
        ok = false;
        break;
      }
      S.insert(s[i]);
    }
    if (ok) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}