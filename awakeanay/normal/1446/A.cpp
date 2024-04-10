#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, W;
    std::cin >> n >> W;
    int k = W-W/2;

    int cur = 0;
    int w[n];
    bool search = true;
    std::vector<int> ans;

    for(int i = 0; i < n; i++)
      std::cin >> w[i];

    for(int i = 0; i < n && search; i++) {
      if(w[i] > W)
        continue;
      if(w[i] >= k) {
        search = false;
        std::cout << 1 << std::endl;
        std::cout << i+1 << std::endl;
      }
      else {
        cur += w[i];
        ans.push_back(i+1);
        if(cur >= k) {
          search = false;
          std::cout << ans.size() << std::endl;
          for(int j : ans)
            std::cout << j << " ";
          std::cout << std::endl;
        }
      }
    }

    if(search) {
      std::cout << -1 << std::endl;
    }
  }

  return 0;
}