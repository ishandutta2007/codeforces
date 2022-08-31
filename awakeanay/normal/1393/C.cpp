#include <iostream>
#include <vector>
#include <set>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> count(n, 0), ncount(n, 0);
    int max = 0, times = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      ncount[x]++;
    }

    for(int i = 0; i < n; i++) {
      if(ncount[i] == max)
        times++;
      else if(ncount[i] > max) {
        max = ncount[i];
        times = 1;
      }
    }

    std::cout << times-1 + (n-max*times)/(max-1) << std::endl;
  }

  return 0;
}