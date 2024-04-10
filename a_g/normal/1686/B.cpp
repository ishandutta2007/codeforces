#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    for (int& x: a) cin >> x;
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i-1];
      if (a[i] < a[i-1]) {
        dp[i] = (i > 1 ? dp[i-2]+1 : 1);
      }
    }
    cout << dp[n-1] << '\n';
  }
}