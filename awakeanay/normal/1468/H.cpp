#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k, m;
    std::cin >> n >> k >> m;

    int c = (k-1)/2;

    std::vector<int> stay(n, 0);
    for(int i = 0; i < m; i++) {
      int x;
      std::cin >> x;
      x--;
      stay[x] = 1;
    }

    if((n-m)%(2*c) != 0) {
      std::cout << "NO" << std::endl;
      continue;
    }

    bool poss = false;

    int dell = 0, delr = n-m;
    for(int i = 0; i < n; i++) {
      if(stay[i]) {
        if(std::min(dell, delr) == 0)
          continue;

        if(dell%c == 0 && delr%c == 0) {
          poss = true;
        }

        if((dell%c)+c+1 < dell && delr >= c)
          poss = true;
        if((delr%c)+c+1 < delr && dell >= c)
          poss = true;
      }
      else {
        dell++;
        delr--;
      }
    }

    if(poss)
      std::cout << "YES";
    else
      std::cout << "NO";

    std::cout << std::endl;
  }

  return 0;
}