#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> pos, neg;
    int ans = 1;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(i < 5)
        ans *= x;
      if(x < 0)
        neg.push_back(x);
      else
        pos.push_back(x);
    }

    std::sort(pos.begin(), pos.end());
    std::sort(neg.begin(), neg.end());
    int p = pos.size();
    int q = neg.size();

    for(int j = 0; j <= 5; j++) {
      int cur = 1;
      if(j > q || 5-j > p)
        continue;
      if(j&1) {
        for(int i = 0; i < j; i++)
          cur *= neg[q-i-1];
        for(int i = 0; i < 5-j; i++)
          cur *= pos[i];
      }
      else {
        for(int i = 0; i < j; i++)
          cur *= neg[i];
        for(int i = 0; i < 5-j; i++)
          cur *= pos[p-i-1];
      }
      ans = std::max(ans, cur);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}