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
    for (int& x: a) cin >> x;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < min(n, i+256); j++) {
        if ((a[i]^j)<(a[j]^i)) {
          dp[j] = max(dp[j], dp[i]+1);
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}