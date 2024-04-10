#include <iostream>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int gd = 0;
  int a[n];
  int ans = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    gd = gcd(gd, a[i]);

    if(i && a[i]%2 && a[i-1]%2) {
      a[i-1] = a[i] = 2;
      ans++;
    }
  }

  for(int i = 0; i < n; i++) {
    if(a[i]%2)
      ans += 2;
  }

  if(gd != 1) {
    std::cout << "YES" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }

  std::cout << "YES" << std::endl;
  std::cout << ans << std::endl;

  return 0;
}