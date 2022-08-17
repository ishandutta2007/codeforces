#include <iostream>

#define int long long

const int MAXA = 2005;
const int MAXN = 10004;
const int INF = 100004;

int dp[MAXN][MAXA];
int a[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < MAXA; i++) {
      if(a[n-1] <= i)
        dp[n-1][i] = 0;
      else
        dp[n-1][i] = a[n-1];
    }

    for(int i = n-2; i >= 0; i--) {
      for(int j = 0; j < MAXA; j++) {
        dp[i][j] = INF;
        if(a[i] <= j)
          dp[i][j] = std::min(dp[i][j], std::max(dp[i+1][j-a[i]]-a[i], 0ll));
        if(j + a[i] < MAXA)
          dp[i][j] = std::min(dp[i][j], dp[i+1][j+a[i]] + a[i]);
      }
    }

    int ans = INF;
    for(int i = 0; i < MAXA; i++)
      ans = std::min(dp[0][i] + i, ans);

    std::cout << ans << std::endl;
  }

  return 0;
}