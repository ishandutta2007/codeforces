#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s, t;
    std::cin >> s >> t;

    std::sort(s.begin(), s.end());

    int n = s.length();
    int j = -1, k = -1;
    if(t == "abc" && s[0] == 'a') {
      for(int i = 0; i < n; i++) {
        if(s[i] == 'b') {
          j = i;
          break;
        }
      }
      for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'c') {
          k = i+1;
          break;
        }
      }

      if(j != -1 && k != -1)
        std::reverse(s.begin()+j, s.begin()+k);
      std::cout << s << std::endl;
    }
    else {
      std::cout << s << std::endl;
    }
  }

  return 0;
}