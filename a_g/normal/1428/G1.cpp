#include <bits/stdc++.h>
using namespace std;

const int K = 6;
const int N = 1e6+2;
int pw[K];
long long dp[N], f[K];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < K; i++) pw[i] = 10*pw[i-1];
  fill(dp+1, dp+N, -1e18);
  int k;
  cin >> k;
  for (int i = 0; i < K; i++) {
    cin >> f[i];
    int num = 3*(k-1);
    for (int z = 1; num > 0; num -= z, z = min(2*z, num)) {
      int weight = 3*z*pw[i];
      if (weight >= N) break;
      long long val = z*f[i];
      for (int i = N-1; i >= weight; i--) {
        dp[i] = max(dp[i], dp[i-weight]+val);
      }
    }
  }

  for (int d = 0; d < K; d++) {
    for (int i = N-1; i >= 0; i--) {
      for (int b = 0; b < 10; b++) {
        int weight = b*pw[d];
        long long val = (b%3 == 0 ? f[d]*b/3 : 0);
        if (i < weight) break;
        dp[i] = max(dp[i], dp[i-weight]+val);
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
}