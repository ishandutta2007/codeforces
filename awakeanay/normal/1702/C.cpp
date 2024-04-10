#include <iostream>
#include <map>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> mpl, mpr;
    for(int i = 0; i < n; i++) {
      int u;
      std::cin >> u;
      if(mpl.find(u) == mpl.end())
        mpl[u] = i;
      mpr[u] = i;
    }

    while(k--) {
      int a, b;
      std::cin >> a >> b;

      if(mpl.find(a) == mpl.end() || mpl.find(b) == mpl.end()) {
        std::cout << "NO" << "\n";
      }
      else {
        if(mpl[a] <= mpr[b])
          std::cout << "YES" << "\n";
        else
          std::cout << "NO" << "\n";
      }
    }
  }

  return 0;
}