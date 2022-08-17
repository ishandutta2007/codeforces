#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 40004;
const int MOD = 1000'000'007;
const int MAXP = 505;

int checkPal(int x) {
  std::vector<int> dig;
  while(x > 0) {
    dig.push_back(x%10);
    x /= 10;
  }

  std::vector<int> rev = dig;
  std::reverse(rev.begin(), rev.end());
  return dig == rev;
}

int dp[2][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  int pal = 0;
  std::vector<int> pals;
  for(int i = 1; i < MAXN; i++) {
    if(checkPal(i)) {
      pals.push_back(i);
      pal++;
    }
  }

  for(int i = 0; i < MAXN; i++)
    dp[0][i] = 1;
  for(int j = 0; j < MAXP; j++)
    dp[j%2][0] = 1;

  for(int j = 1; j < pal; j++) {
    for(int i = 1; i < MAXN; i++) {
      dp[j%2][i] = dp[(j-1)%2][i];
      if(i-pals[j] >= 0)
        dp[j%2][i] = (dp[j%2][i] + dp[j%2][i-pals[j]])%MOD;
    }
  }

  while(t--) {
    int n;
    std::cin >> n;

    std::cout << dp[(pal-1)%2][n] << "\n";
  }

  return 0;
}