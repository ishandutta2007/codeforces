#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int o1 = 0, o2 = 0;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '(') {
        o1++;
      }
      else if(s[i] == '[') {
        o2++;
      }
      else if(s[i] == ')') {
        if(o1) {
          ans++;
          o1--;
        }
      }
      else {
        if(o2) {
          ans++;
          o2--;
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}