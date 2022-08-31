#include <iostream>
#include <vector>
#include <set>

#define int long long

const int MOD = 998244353;

int fl(int x, int y) {
  return x/y;
}

int cl(int x, int y) {
  return x/y + (x%y != 0);
}

const int MAXN = 10000;

int dp[2][MAXN];
int able[2][MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int ans = 0;
    int sz[2];

    for(int i = n-1; i >= 0; i--) {
      int l1 = a[i], l2 = a[i];
      int last = 1;
      int m = i&1;

      int it = 0;
      while(last <= a[i]) {
        able[m][it] = last;
        dp[m][it++] = 0;
        if(last == a[i])
          break;
        int k = (a[i] + last - 1)/last;
        last = (k == 1 ? a[i] : (a[i]-1)/(k-1)) + 1;
      }

      sz[m] = it;

      int test = 0;
      if(i+1 < n) {
        for(int j = 0; j < sz[m^1]; j++) {
          while(fl(a[i+1], able[m^1][j]) < cl(a[i], able[m][test])) {
            test++;
          }

          dp[m][test] = (dp[m][test] + dp[m^1][j])%MOD;
          ans = (ans + dp[m^1][j]*(i+1)*(able[m][test]-1))%MOD;
        }
      }

      dp[m][0] = (dp[m][0] + 1)%MOD;

    }

    std::cout << ans << std::endl;
  }

  return 0;
}