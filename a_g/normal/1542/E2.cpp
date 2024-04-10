#include <bits/stdc++.h>
using namespace std;

const int N = 502;
int dp[2][N*N];
long long ans[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, MOD;
  cin >> n >> MOD;
  dp[0][0] = dp[1][0] = 1;
  for (int m = 2; m < N; m++) {
    ans[m] = 1LL*m*ans[m-1];
    int c = ((m-1)*(m-2))/2;
    int k = 0;
    for (int d = 2; d <= c; d++) {
      k += max(m-d+1, 0);
      ans[m] += 1LL*k*dp[0][c-d];
    }
    ans[m] %= MOD;
    for (int z = 0; z < 2; z++) {
      for (int i = 1; i <= m*(m-1); i++) {
        dp[1-z][i] = dp[1-z][i-1]+dp[z][i]-(i>=m?dp[z][i-m]:0);
        if (dp[1-z][i] >= MOD) dp[1-z][i] -= MOD;
        if (dp[1-z][i] < 0) dp[1-z][i] += MOD;
      }
    }
  }

  cout << (ans[n]+MOD)%MOD << '\n';
}