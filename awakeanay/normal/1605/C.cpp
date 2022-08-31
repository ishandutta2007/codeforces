#include <iostream>

#define int long long

int check(std::string s) {
  int c[3];
  c[0] = c[1] = c[2] = 0;
  for(char t : s) {
    c[t-'a']++;
  }
  return c[0] > c[1] && c[0] > c[2];
}

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

    bool done = false;
    for(int i = 2; i <= 15; i++) {
      for(int j = 0; j+i <= n; j++) {
        if(check(s.substr(j, i))) {
          std::cout << i << std::endl;
          done = true;
          break;
        }
      }
      if(done)
        break;
    }
    
    if(done)
      continue;

    std::cout << -1 << std::endl;
  }

  return 0;
}