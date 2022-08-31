#include <iostream>
#include <algorithm>

#define int long long

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

signed main() {
  int n, m;
  std::cin >> n >> m;

  int a[n], b[m];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  for(int i = 0; i < m; i++)
    std::cin >> b[i];

  std::sort(a, a+n);

  int x = 0;
  for(int i = 1; i < n; i++)
    x = gcd(x, a[i]-a[i-1]);

  for(int i = 0; i < m; i++) {
    std::cout << gcd(x, a[0] + b[i]) << " ";
  }

  std::cout << std::endl;

  return 0;
}