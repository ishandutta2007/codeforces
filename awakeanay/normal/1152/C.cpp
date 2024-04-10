#include <iostream>

#define int long long

const int INF = 1000000000000000000;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int a, b;
  std::cin >> a >> b;

  int min = a*b;
  min /= gcd(a, b);
  int c1 = 0;

  int diff = a < b ? b-a : a-b;

  if(diff == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  for(int j = 1; j*j <= diff; j++) {
    int st = j;
    if(diff%j == 0) {
      for(int m = 0; m < 2; m++) {
        int cur = a%j;
        cur = j-cur;
        cur %= j;
        int x = a+cur;
        int y = b+cur;
        int lcm = x/gcd(x,y);
        lcm *= y;
        if(lcm < min) {
          min = lcm;
          c1 = cur;
        }
        else if(lcm == min && cur < c1)
          c1 = cur;
        j = diff/j;
      }
      j = st;
    }
  }

  std::cout << c1 << std::endl;

  return 0;
}