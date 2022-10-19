#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2005;
int dp[N][N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int half = inversemod(2, MOD);
  for (int i = 1; i < N; i++) {
    dp[i][i] = i;
    for (int j = 1; j < i; j++) {
      dp[i][j] = 1LL*half*(dp[i-1][j-1] + dp[i-1][j]) % MOD;
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << 1LL*k*dp[n][m]%MOD << '\n';
  }
}