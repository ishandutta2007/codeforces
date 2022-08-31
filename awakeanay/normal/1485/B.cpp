#include <iostream>

#define int long long

signed main() {
  int n, q, k;
  std::cin >> n >> q >> k;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  while(q--) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;
    std::cout << k+1+a[r]-a[l]-2*(r-l+1) << std::endl;
  }

  return 0;
}