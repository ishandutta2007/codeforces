#include <iostream>

#define int long long

const int MOD = 1000000007;

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

    int last = n;
    int i = 2;
    int num = 1;

    int ans = 0;
    while(true) {
      int gd = gcd(num, i);
      int nex = num/gd;
      num = nex*i;

      int cur = n/num;
      ans += (last-cur)*i;
      ans %= MOD;

      last = cur;

      i++;

      if(num > n)
        break;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}