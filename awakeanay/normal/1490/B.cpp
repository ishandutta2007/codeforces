#include <iostream>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int c[3];
    c[0] = c[1] = c[2] = 0;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      c[x%3]++;
    }

    int k = n/3;
    int ans = 0;
    int j;
    for(int i = 0; i < 6; i++) {
      j = i%3;
      if(c[j] > k) {
        c[(j+1)%3] += c[j]-k;
        ans += c[j]-k;
        c[j] = k;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}