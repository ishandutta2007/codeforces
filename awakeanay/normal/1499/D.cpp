#include <iostream>

#define int long long

const int MAXN = 20000007;
const int MP = 1000;

int pr[MAXN];
int np[MAXN];
int p2[MP];

signed main() {
  for(int i = 2; i < MAXN; i++) {
    if(pr[i] != 0)
      continue;
    for(int j = i; j < MAXN; j+=i) {
      pr[j] = i;
    }
  }

  for(int i = 2; i < MAXN; i++) {
    int cur = pr[i];
    int next = i;
    while(pr[next] == cur)
      next /= cur;

    np[i] = np[next] + 1;
  }

  p2[0] = 1;
  for(int i = 1; i < MP; i++)
    p2[i] = 2*p2[i-1];

  int t;
  std::cin >> t;

  while(t--) {
    int ans = 0;
    int c, d, x;
    std::cin >> c >> d >> x;

    for(int j = 1; j*j <= x; j++) {
      if(x%j != 0)
        continue;
      int next = x/j + d;
      if(next%c != 0)
        continue;
      ans += p2[np[next/c]];
    }

    for(int j = 1; j*j < x; j++) {
      if(x%j != 0)
        continue;
      int k = x/j;
      int next = x/k + d;
      if(next%c != 0)
        continue;
      ans += p2[np[next/c]];
    }

    std::cout << ans << std::endl;
  }

  return 0;
}