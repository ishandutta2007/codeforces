#include <iostream>

signed main() {
  int n, q;
  std::cin >> n >> q;

  int a[n];
  int c[2];
  c[0] = c[1] = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    c[a[i]]++;
  }

  for(int i = 0; i < q; i++) {
    int t;
    std::cin >> t;

    if(t == 1) {
      int x;
      std::cin >> x;
      x--;
      c[a[x]]--;
      a[x] ^= 1;
      c[a[x]]++;
    }
    else {
      int k;
      std::cin >> k;

      std::cout << (c[1] >= k) << std::endl;
    }
  }

  return 0;
}