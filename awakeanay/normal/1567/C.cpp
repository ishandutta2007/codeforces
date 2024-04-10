#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int c[2], a[2];
    c[0] = c[1] = 0;
    a[0] = a[1] = 1;

    int i = 0;
    while(n > 0) {
      c[i%2] += a[i%2]*(n%10);
      n /= 10;
      a[i%2] *= 10;
      i++;
    }

    std::cout << (c[0]+1)*(c[1]+1)-2 << std::endl;
  }

  return 0;
}