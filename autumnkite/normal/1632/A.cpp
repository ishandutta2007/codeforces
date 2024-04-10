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
    if (n >= 3) {
      std::cout << "NO\n";
    } else if (n == 1) {
      std::cout << "YES\n";
    } else if (s[0] == s[1]) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}