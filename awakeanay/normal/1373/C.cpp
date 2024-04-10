#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int ans = 0;
    int cur = 0;
    int max = 0;

    for(int i = 0; i < n; i++) {
      if(s[i] == '+')
        cur--;
      else
        cur++;
      if(cur > max) {
        ans += i+1;
        max = cur;
      }
    }

    std::cout << ans + n << std::endl;
  }

  return 0;
}