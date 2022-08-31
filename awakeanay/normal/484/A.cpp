#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  while(n--) {
    int l, r;
    std::cin >> l >> r;
    if(l == r) {
      std::cout << l << std::endl;
      continue;
    }

    int last = -1;
    for(int i = 63; i >= 0; i--) {
      if(((r >> i)&1ll)^((l >> i)&1ll)) {
        last = i;
        int cur = r-r%(1ll << i)-1;

        int u = __builtin_popcountll(cur);
        int v = __builtin_popcountll(r);

        if(v > u)
          std::cout << r << std::endl;
        else
          std::cout << cur << std::endl;
        break;
      }
    }
  }

  return 0;
}