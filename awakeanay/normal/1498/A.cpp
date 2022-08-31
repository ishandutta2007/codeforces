#include <iostream>

#define int long long

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += x%10;
    x /= 10;
  }
  return ret;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;
    while(gcd(n, sum(n)) == 1)
      n++;
    std::cout << n << std::endl;
  }

  return 0;
}