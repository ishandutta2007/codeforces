#include <iostream>

#define int long long

#define MOD 1000000007

signed main() {
  int n, x, pos;
  std::cin >> n >> x >> pos;

  int less = 0, more = 0;
  int l = 0, r = n;

  while(l < r) {
    int m = (l+r)/2;
    if(pos > m)
      less++;
    else if(pos < m)
      more++;

    if(pos >= m)
      l = m+1;
    else
      r = m;
  }
  
  int ans = 1;
  int availl = x-1;
  int availm = n-x;
  int any = n-1-less-more;

  while(less) {
    ans = (ans*availl)%MOD;
    availl--;
    less--;
  }

  while(more) {
    ans = (ans*availm)%MOD;
    availm--;
    more--;
  }

  int avail = availl + availm;
  while(any) {
    ans = (ans*avail)%MOD;
    avail--;
    any--;
  }

  std::cout << ans << std::endl;

  return 0;
}