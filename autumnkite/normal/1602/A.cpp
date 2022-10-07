#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    auto it = std::min_element(s.begin(), s.end());
    char a = *it;
    s.erase(it);
    std::cout << a << " " << s << "\n";
  }
}