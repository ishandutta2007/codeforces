#include <iostream>

#define int long long
int dp[2][5001][2];

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::string s, t;
  std::cin >> s >> t;

  for(int i = 0; i <= n; i++) {
    int l = i%2;
    for(int j = 0; j <= m; j++) {
      for(int k = 0; k < 2; k++) {
        dp[l][j][k] = 0;
        if(i)
          dp[l][j][k] = std::max(dp[l][j][k], dp[1-l][j][k] - (k==1));
        if(j)
          dp[l][j][k] = std::max(dp[l][j][k], dp[l][j-1][k] - (k==1));
        if(i && j && s[i-1] == t[j-1])
          dp[l][j][k] = std::max(dp[l][j][k], dp[1-l][j-1][1]+2);
      }
    }
  }

  std::cout << dp[n%2][m][0] << std::endl;

  return 0;
}