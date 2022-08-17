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
    int ct = 0;
    for(int i = 0; i < n; i++)
      ct += s[i] == 'E';

    if(ct == n-1)
      std::cout << "NO" << std::endl;
    else
      std::cout << "YES" << std::endl;
  }

  return 0;
}