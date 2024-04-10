#include <iostream>
#include <algorithm>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end());

    std::cout << s << std::endl;
  }

  return 0;
}