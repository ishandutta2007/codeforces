#include <iostream>

#define int long long

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];
    for(int i = 0; i < n; i++)
      std::cin >> b[i];

    int ans = 0;
    for(int i = 1; i < n; i++) {
      ans += std::min(abso(a[i]-a[i-1]) + abso(b[i]-b[i-1]), abso(a[i]-b[i-1]) + abso(b[i]-a[i-1]));
    }

    std::cout << ans << std::endl;
  }

  return 0;
}