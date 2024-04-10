#include <iostream>

#define int long long

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

const int MAX = 15000006;

signed cmp[MAX];
signed count[MAX];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 2; i < MAX; i++) {
    if(cmp[i])
      continue;
    cmp[i] = i;
    for(int j = i*i; j < MAX; j+=i)
      cmp[j] = i;
  }

  int a[n];
  bool poss = false;
  int gd = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    gd = gcd(a[i], gd);
    if(a[i] != a[0])
      poss = true;
  }

  int ans = n-1;

  if(!poss) {
    std::cout << -1 << std::endl;
    return 0;
  }

  for(int i = 0; i < n; i++) {
    a[i] /= gd;
    while(a[i] > 1) {
      int j = cmp[a[i]];
      count[j]++;
      ans = std::min(ans, n-count[j]);
      while(a[i]%j == 0)
        a[i] /= j;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}