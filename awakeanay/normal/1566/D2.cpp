#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::pair<int, int> help[n*m];
    for(int i = 0; i < n*m; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
    }

    std::sort(help, help+n*m);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int u = i*m+j;
        for(int k = 0; k < j; k++) {
          int v = i*m+k;
          if(help[v].first != help[u].first && help[v].second < help[u].second)
            ans++;
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}