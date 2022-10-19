#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<pair<int, int>> dp(n+1);
  for (int i = 0; i < n; i++) {
    dp[i+1] = dp[i];
    if (s[i] == '0' && s[i+1] == '0') {
      dp[i+1].first++;
    }
    if (s[i] == '1' && s[i+1] == '1') {
      dp[i+1].second++;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << 1 + max(dp[r-1].second-dp[l-1].second, dp[r-1].first-dp[l-1].first) << '\n';
  }
}