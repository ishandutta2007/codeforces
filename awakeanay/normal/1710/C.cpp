#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MOD = 998244353;
const int INV2 = (MOD + 1)/2;
const int INV3 = (MOD + 1)/3;
const int MAXN = 200005;

int dp[8][3][MAXN];
std::vector<int> poss[3];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  poss[0] = {0, 7};
  poss[1] = {0, 3, 4, 7};
  poss[2] = {0, 2, 3, 4, 5, 7};

  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 3; j++)
      dp[i][j][0] = 1;

  std::string s;
  std::cin >> s;

  int n = s.length();
  std::reverse(s.begin(), s.end());
  int tot = 1;
  int cur = 1;
  for(int i = 1; i <= n; i++) {
    if(s[i-1] == '1') {
      tot += cur;
      tot %= MOD;
    }
    cur <<= 1;
    cur %= MOD;
    for(int j = 0; j < 8; j++) {
      for(int l = 0; l < 3; l++) {
        dp[j][l][i] = 0;
        for(int k : poss[l]) {
          if(k != 0 && k != 7)
            k ^= j&1;
          if((j&1) && (k&1) && s[i-1] == '0')
            continue;
          if((j&2) && (k&2) && s[i-1] == '0')
            continue;
          if((j&4) && (k&4) && s[i-1] == '0')
            continue;

          int nx = 0;
          int xo = s[i-1] == '1' ? 7 : 0;
          nx = (j & (k^xo^7));
          dp[j][l][i] = (dp[j][l][i] + dp[nx][l][i-1])%MOD;
        }
      }
    } 
  }

  tot = (((tot*tot)%MOD)*tot)%MOD;
  //std::cout << dp[7][n] << std::endl;
  int rem = dp[7][0][n];
  //std::cout << rem << std::endl;
  rem += (dp[7][1][n] - dp[7][0][n])*3 + 3*MOD;
  rem %= MOD;
  //std::cout << rem << std::endl;
  rem += (dp[7][2][n] - 2*dp[7][1][n] + 2*MOD + dp[7][0][n])*3;
  rem %= MOD;
  //std::cout << rem << std::endl;
  tot = (tot - rem + MOD)%MOD;

  std::cout << tot << std::endl;

  return 0;
}