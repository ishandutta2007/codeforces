#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();

    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(i+2 < n && s[i] == s[i+1] && s[i+1] == s[i+2]) {
        ans += 2;
        i += 2;
      }
      else if(i+1 < n && s[i] == s[i+1]) {
        ans += 1;
        i += 1;
      }
      else if(i+2 < n && s[i] == s[i+2]) {
        s[i+2] = i%6;
        ans++;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}