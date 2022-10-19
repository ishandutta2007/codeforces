#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end());
  vector<int> dp(n);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    int l = -1;
    int r = i;
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      if (arr[m].first >= arr[i].first - arr[i].second) {
        r = m; 
      } else {
        l = m;
      }
    }
    dp[i] = (i - r);
    if (r != 0)
      dp[i] += dp[r - 1];
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    ans = min(ans, n - i - 1 + dp[i]);
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}