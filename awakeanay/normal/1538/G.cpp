#include <iostream>

#define int long long

const int INF = 1000000007;

int a, b;

int ans(int x, int y) {
  if(x < a || y < b)
    return 0;
  if(x-a > y-b) {
    int cur = x/(a+b);
    x -= cur*(a+b);
    y -= cur*(a+b);
    cur <<= 1;
    cur += (x >= a && y >= b);
    return cur;
  }
  int lo = 1, hi = INF;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    int nx = x-mid*a, ny = y-mid*b;
    bool check = nx < 0 || ny < 0 || ny < nx;
    if(check)
      hi = mid;
    else
      lo = mid+1;
  }
  lo--;
  x -= lo*a;
  y -= lo*b;
  if(lo == 0) {
    return 0;
  }
  else {
    int ans = lo;
    int cur = x/(a+b);
    x -= cur*(a+b);
    y -= cur*(a+b);
    cur <<= 1;
    cur += (x >= a && y >= b);
    return ans + cur;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int x, y;
    std::cin >> x >> y >> a >> b;
    if(a > b)
      a ^= b ^= a ^= b;
    if(x > y)
      x ^= y ^= x ^= y;
    std::cout << ans(x, y) << std::endl;
  }

  return 0;
}