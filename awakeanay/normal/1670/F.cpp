#include <iostream>

#define int long long

const int LOG = 60;
const int MOD = 1000'000'007;
const int MAXN = 1005;

int z, r, n;
int store[LOG][MAXN];
int ch[MAXN][MAXN];

int dp(int i, int ex) {
  if(i == LOG) {
    return ex == 0;
  }

  if(store[i][ex])
    return store[i][ex]-1;

  int lim = r >> i;
  int ans = 0;

  for(int j = (z >> i)&1; j <= n && j+ex <= lim; j+=2) {
    int np = lim-ex-j;
    np /= 2;
    int nx = (lim >> 1) - np;
    ans = (ans + dp(i+1, nx)*ch[n][j])%MOD;
  }

  store[i][ex] = ans+1;
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 0; i < MAXN; i++)
    ch[i][i] = ch[i][0] = 1;

  for(int i = 0; i < MAXN; i++) {
    for(int j = 1; j < i; j++)
      ch[i][j] = (ch[i-1][j] + ch[i-1][j-1])%MOD;
  }

  int x, y;
  std::cin >> n;
  std::cin >> x >> y >> z;

  r = y;
  int ans = dp(0, 0);

  for(int i = 0; i < LOG; i++)
    for(int j = 0; j < MAXN; j++)
      store[i][j] = 0;

  r = x-1;
  ans = (ans - dp(0, 0) + MOD)%MOD;

  std::cout << ans << std::endl;

  return 0;
}