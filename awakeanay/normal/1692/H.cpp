#include <iostream>
#include <map>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> last;
    int a[n];
    int dp[n];
    int wh[n];
    int best = -1;
    int l = -1, r = -1;
    int x;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      dp[i] = 1;
      wh[i] = i;
      int prev = last[a[i]]-1;
      if(prev != -1) {
        int next = 1 - (i-prev-1) + dp[prev];
        if(next > dp[i]) {
          dp[i] = next;
          wh[i] = wh[prev];
        }
      }
      if(dp[i] > best) {
        x = a[i];
        l = wh[i]+1;
        r = i+1;
        best = dp[i];
      }
      last[a[i]] = i+1;
    }

    std::cout << x << " " << l << " " << r << std::endl;
  }

  return 0;
}