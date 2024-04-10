#include <iostream>

#define int long long

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, u, v;
    std::cin >> n >> u >> v;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int ans = std::min(u+v, 2*v);
    for(int i = 1; i < n; i++) {
      if(abso(a[i]-a[i-1]) > 1)
        ans = 0;
    }

    for(int i = 1; i < n; i++) {
      if(a[i] != a[i-1]) {
        ans = std::min(ans, u);
        ans = std::min(ans, v);
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}