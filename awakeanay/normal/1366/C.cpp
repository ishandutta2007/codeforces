#include <iostream>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int> > types(n+m-1, std::vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int x;
        std::cin >> x;
        int cur = std::min(i+j, n+m-2-i-j);
        types[cur][x]++;
      }
    }

    int ans = 0;
    for(int i = 0; i < n+m-1; i++)
      if(2*i != n+m-2)
        ans += std::min(types[i][0], types[i][1]);

    if((n+m)%2) {
      ans -= std::min(types[(n+m)/2][0], types[(n+m)/2][1]);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}