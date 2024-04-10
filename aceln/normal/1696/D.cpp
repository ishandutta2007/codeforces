#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, 1000000000)); // mn, mx
    vector<int> mn = {0, 1}, mx = {0, 1};
    dp[1][0] = dp[1][1] = 0;
    for (int i = 2; i <= n; i++) {
      while (mn.back() > 0 && a[mn.back()] > a[i])
        mn.pop_back();
      while (mx.back() > 0 && a[mx.back()] < a[i])
        mx.pop_back();
      auto tmp = upper_bound(mx.begin(), mx.end(), mn.back());
      if (tmp != mx.end()) {
        dp[i][0] = dp[*tmp][1] + 1;
      } else {
        tmp = upper_bound(mn.begin(), mn.end(), mx.back());
        dp[i][1] = dp[*tmp][0] + 1;
      }
      mn.emplace_back(i);
      mx.emplace_back(i);
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
  }
}