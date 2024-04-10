#include <iostream>

#define int long long

const int INF = 1'000'000'000'000;
const int LOG = 20;
const int MAXN = 200005;

int next[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int i = 0; i < MAXN; i++) {
    for(int j = 0; j < LOG; j++) {
      if((1 << j) >= i) {
        next[i] = j;
        break;
      }
    }
  }

  while(t--) {
    int n;
    std::cin >> n;

    int a[n+1], pr[n+1];
    for(int i = 0; i < n; i++)
      a[i] = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      a[x]++;
    }

    for(int i = 0; i < n; i++) {
      pr[i] = a[i];
      if(i)
        pr[i] += pr[i-1];
    }

    int dp[n+1];
    dp[n] = 2;
    for(int i = n-1; i >= 0; i--) {
      dp[i] = INF;
      for(int j = 0; j < LOG; j++) {
        int lo = i, hi = n;
        while(lo < hi) {
          int mid = (lo+hi)/2;
          if(pr[mid]-(i > 0 ? pr[i-1] : 0) > (1 << j))
            hi = mid;
          else
            lo = mid+1;
        }

        lo--;

        int rem = pr[n-1]-(lo >= 0 ? pr[lo] : 0);
        int num = next[rem];

        dp[i] = std::min(dp[i], (1 << j) - ((lo >= 0 ? pr[lo] : 0) -(i > 0 ? pr[i-1] : 0)) + (1 << num) - rem);
      }
    }

    int ans = INF;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur += a[i];
      int num = next[cur];

      ans = std::min(ans, (1 << num) - cur + dp[i+1]);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}