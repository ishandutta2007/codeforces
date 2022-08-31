#include <iostream>
#include <map>

#define int long long

int abso(int x) {
  if(x >= 0)
    return x;
  return -x;
}

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<std::pair<int, int>, int> dir;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x, y, u, v;
      std::cin >> x >> y >> u >> v;
      int p = u-x;
      int q = v-y;
      int d = gcd(abso(p), abso(q));
      p /= d; q /= d;

      ans += dir[{-p, -q}];
      dir[{p, q}]++;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}