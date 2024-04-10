#include <iostream>

#define int long long

const int MOD = 1000000007;

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int x = a[0];
    for(int i = 1; i < n; i++)
      x &= a[i];

    for(int i = 0; i < n; i++)
      a[i] ^= x;

    int num0 = 0;
    for(int i = 0; i < n; i++)
      num0 += a[i] == 0;

    int count = (num0*(num0-1))%MOD;
    for(int i = 0; i < n-2; i++)
      count = (count*(i+1))%MOD;

    std::cout << count << std::endl;
  }
  
  return 0;
}