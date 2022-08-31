#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, q;
    std::cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++) {
      int cur;
      char c;
      std::cin >> c;
      cur = (c == '+' ? 1 : -1);
      if(i%2)
        cur *= -1;
      a[i] = cur;
      if(i)
        a[i] += a[i-1];
    }

    while(q--) {
      int l, r;
      std::cin >> l >> r;
      l--;
      r--;
      int sum = a[r];
      if(l)
        sum -= a[l-1];
      if(sum < 0)
        sum *= -1;
      if(sum == 0)
        std::cout << 0 << std::endl;
      else if(sum%2)
        std::cout << 1 << std::endl;
      else
        std::cout << 2 << std::endl;
    }
  }

  return 0;
}