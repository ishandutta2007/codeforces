#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string a, b;
    std::cin >> a >> b;


    int ans = a.size() + b.size();

    int p = a.size(), q = b.size();

    for(int i = 0; i < p; i++) {
      for(int j = i; j < p; j++) {
        for(int k = 0; k < q; k++) {
          bool poss = true;
          if(k+j-i >= q) {
            poss = false;
            break;
          }
          for(int l = k; l <= k+j-i; l++) {
            if(a[i+l-k] != b[l]) {
              poss = false;
              break;
            }
          }
          if(poss)
            ans = std::min(ans, p+q-2*(j-i+1));
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}