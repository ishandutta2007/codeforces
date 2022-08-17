#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  int a[n];
  int c0[n], c1[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    c0[i] = c1[i] = 0;
  }

  int ans = 0;
  for(int i = n-1; i >= 0; i--) {
    int cur = std::min(i+1, k);
    if(i+1 < n) {
      c1[i] += c1[i+1];
      c0[i] += c0[i+1];
    }
    a[i] += c1[i]*i;
    a[i] += c0[i];
    if(a[i] > 0) {
      int ct = std::max(0ll, (a[i]/cur) + (a[i]%cur != 0));
      ans += ct;
      c1[i] -= ct;
      c0[i] += ct*(i-cur);
      if(i-cur >= 0) {
        c1[i-cur] += ct;
        c0[i-cur] -= ct*(i-cur);
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}