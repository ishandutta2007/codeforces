#include <iostream>
#include <cmath>
#include <iomanip>

#define int long long

const long double eps = 0.00000000001;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k, d, t;
  std::cin >> k >> d >> t;

  int u = k/d;
  if(k%d != 0)
    u++;

  d *= u;

  int need = 2*t;

  int lo = 1, hi = (2*t)/d + 1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(mid*(d + k) >= need)
      hi = mid;
    else
      lo = mid+1;
  }

  int cur = lo-1;
  //std::cout << cur << std::endl;
  long double tim = (cur*d);
  int done = cur*(d + k);

  int rem = 2*t-done;
  if(rem <= 2*k) {
    tim += ((long double)(rem))/2.0000000000000000000;
  }
  else {
    tim += (long double)(k);
    tim += ((long double)rem)-(long double)(2*k);
  }

  std::cout << std::fixed << std::setprecision(15);
  std::cout << tim << std::endl;

  return 0;
}