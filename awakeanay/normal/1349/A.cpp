#include <iostream>

#define int long long 

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

int lcm(int a, int b) {
  int x = a/gcd(a, b);
  return x * b;
}

signed main() {
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int gpref[n], gsuff[n];

  gpref[0] = a[0];
  gsuff[n-1] = a[n-1];

  for(int i = 1; i < n; i++) {
    gpref[i] = gcd(gpref[i-1], a[i]);
  }

  for(int i = n-2; i >= 0; i--) {
    gsuff[i] = gcd(gsuff[i+1], a[i]);
  } 

  int ans = gsuff[1];
  for(int i = 1; i < n-1; i++) {
    int next = gcd(gpref[i-1], gsuff[i+1]);
    ans = lcm(ans, next);
  }

  ans = lcm(ans, gpref[n-2]);
  std::cout << ans << std::endl;

  return 0;
}