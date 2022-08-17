#include <iostream>

#define int long long

const int MAXR = 100005;

bool isSq(int x) {
  int l = 0, r = MAXR;
  while(l < r) {
    int m = (l+r)/2;
    if(m*m >= x)
      r = m;
    else
      l = m+1;
  }
  return l*l == x;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    if(n%2)
      std::cout << "NO" << std::endl;
    else {
      while(n%2 == 0)
        n /= 2;

      std::cout << (isSq(n) ? "YES" : "NO") << std::endl;
    }
  }

  return 0;
}