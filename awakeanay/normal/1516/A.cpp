#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int extra = 0;
    for(int i = 0; i+1 < n; i++) {
      int add = std::min(k, a[i]);
      a[i] -= add;
      k -= add;
      extra += add;
    }

    a[n-1] += extra;
    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}