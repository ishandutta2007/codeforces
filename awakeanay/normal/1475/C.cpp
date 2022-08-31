#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b, k;
    std::cin >> a >> b >> k;

    int ans = 0;

    std::vector<int> c1(a, 0), c2(b, 0);
    std::vector<std::pair<int, int> > p(k);
    for(int i = 0; i < k; i++) {
      int u;
      std::cin >> u;
      p[i].first = u-1;
    }
    for(int i = 0; i < k; i++) {
      int u;
      std::cin >> u;
      p[i].second = u-1;
    }


    for(int i = 0; i < k; i++) {
      int u = p[i].first, v = p[i].second;
      ans += i - c1[u] - c2[v];
      c1[u]++; c2[v]++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}