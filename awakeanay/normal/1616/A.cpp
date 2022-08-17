#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ct = 0;
    std::vector<int> c(101, 0);
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x == 0) {
        if(c[0])
          continue;
        c[0]++;
        ct++;
        continue;
      }
      if(x < 0)
        x *= -1;
      c[x]++;
      if(c[x] <= 2)
        ct++;
    }

    std::cout << ct << std::endl;
  }

  return 0;
}