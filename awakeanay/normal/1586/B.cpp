#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> poss(n, 1);
    for(int i = 0; i < m; i++) {
      int a, b, c;
      std::cin >> a >> b >> c;
      b--;
      poss[b] = 0;
    }

    int best = -1;
    for(int j = 0; j < n; j++)
      if(poss[j])
        best = j;

    for(int i = 0; i < n; i++) {
      if(i == best)
        continue;
      std::cout << i+1 << " " << best+1 << std::endl;
    }
  }

  return 0;
}