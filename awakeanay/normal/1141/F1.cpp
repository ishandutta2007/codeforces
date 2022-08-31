#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int dp[n+1][n+1];
  std::pair<int, int> last[n+1][n+1];

  int a[n+1];
  a[0] = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i+1];
    a[i+1] += a[i];
  }

  int ans = 0;
  std::pair<int, int> alst = {-1, -1};

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      dp[i][j] = 1;
      last[i][j] = {-1, -1};
      for(int k = 1; k < i; k++) {
        for(int l = 1; l <= k; l++) {
          if(a[k] - a[l-1] == a[j] - a[i-1]) {
            if(dp[i][j] < dp[l][k] + 1) {
              dp[i][j] = dp[l][k]+1;
              last[i][j] = {l, k};
            }
          }
        }
      }
      if(dp[i][j] > ans) {
        ans = dp[i][j];
        alst = {i, j};
      }
    }
  }

  std::cout << ans << std::endl;
  int x = alst.first, y = alst.second;
  while(x != -1 && y != -1) {
    std::cout << x << " " << y << std::endl;
    int a = last[x][y].first;
    int b = last[x][y].second;
    x = a;
    y = b;
  }

  return 0;
}