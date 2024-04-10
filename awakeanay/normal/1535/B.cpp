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

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int ans = 0;
    int even = 0;

    for(int i = 0; i < n; i++) {
      if(a[i]%2 == 0) {
        even++;
      }
      else {
        for(int j = 0; j < i; j++) {
          if(a[j]%2 == 1 && gcd(a[j], a[i]) > 1)
            ans++;
        }
      }
    }

    ans += even*(n-1) - (even*(even-1))/2;
    std::cout << ans << std::endl;
  }

  return 0;
}