#include <iostream>

#define int long long


int add = 0;

int query(int u) {
  add += u;
  std::cout << "+ " << u << std::endl;
  int ret;
  std::cin >> ret;
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int lo = 1, hi = n-1;
  int cd = 0;
  int last = 0;
  add = 0;
  while(lo < hi) {
    int m = (lo+hi)/2;

    int ct = m;
    int ch = ct-last > 0 ? 0 : 1;
  
    int ret = query(ch*n-last+ct);

    cd += ch;
    if(ret > cd)
      hi = m;
    else
      lo = m+1;

    last = ct;
  }

  std::cout << "! " << add+n-lo << std::endl;

  return 0;
}