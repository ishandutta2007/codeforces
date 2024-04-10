#include <iostream>

#define int long long

const int MOD = 1000000007;

int k;

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;
    
    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int intersect(int x, int y, int a, int b) {
  return std::max(0ll, std::min(b, y) - std::max(x, a));
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, r, c;
  std::cin >> n >> m >> k >> r >> c;
  int ax, ay, bx, by;
  std::cin >> ax >> ay >> bx >> by;

  if(ax == bx && ay == by) {
    std::cout << expo(k, n*m) << std::endl;
    return 0;
  }

  int a = intersect(ax, ax+r, bx, bx+r);
  int b = intersect(ay, ay+c, by, by+c);
  int common = a*b;
  int exter = n*m - 2*r*c + common;
  int init = expo(k, exter);
  if(common == 0) {
    init = (init*expo(k, r*c))%MOD;
  }
  else {
    int n = r, m = c, x = a, y = b;
    while(true) {
      int a = intersect(0, x, n-x, n);
      int b = intersect(0, y, m-y, m);
      int common = a*b;
      int exter = n*m - 2*x*y + common;

      if(common == 0) {
        init = (init*expo(k, exter + x*y))%MOD;
        break;
      }
      else {
        init = (init*expo(k, exter))%MOD;
        n = x;
        m = y;
        x = a;
        y = b;
      }
    }
  }

  std::cout << init << std::endl;

  return 0;
}