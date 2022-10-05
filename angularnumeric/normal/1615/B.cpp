#include <bits/stdc++.h>
using namespace std;
int dp[200005][19];
int pow2[19];
int func(int l, int r) {
  if (l == r) return 0;
  int ans = INT_MAX;
  int pow2 = 1;
  for (int i = 0; i < 19; i++) {
    if (pow2 > r) break;
    int d = dp[r][i] - dp[l - 1][i];
    ans = min(ans, r - l + 1 - d);
    pow2 *= 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pow2[0] = 1;
  for (int i = 1; i < 19; i++) pow2[i] = pow2[i - 1] * 2;
  for (int i = 1; i <= 200000; i++) {
    for (int j = 0; j < 19; j++) {
      dp[i][j] = dp[i - 1][j];
      if (i & pow2[j]) dp[i][j]++;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << func(l, r) << '\n';
  }
}