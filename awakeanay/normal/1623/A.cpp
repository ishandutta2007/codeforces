#include <iostream>

#define int long long

int n, m;

int dist(int a, int b, int n) {
  if(a <= b)
    return b-a;
  return 2*n-a-b;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> m;

    int x, y, p, q;
    std::cin >> x >> y >> p >> q;

    int ans = std::min(dist(x, p, n), dist(y, q, m));
    std::cout << ans << std::endl;
  }

  return 0;
}