#include <iostream>
#include <vector>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> bit(30, 0);
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      for(int j = 0; j < 30; j++)
        if((x >> j)&1)
          bit[j]++;
    }

    int ans = 0;
    for(int i = 0; i < 30; i++) {
      ans = gcd(ans, bit[i]);
    }

    for(int i = 1; i <= n; i++) {
      if(ans%i == 0)
        std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}