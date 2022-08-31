#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();

    bool poss = false;
    for(int i = 0; i <= n; i++) {
      bool cur = true;
      for(int j = 1; j < i; j++) {
        if(s[j-1] == '1' && s[j] == '1')
          cur = false;
      }
      for(int j = 1; j < n-i; j++) {
        if(s[n-j] == '0' && s[n-1-j] == '0')
          cur = false;
      }

      poss |= cur;
    }

    if(poss)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}