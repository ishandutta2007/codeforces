#include <iostream>

#define int long long

const int MAXN = 200005;

int dp[MAXN];
int a[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < MAXN; i++) {
      dp[i] = 0;
      a[i] = 0;
    }

    for(int j = 0; j < n; j++) {
      int x;
      std::cin >> x;
      a[x]++;
    }

    int ans = 0;
    for(int i = 1; i < MAXN; i++) {
      dp[i] += a[i];
      ans = std::max(ans, dp[i]);
      for(int j = 2*i; j < MAXN; j += i)
        dp[j] = std::max(dp[j], dp[i]);
    }


    std::cout << n-ans << std::endl;
  }

  return 0;
}