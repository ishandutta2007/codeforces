#include <iostream>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  for(int i = 1; i < n; i++) {
    if(s[i-1] > s[i]) {
      std::cout << "YES" << std::endl;
      std::cout << i << " " << i+1 << std::endl;
      return 0;
    }
  }

  std::cout << "NO" << std::endl;

  return 0;
}