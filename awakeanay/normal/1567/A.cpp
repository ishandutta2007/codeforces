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

    for(int i = 0; i < n; i++) {
      if(s[i] == 'U')
        s[i] = 'D';
      else if(s[i] == 'D')
        s[i] = 'U';
    }

    std::cout << s << std::endl;
  }

  return 0;
}