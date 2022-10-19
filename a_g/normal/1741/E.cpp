#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> b(n), dp(n+1);
    for (int& x: b) cin >> x;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      // b[i] is the end of a segment
      if (b[i] <= i) dp[i+1] |= dp[i-b[i]];
      // b[i] is the start of a segment
      if (i+1+b[i] <= n) dp[i+1+b[i]] |= dp[i];
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
  }
}