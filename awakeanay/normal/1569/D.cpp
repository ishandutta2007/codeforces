#include <iostream>
#include <map>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int x[n], y[m];
    for(int i = 0; i < n; i++)
      std::cin >> x[i];
    for(int i = 0; i < m; i++)
      std::cin >> y[i];

    std::map<std::pair<int, int>, int> mpa, mpb;
    std::map<int, int> mpx, mpy;

    int ans = 0;
    for(int i = 0; i < k; i++) {
      int a, b;
      std::cin >> a >> b;

      int u = std::lower_bound(x, x+n, a)-x;
      int v = std::lower_bound(y, y+m, b)-y;
      if(x[u] == a && y[v] == b)
        continue;
      if(x[u] == a) {
        ans += mpy[v] - mpa[{u, v}];
        mpa[{u, v}]++;
        mpy[v]++;
      }
      else {
        ans += mpx[u] - mpb[{u, v}];
        mpb[{u, v}]++;
        mpx[u]++;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}