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
    for(int i = 0; i < n; i++) {
      a[i] = i+1;
    }
    for(int j = (n%2); j < n; j+=2) {
      a[j] ^= a[j+1] ^= a[j] ^= a[j+1];
    }
    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << "\n";
  }

  return 0;
}