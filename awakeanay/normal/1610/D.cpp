#include <iostream>

#define int long long

const int MOD = 1000'000'007;
const int MAXN = 200005;

int p2[MAXN];
int gc[35];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  p2[0] = 1;
  for(int i = 1; i < MAXN; i++)
    p2[i] = (p2[i-1]*2)%MOD;

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    int px = 0;
    while(x%2 == 0) {
      x /= 2;
      px++;
    }
    gc[px]++;
  }

  ans = (p2[gc[0]]-1+MOD)*p2[n-gc[0]];
  ans %= MOD;

  int ah = 0;
  for(int i = 34; i > 0; i--) {
    if(gc[i]) {
      ans = (ans + (p2[gc[i]-1] - 1 + MOD)*p2[ah])%MOD;
      ans %= MOD;
    }
    ah += gc[i];
  }

  std::cout << ans << std::endl;

  return 0;
}