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
    int xa, ya, xb, yb, xf, yf;
    std::cin >> xa >> ya >> xb >> yb >> xf >> yf;

    int ans = abso(xa-xb) + abso(ya-yb);
    if(xa == xb && xb == xf && (yf-ya)*(yb-yf) > 0)
      ans += 2;
    if(ya == yb && yb == yf && (xf-xa)*(xb-xf) > 0)
      ans += 2;
    std::cout << ans << std::endl;
  }

  return 0;
}