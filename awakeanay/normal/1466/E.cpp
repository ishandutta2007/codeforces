#include <iostream>
#include <vector>

const int MOD = 1000000007;

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    std::vector<int> count(61, 0);
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      for(int j = 0; j < 61; j++) {
        if((1ll << j)&a[i])
          count[j]++;
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int c1 = 0, c2 = 0;
      for(int j = 0; j < 61; j++) {
        int x = (1ll << j)%MOD;
        int y = (count[j]*x)%MOD;
        int z = (n*x)%MOD;
        if((1ll << j)&a[i]) {
          c1 = (c1 + y)%MOD;
          c2 = (c2 + z)%MOD;
        }
        else {
          c2 = (c2 + y)%MOD;
        }
      }

      ans = (ans + (c1*c2)%MOD)%MOD;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}