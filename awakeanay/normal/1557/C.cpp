#include <iostream>
#include <vector>

#define int long long

const int MOD = 1'000'000'007;

const int MAXN = 200005;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  int p2[MAXN];
  p2[0] = 1;
  for(int i = 1; i < MAXN; i++)
    p2[i] = (2*p2[i-1])%MOD;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    if(k == 0) {
      std::cout << 1 << std::endl;
      continue;
    }

    int win = 0;
    int lose = p2[n-1];
    int tie = p2[n-1];

    if(n&1) {
      tie++;
      lose += MOD-1;
    }
    else {
      win++;
      tie += MOD-1;
    }
    tie %= MOD;
    lose %= MOD;

    int ans = 1;
    for(int i = 0; i < k; i++)
      ans = (ans*tie)%MOD;

    std::vector<int> add(k, win);
    int cur = 1;
    for(int i = 0; i < k; i++) {
      add[i] = (add[i]*cur)%MOD;
      cur = (cur*tie)%MOD;
    }

    cur = 1;
    for(int i = k-1; i >= 0; i--) {
      add[i] = (add[i]*cur)%MOD;
      cur = (cur*p2[n])%MOD;
      ans = (ans + add[i])%MOD;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}