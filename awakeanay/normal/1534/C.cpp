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

    int p1[n];
    for(int i = 0; i < n; i++) {
      std::cin >> p1[i];
      p1[i]--;
    }

    int p2[n];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      p2[x-1] = p1[i];
    }

    std::vector<int> vis(n, 0);
    int ans = 1;
    for(int i = 0; i < n; i++) {
      if(vis[i])
        continue;
      int cur = i;
      ans = (ans*2)%1000000007;
      while(!vis[cur]) {
        vis[cur] = true;
        cur = p2[cur];
      }
    }

    std::cout << ans << std::endl;

  }

  return 0;
}