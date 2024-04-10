#include <iostream>

#define int long long

const int MAXM = 1 << 17;
const int MAXL = 17;
const int MAXN = 1005;
const int MOD = 998244353;

int f[MAXL+1][MAXM];
int calc[MAXN][MAXN];
int worth[MAXN][MAXN];
int dp[MAXN][MAXN];
int expo[MAXL+1][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  int tot = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '?') {
      tot++;
      calc[i][i] = 1;
      worth[i][i] = 1;
    }
  }

  for(int i = 1; i <= MAXL; i++) {
    int ret = 1;
    for(int j = 0; j <= MAXN; j++) {
      expo[i][j] = ret;
      ret = (ret*i)%MOD;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= MAXL; j++) {
      f[j][0] += expo[j][calc[i][i]]*expo[j][tot-calc[i][i]];
      f[j][0] %= MOD;
    }
  }

  int spec = 0;
  for(int i = 1; i <= 11; i++) {
    spec += (12-i)*expo[4][i-i/2]*expo[4][11-i];
    spec %= MOD;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j+i <= n; j++) {
      int k = j+i-1;
      dp[j][k] = dp[j+1][k-1];
      calc[j][k] = calc[j+1][k-1];
      worth[j][k] = worth[j][k-1] + (s[k] == '?');
      if(s[j] == '?' && s[k] != '?')
        dp[j][k] |= 1 << (s[k] - 'a');
      if(s[j] != '?' && s[k] == '?')
        dp[j][k] |= 1 << (s[j] - 'a');
      if(s[j] == '?' && s[k] == '?')
        calc[j][k]++;
      if(s[j] != '?' && s[k] != '?' && s[j] != s[k])
        dp[j][k] = MAXM;

      //std::cout << j << " " << k << " " << worth[j][k] << std::endl;

      if(dp[j][k] < MAXM)
        for(int p = 1; p <= MAXL; p++) {
          f[p][dp[j][k]] += expo[p][tot-worth[j][k]]*expo[p][calc[j][k]];
          f[p][dp[j][k]] %= MOD;
        }
    }
  }

  for(int p = 1; p <= MAXL; p++) {
    for(int i = 0; i < MAXL; i++) {
      for(int j = 0; j < MAXM; j++) {
        if(j & (1 << i)) {
          f[p][j] += f[p][j^(1 << i)];
          f[p][j] %= MOD;
        }
      }
    }
  }

  int q;
  std::cin >> q;

  while(q--) {
    std::string qs;
    std::cin >> qs;

    int qb = 0;
    for(char c: qs) {
      qb |= 1 << (c-'a');
    }

    int sz = qs.length();
    std::cout << f[sz][qb] << "\n";
  }

  return 0;
}