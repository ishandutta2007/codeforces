#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int C = 26;
// source: mango_lassi (https://codeforces.com/problemset/submission/1620/139809619)

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, C>> A(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c: s) {
      A[i][c-'a']++;
    }
  }
  vector<int> dp(1<<n, 1);
  dp[0] = 0;

  // compute the intersection sizes with a sign factor
  for (int mask = 1; mask < (1<<n); mask++) {
    array<int, C> intersection;
    for (int j = 0; j < C; j++) intersection[j] = 1e9;
    for (int i = 0; i < n; i++) {
      if ((mask>>i)&1) {
        for (int j = 0; j < C; j++) {
          intersection[j] = min(intersection[j], A[i][j]);
        }
      }
    }
    for (int val: intersection) {
      dp[mask] = 1LL * dp[mask] * (val+1) % MOD;
    }
    if (!(__builtin_popcount(mask) & 1)) dp[mask] = -dp[mask];
  }

  // cascade
  for (int b = 1; b < (1<<n); b<<=1) {
    for (int mask = 1; mask < (1<<n); mask++) {
      if (mask&b) {
        dp[mask] = (dp[mask] + dp[mask^b]) % MOD;
      }
    }
  }

  // compute
  ll ans = 0;
  for (int mask = 1; mask < (1<<n); mask++) {
    int k = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
      if ((mask>>i)&1) {
        k++;
        s+=i+1;
      }
    }
    dp[mask] = (dp[mask] + MOD) % MOD;
    ans ^= 1LL * k * s * dp[mask];
  }
  cout << ans << endl;
}