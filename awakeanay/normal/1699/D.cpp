#include <iostream>
#include <vector>

const int MAXN = 5005;

int st[MAXN][MAXN];
int dp[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int ans = 0;
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i]--;
    }

    for(int i = 0; i < n; i++) {
      std::vector<int> ct(n, 0);
      int max = 0;
      for(int j = i; j < n; j++) {
        ct[a[j]]++;
        max = std::max(max, ct[a[j]]);
        st[i][j] = max;
      }
    }

    for(int i = 0; i < n; i++) {
      dp[i] = -n;
      for(int j = i-1; j >= 0; j -= 2) {
        if(a[j] == a[i] && (j == i-1 || 2*st[j+1][i-1] <= i-j-1))
          dp[i] = std::max(dp[i], dp[j] + 1);
      }
      if(i%2 == 0 && (i == 0 || 2*st[0][i-1] <= i))
        dp[i] = std::max(dp[i], 1);
    }
    for(int j = n-1; j >= 0; j -= 2) {
      if(j == n-1 || (2*st[j+1][n-1] <= n-j-1)) {
        ans = std::max(ans, dp[j]);
      }
    }

    std::cout << ans << "\n";
  }

  return 0;
}