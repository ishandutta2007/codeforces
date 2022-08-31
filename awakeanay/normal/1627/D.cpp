#include <iostream>

#define int long long

const int MAXN = 1000006;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

int a[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a[x] = 1;
  }

  int ans = 0;
  for(int j = MAXN-1; j >= 1; j--) {
    int gd = 0;
    for(int k = j; k < MAXN; k+=j) {
      if(a[k] == 1)
        gd = gcd(gd, k);
    }
    if(gd == j)
      a[j] = 1;
    ans += a[j];
  }

  std::cout << ans-n << std::endl;

  return 0;
}