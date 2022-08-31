#include <iostream>

#define int long long

int k, x;

int count(int n) {
  if(n >= 2*k-1)
    return true;

  int cur = 0;
  if(n <= k)
    cur = (n*(n+1))/2;
  else
    cur = (k*(k+1))/2 + ((k-(n-k) + k-1)*(n-k))/2;
  
  return cur >= x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> k >> x;
    int lo = 1, hi = 2*k-1;
    while(lo < hi) {
      int mid = (lo+hi)/2;
      if(count(mid))
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}