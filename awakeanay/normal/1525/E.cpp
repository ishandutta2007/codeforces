#include <iostream>
#include <vector>

#define int long long

const int MAXN = 25;
const int MOD = 998244353;

int fact[MAXN];

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;

    x = (x*x)%MOD;
    p >>= 1;
  }
  return ret;
}
  
int inv(int x) {
  return expo(x, MOD-2);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  fact[0] = 1;
  for(int i = 1; i <= n; i++)
    fact[i] = (i*fact[i-1])%MOD;

  int invn = inv(fact[n]);

  int input[n][m];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> input[i][j];

  int ans = 0;
  for(int i = 0; i < m; i++) {
    int avail = 1;
    std::vector<int> tvail(n+1, 0);
    for(int j = 0; j < n; j++) {
      tvail[n+1-input[j][i]]++;
    }

    int cur = 1;
    for(int i = 0; i < n; i++) {
      avail += tvail[i]-1;
      cur = (avail*cur)%MOD;
    }

    cur = MOD + fact[n] - cur;
    cur %= MOD;
    cur *= invn;
    cur %= MOD;
    ans += cur;
    ans %= MOD;
  }

  std::cout << ans << std::endl;

  return 0;
}