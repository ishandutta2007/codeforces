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

    int zero = 0, one = 0;
    int one_zero = 0, zero_one = 0;
    int twice = 0;

    for(int i = 0; i < n; i++) {
      if(s[i] == '0') {
        zero = 1;
        if(i && s[i-1] == '1' && zero_one)
          twice = 1;
      }
      else if(s[i] == '1') {
        one = 1;
        if(zero)
          zero_one = 1;
      }
    }

    if(!zero)
      std::cout << 0 << std::endl;
    else if(!one)
      std::cout << 1 << std::endl;
    else if(!twice)
      std::cout << 1 << std::endl;
    else
      std::cout << 2 << std::endl;
  }

  return 0;
}