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

    std::string s;
    std::cin >> s;

    int min = n/2;
    int done = 0;
    for(int i = 1; i <= n; i++) {
      if(i-1 >= min && s[i-1] == '0') {
        std::cout << 1 << " " << i << " " << 1 << " " << i-1 << std::endl;
        done = 1;
        break;
      }
    }

    if(done)
      continue;

    for(int i = 1; i <= n; i++) {
      if(n-i >= min && s[i-1] == '0') {
        std::cout << i << " " << n << " " << i+1 << " " << n << std::endl;
        done = 1;
        break;
      }
    }

    if(done)
      continue;

    std::cout << 1 << " " << 2*min << " " << 1 << " " << min << std::endl;
  }

  return 0;
}