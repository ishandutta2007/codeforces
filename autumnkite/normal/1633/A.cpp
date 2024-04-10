#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;

    auto check = [&](std::string s) {
      if (s[0] == '0') {
        return false;
      }
      int res = 0;
      for (char c : s) {
        res = (res * 10 + c - '0') % 7;
      }
      return res == 0;
    };

    if (check(s)) {
      std::cout << s << "\n";
      continue;
    }
    bool ok = false;
    for (int i = 0; i < (int)s.size() && !ok; ++i) {
      for (int j = 0; j <= 9 && !ok; ++j) {
        auto t = s;
        t[i] = j + '0';
        if (check(t)) {
          std::cout << t << "\n";
          ok = true;
        }
      }
    }
  }
}