#include <iostream>
#include <vector>

#define int long long

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a, m;
    std::cin >> a >> m;

    int d = gcd(a, m);

    int l = a/d-1;
    int r = (a+m)/d - 1;
    
    m /= d;

    std::vector<int> pr;
    for(int i = 2; i*i <= m; i++) {
      if(m%i == 0) {
        pr.push_back(i);
        while(m%i == 0)
          m /= i;
      }
    }

    if(m > 1) {
      pr.push_back(m);
    }

    int k = pr.size();
    int ans = 0;
    for(int i = 0; i < (1 << k); i++) {
      int sgn = 1;
      int cur = 1;

      for(int j = 0; j < k; j++) {
        if((i >> j)&1ll) {
          sgn *= -1;
          cur *= pr[j];
        }
      }

      ans += sgn*(r/cur - l/cur);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}