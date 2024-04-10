#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, color;
    cin >> n;
    vector<int> a;
    int current = 0;
    map<int, vector<int>> locations;
    for (int i = 0; i < n; i++) {
      cin >> color;
      a.push_back(color);
      locations[color].push_back(i);
    }
    n = a.size();
    int dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int d = 1; d <= n-1; d++) {
      for (int i = 0; i < n-d; i++) {
        int ans = 1+dp[i+1][i+d];
        for (int k: locations[a[i]]) {
          if (k > i && k <= i+d) {
            ans = min(ans, dp[i][k-1] + dp[k][i+d]);
          }
        }
        dp[i][i+d] = ans;
      }
    }
    cout << dp[0][n-1] << endl;
  }
}