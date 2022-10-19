#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      a[c-1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      vector<int> dp(2);
      for (int j: a[i]) {
        dp[j&1] = max(dp[j&1], 1+dp[1-j&1]);
      }
      cout << max(dp[0], dp[1]) << ' ';
    }
    cout << '\n';
  }
}