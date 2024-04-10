#include <iostream>
#include <vector>

#define int long long

const int MAX = 105;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> ct(MAX, 0);
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      ct[x]++;
    }

    int ans = 0;
    for(int k = 0; k < 2; k++)
      for(int i = 0; i < MAX; i++) {
        if(!ct[i]) {
          ans += i;
          for(int j = 0; j < i; j++)
            ct[j]--;
          break;
        }
      }

    std::cout << ans << std::endl;
  }

  return 0;
}