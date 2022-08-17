#include <iostream>

#define int long long

bool check(int x) {
  int l = 1, r = 100000;
  while(l < r) {
    int mid = (l+r)/2;
    if(mid*mid*mid >= x)
      r = mid;
    else
      l = mid+1;
  }

  return l*l*l == x;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int x;
    std::cin >> x;

    bool poss = false;
    for(int i = 1; i*i*i < x; i++) {
      int b = x - i*i*i;
      if(check(b))
        poss = true;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}