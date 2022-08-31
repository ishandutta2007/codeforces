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

    int a[n], b[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      std::cin >> b[i];
    }

    std::vector<std::pair<int, int> > ans;
    while(true) {
      int check = 0;
      for(int i = 0; i+1 < n; i++) {
        if((a[i] > a[i+1] && b[i] >= b[i+1]) || (b[i] > b[i+1] && a[i] >= a[i+1])) {
          ans.push_back({i+1, i+2});
          a[i] ^= a[i+1] ^= a[i] ^= a[i+1];
          b[i] ^= b[i+1] ^= b[i] ^= b[i+1];
          check = true;
          break;
        }
      }

      if(!check)
        break;
    }

    bool poss = true;
    for(int i = 0; i+1 < n; i++) {
      poss &= a[i] <= a[i+1];
      poss &= b[i] <= b[i+1];
    }

    if(poss) {
      std::cout << ans.size() << std::endl;
      for(auto j : ans)
        std::cout << j.first << " " << j.second << std::endl;
    }
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}