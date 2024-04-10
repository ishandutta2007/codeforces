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

    int cur = 0;
    int x = a[n-1];

    for(int i = n-2; i >= 0; i--) {
      if(a[i] > x) {
        x = a[i];
        cur++;
      }
    }

    std::cout << cur << std::endl;
  }

  return 0;
}