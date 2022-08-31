#include <iostream>
#include <vector>

#define int long long

const int MAXN = 3005;

int dp[MAXN][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int last = -1;
    std::vector<int> a;
    int m = n;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      if(x != last)
        a.push_back(x);
      last = x;
    }

    n = a.size();
    std::vector<int> next(m, n+1), nt(n, 0);
    for(int i = n-1; i >= 0; i--) {
      nt[i] = next[a[i]];
      next[a[i]] = i;
    }

    for(int j = 2; j <= n; j++) {
      for(int i = 0; i+j <= n; i++) {
        int k = i+j-1;
        dp[i][k] = dp[i+1][k];
        int nex = nt[i];
        while(nex <= k) {
          dp[i][k] = std::max(dp[i][k], dp[i+1][nex] + dp[nex][k] + 1);
          dp[i][k] = std::max(dp[i][k], dp[i][nex-1] + dp[nex][k] + 1);
          nex = nt[nex];
        }
      }
    }

    std::cout << n-1-dp[0][n-1] << std::endl;
  }

  return 0;
}