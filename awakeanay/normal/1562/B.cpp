#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);


  std::vector<int> pr(100, 1);
  pr[1] = 0;

  for(int i = 2; i < 100; i++) {
    if(pr[i]) {
      for(int j = 2*i; j < 100; j+=i)
        pr[j] = 0;
    }
  }

  int t;
  std::cin >> t;

  while(t--) {
    int k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    int done = 0;
    for(int i = 0; i < k; i++) {
      if(!pr[s[i]-'0']) {
        std::cout << 1 << std::endl;
        std::cout << s[i] << std::endl;
        done = 1;
        break;
      }
    }

    if(!done) {
      for(int i = 0; i < k && (!done); i++) {
        for(int j = i+1; j < k && (!done); j++) {
          int cur = (s[i]-'0')*10 + s[j]-'0';
          if(!pr[cur]) {
            std::cout << 2 << std::endl;
            std::cout << cur << std::endl;
            done = 1;
          }
        }
      }
    }
  }

  return 0;
}