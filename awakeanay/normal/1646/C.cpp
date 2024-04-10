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

    std::vector<int> facts;
    int f = 1;
    for(int i = 1; f <= n; i++) {
      f *= i;
      facts.push_back(f);
    }

    int m = facts.size();
    int ans = n;

    for(int j = 0; j < (1 << m); j++) {
      int take = 0;
      for(int i = 0; i < m; i++)
        if((j >> i)&1)
          take += facts[i];

      int next =  __builtin_popcount(j) + __builtin_popcountll(n-take);
      ans = std::min(ans, next);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}