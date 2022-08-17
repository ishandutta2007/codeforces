#include <iostream>

#define int long long

int query(int l, int r) {
  int ret;
  std::cout << "? " << l << " " << r << std::endl;
  std::cin >> ret;
  return ret;
}

signed main() {
  int n;
  std::cin >> n;

  int x = query(1, n);

  int l = 1, r = n-1;
  while(l < r) {
    int m = (l+r)/2;
    int left, right;
    if(x-m <= 1) {
      left = 1;
      right = m+1;
    }
    else {
      left = x-m;
      right = x;
    }

    bool check = query(left, right) == x;
    if(check)
      r = m;
    else
      l = m+1;
  }

  std::cout << "! ";
  if(x-l < 1)
    std::cout << l+1 << std::endl;
  else
    std::cout << x-l << std::endl;

  return 0;
}