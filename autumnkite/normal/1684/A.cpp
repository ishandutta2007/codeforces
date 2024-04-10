#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int n = s.size();
    if (n == 2) {
      std::cout << s[1] << "\n";
    } else {
      std::cout << *std::min_element(s.begin(), s.end()) << "\n";
    }
  }
}