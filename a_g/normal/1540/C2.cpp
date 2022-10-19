#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 104;
int b[3][N], c[N];
int dp[N][N*N]; // (i, pref_i) -> count
int ans[N];
int n;

int calc(int x) {
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i-1][0];
    for (int j = 1; j <= i*N; j++) {
      dp[i][j] = (0LL + dp[i][j-1] + dp[i-1][j] + (j >= c[i]+1 ? -dp[i-1][j-c[i]-1] : 0)) % MOD;
    }
    int low = i*x+b[2][i-1];
    for (int j = 0; j < min(low, N*N); j++) {
      dp[i][j] = 0;
    }
  }

  int ans = 0;
  for (int j = 0; j <= n*N; j++) {
    ans = (ans+dp[n][j]) % MOD;
  }
  return (ans+MOD)%MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 0; i < n-1; i++) {
    cin >> b[0][i];
    b[1][i+1] = b[1][i] + b[0][i];
    b[2][i+1] = b[2][i] + b[1][i+1];
  }

  int mn = N;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, -(b[2][i-1]/i)-1);
  }

  for (int i = 0; i < N; i++) {
    ans[i] = calc(mn+i);
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[max(0, min(N-1, x-mn))] << '\n';
  }
}