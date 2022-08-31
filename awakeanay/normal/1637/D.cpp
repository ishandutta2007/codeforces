#include <iostream>

#define int long long

const int MAXN = 10005;

int calc(int a[], int n) {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      ans += (a[i] + a[j])*(a[i] + a[j]);
    }
  }
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n][2];
    int tot = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i][0];
      tot += a[i][0];
    }
    for(int j = 0; j < n; j++) {
      std::cin >> a[j][1];
      tot += a[j][1];
    }

    int dp[n+1][MAXN];
    dp[0][0] = 1;
    for(int j = 1; j < MAXN; j++)
      dp[0][j] = -1;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < MAXN; j++) {
        dp[i+1][j] = -1;
        for(int k = 0; k < 2; k++) {
          if(j - a[i][k] >= 0 && dp[i][j-a[i][k]] != -1)
            dp[i+1][j] = k;
        }
      }
    }

    int best = -1;
    for(int i = 0; i <= tot/2; i++) {
      if(dp[n][i] != -1)
        best = i;
    }

    int b[n], c[n];
    for(int i = n-1; i >= 0; i--) {
      b[i] = a[i][0];
      c[i] = a[i][1];
      if(dp[i+1][best])
        b[i] ^= c[i] ^= b[i] ^= c[i];
      best -= a[i][dp[i+1][best]];
    }

    std::cout << calc(b, n) + calc(c, n) << std::endl;
  }

  return 0;
}