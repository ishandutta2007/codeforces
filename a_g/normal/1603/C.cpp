#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e5+5;

int dp[2][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[n-1-i];
    int ans = 0;
    dp[0][a[0]]++;
    for (int i = 1; i < n; i++) {
      for (int j = a[i-1]; j >= 1; j = min(j-1, a[i-1]/(a[i-1]/j+1))) {
        int c = dp[1-i&1][j];
        int l = (a[i]-1)/j+1;
        int y = a[i]/l;
        ans = (ans + 1LL*c*(n-i)*(l-1)) % MOD;
        dp[i&1][y] = (dp[i&1][y]+c) % MOD;
        dp[1-i&1][j] = 0;
      }
      dp[i&1][a[i]]++;
    }
    for (int j = a[n-1]; j >= 1; j = min(j-1, a[n-1]/(a[n-1]/j+1))) {
      dp[1-n&1][j] = 0;
    }
    cout << ans << '\n';
  }
}