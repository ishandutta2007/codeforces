#include <iostream>

#define int long long

int till(int x, int y) {
  return x/y;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int a, b, x, y;
  std::cin >> a >> b >> x >> y;

  int lo = 1, hi = 100000000000000000;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    int both = mid - till(mid, x) - till(mid, y) + till(mid, x*y);
    int first = mid - till(mid, x) - both;
    int second = mid - till(mid, y) - both;
    
    int an = a, bn = b;
    int del;

    del = std::min(an, first);
    an -= del;
    del = std::min(bn, second);
    bn -= del;
    
    if(an + bn <= both)
      hi = mid;
    else
      lo = mid+1;
  }

  std::cout << lo << std::endl;

  return 0;
}