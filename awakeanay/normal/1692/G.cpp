#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    int b[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i)
        b[i-1] = a[i-1] < 2*a[i];
    }
    int cur = 0;
    int ans = 0;
    for(int i = 0; i+1 < n; i++) {
      cur += b[i];
      if(i-k >= 0)
        cur -= b[i-k];
      if(cur == k)
        ans++;
    }
    std::cout << ans << std::endl;
  }

  return 0;
}