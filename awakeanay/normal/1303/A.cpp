/*
Author: AwakeAnay
Date: 12/02/2020
Time: 20:07:16
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int start = 0;
    int cur = 0;
    int ans = 0;
    std::string s;
    std::cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
      char c = s[i];
      if(c == '1')
        start = 1;
      if(start && c == '0')
        cur++;
      if(start && c == '1') {
        ans += cur;
        cur = 0;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}