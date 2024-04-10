#include <iostream>
#include <vector>

#define int long long

const int MOD = 1000'000'007;

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

int inv(int x) {
  return expo(x, MOD-2);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, x, y, p, q;
    std::cin >> n >> m >> x >> y >> p >> q;

    int cx = x, cy = y, dx = 1, dy = 1;
    int fx = 1, fy = 1;
    if(cx + dx > n || cx + dx < 1)
      fx *= -1;
    if(cy + dy > m || cy + dy < 1)
      fy *= -1;

    std::vector<int> loop;

    int first = 1;
    while(true) {
      if(cx + dx > n || cx + dx < 1)
        dx *= -1;
      if(cy + dy > m || cy + dy < 1)
        dy *= -1;
      if(cx == x && cy == y && dx == fx && dy == fy && (!first))
        break;
      loop.push_back(cx == p || cy == q);
      first = 0;
      cx += dx;
      cy += dy;
    }

    n = loop.size();

    /*
    for(int i = 0; i < n; i++) {
      std::cout << loop[i] << " ";
    }
    std::cout << std::endl;
    */

    int pr;
    std::cin >> pr;

    pr *= inv(100);
    pr = (MOD+1-pr)%MOD;

    int d1 = 1, d2 = 0;

    for(int i = n-1; i >= 0; i--) {
      if(loop[i]) {
        int n1, n2;
        n1 = (pr*d1)%MOD;
        n2 = (pr*(d2 + 1))%MOD;
        d1 = n1;
        d2 = n2;
      }
      else {
        d2 = (d2 + 1)%MOD;
      }
    }

    int ans = (MOD-d2)%MOD;
    ans *= inv((d1-1+MOD)%MOD);
    ans %= MOD;

    std::cout << ans << std::endl;
  }

  return 0;
}