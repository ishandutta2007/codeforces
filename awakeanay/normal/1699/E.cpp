#include <iostream>
#include <vector>

const int INF = 10'000'007;
const int MAXA = 5'000'006;

int dp[MAXA];
int pr[MAXA];
int ctn[MAXA];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= m; i++) {
      pr[i] = 0;
      dp[i] = INF;
      ctn[i] = 0;
    }

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      pr[x] = 1;
    }

    int ct = 0;
    for(int i = 1; i <= m; i++)
      ct += pr[i];

    int ans = m;
    int pos = INF;
    for(int i = m; i >= 1; i--) {
      dp[i] = i;
      if(pr[i]) {
        ctn[dp[i]]++;
        ct--;
      }
      
      int k = 2;
      for(int j = 2*i; j <= m; j += i) {
        if(pr[j])
          ctn[dp[j]]--;
        dp[j] = std::min(dp[j], std::max(i, dp[k++]));
        if(pr[j])
          ctn[dp[j]]++;
      }

      if(ct == 0) {
        pos = std::min(pos, m);
        while(!ctn[pos])
          pos--;
      }

      ans = std::min(pos-i, ans);
    }

    std::cout << ans << "\n";
  }

  return 0;
}