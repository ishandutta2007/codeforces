#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
const int INF = 10000000000000;


signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> w[2];
    
    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < n; i++) {
      int u;
      std::cin >> u;

      w[u-1].push_back(a[i]);
    }

    std::sort(w[0].begin(), w[0].end());
    std::reverse(w[0].begin(), w[0].end());
    std::sort(w[1].begin(), w[1].end());
    std::reverse(w[1].begin(), w[1].end());

    std::vector<int> x[2];

    for(int j = 0; j < 2; j++) {
      x[j].push_back(0);
      for(int i = 0; i < w[j].size(); i++) {
        if(i) w[j][i] += w[j][i-1];
        x[j].push_back(w[j][i]);
      }
    }

    int ans = INF;

    int sum = 0;
    for(int i = 0; i < x[0].size(); i++) {
      sum = x[0][i];
      int l = 0, r = x[1].size()-1;
      
      while(l < r) {
        int mid = (l+r)/2;
        if(x[1][mid] >= m-sum)
          r = mid;
        else
          l = mid+1;
      }

      if(x[1][l] >= m-sum) {
        ans = std::min(ans, i + 2*l);
      }
    }

    if(ans == INF)
      std::cout << -1 << std::endl;
    else
      std::cout << ans << std::endl;
  }

  return 0;
}