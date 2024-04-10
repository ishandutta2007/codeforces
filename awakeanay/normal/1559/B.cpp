#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int first = -1;
    std::string s;
    std::cin >> s;

    for(int i = 0; i < n; i++) {
      if(s[i] == 'R' || s[i] == 'B')
        first = i;
    }

    if(first == -1) {
      for(int i = 0; i < n; i++)
        std::cout << ((i%2) ? 'B' : 'R');
      std::cout << std::endl;
    }
    else {
      for(int i = first+1; i < n; i++) {
        if(s[i] == '?') {
          if(s[i-1] == 'R')
            s[i] = 'B';
          else
            s[i] = 'R';
        }
      }
      for(int i = first-1; i >= 0; i--) {
        if(s[i] == '?') {
          if(s[i+1] == 'R')
            s[i] = 'B';
          else
            s[i] = 'R';
        }
      }
      std::cout << s << std::endl;
    }
  }

  return 0;
}