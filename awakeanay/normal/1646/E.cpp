#include <iostream>

#define int long long

const int LOG = 20;
const int MAXN = 1000006;

int n, m;
int f[(1 << LOG)];
short done[MAXN];

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

int lcm(int a, int b) {
  return a*(b/gcd(a, b));
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> m;

  int tot = 0;

  for(int b = 1; b < (1 << LOG); b++) {
    int max = m*LOG;

    int lm = 1;
    for(int j = 0; j < LOG; j++) {
      if((b >> j)&1) {
        max = std::min(max, m*(j+1));
        lm = lcm(j+1, lm);
      }
    }

    int mag = max/lm;
    f[b] = __builtin_parity(b) ? mag : -mag;
  }

  for(int i = 0; i < LOG; i++) {
    for(int j = 0; j < (1 << LOG); j++) {
      if((j >> i)&1)
        f[j] += f[j^(1 << i)];
    }
  }

  int ans = 1;
  for(int i = 2; i <= n; i++) {
    if(done[i])
      continue;

    int ct = 0;
    for(int j = i; j <= n; j*=i) {
      done[j] = 1;
      ct++;
    }

    ans += f[(1 << ct)-1];
  }

  std::cout << ans << std::endl;

  return 0;
}