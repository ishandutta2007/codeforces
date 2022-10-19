#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 5005;
int binom[N][N];
int freq[N];
int dp[N][N];
// dp[i][j] = number of ways to place all blocks of size >= k such that exactly
// j of them are in even positions

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  binom[0][0] = 1;
  for (int i = 1; i < N; i++) {
    binom[i][0] = 1;
    for (int j = 1; j < N; j++) {
      binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      freq[a[i]]++;
    }

    dp[n+1][0] = 1;
    int tot = 0;
    for (int i = n; i >= 1; i--) {
      int f = freq[i];
      for (int j = 0; j <= n/2; j++) {
        // case 1: use an even position
        int odd_positions = max(2*j-1-tot, 0);
        if (j == n/2) odd_positions = n-tot;
        if (f) {
          dp[i][j+1] += 1LL * dp[i+1][j] * binom[odd_positions][f-1] % MOD;
          dp[i][j+1] %= MOD;
        }
        // case 2: don't
        dp[i][j] += 1LL * dp[i+1][j] * binom[odd_positions][f] % MOD;
        dp[i][j] %= MOD;
      }
      tot += f;
    }

    /*
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j <= n/2; j++) {
        cout << i << " " << j << " " << dp[i][j] << '\n';
      }
    }
    */

    cout << dp[1][n/2] << '\n';
    fill(freq+1, freq+n+1, 0);
    for (int i = 1; i <= n+1; i++) {
      fill(dp[i], dp[i]+n+1, 0);
    }
  }
}