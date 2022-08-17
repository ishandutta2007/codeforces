#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 1; i < n; i++) {
      if(a[i] < a[0])
        a[i] ^= a[0] ^= a[i] ^= a[0];
    }

    int ct = 0;
    for(int i = 1; i < n; i++) {
      std::cout << a[i] << " " << a[0] << std::endl;
      ct++;
      if(ct == n/2)
        break;
    }
  }

  return 0;
}