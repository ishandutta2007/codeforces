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
    int done = false;
    for(int i = n-1; i > 0; i--) {
      int u = s[i-1]-'0';
      int v = s[i]-'0';
      if(u + v >= 10) {
        int w = u + v;
        s[i] = '0' + w%10;
        w /= 10;
        s[i-1] = '0' + w%10;
        done = true;
        std::cout << s << std::endl;
        break;
      }
    }

    if(done)
      continue;

    int u = s[0]-'0';
    int v = s[1]-'0';
    std::cout << u+v;
    for(int j = 2; j < n; j++)
      std::cout << s[j];
    std::cout << std::endl;
  }

  return 0;
}