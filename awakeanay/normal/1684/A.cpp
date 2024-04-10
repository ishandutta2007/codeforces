#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();

    if(n == 2) {
      std::cout << s[1] << std::endl;
    }
    else {
      char c = s[0];
      for(int i = 1; i < n; i++)
        c = std::min(c, s[i]);
      std::cout << c << std::endl;
    }
  }

  return 0;
}