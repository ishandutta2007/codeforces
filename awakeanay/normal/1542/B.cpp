#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, a, b;
    std::cin >> n >> a >> b;

    bool poss = false;
    if(a == 1) {
      poss = (n-1)%b == 0;
    }
    else {
      int na = 1;
      while(na <= n) {
        if((n-na)%b == 0)
          poss = true;
        na = na*a;
      }
    }

    std::cout << (poss ? "Yes" : "No") << std::endl;
  }

  return 0;
}