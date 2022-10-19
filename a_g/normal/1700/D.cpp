#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& x: v) cin >> x;
  vector<long long> s(n+1);
  for (int i = 0; i < n; i++) {
    s[i+1] = s[i] + v[i];
  }
  vector<long long> dp(n);
  // dp[x] = time to fill if first x+1 locks are open
  long long z = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = max(z, (s[n]+i)/(i+1));
    z = max(z, (s[i+1]+i)/(i+1));
  }

  int q;
  cin >> q;
  while (q--) {
    long long t;
    cin >> t;
    if (t < dp[n-1]) {
      cout << "-1\n";
      continue;
    }
    auto it = lower_bound(dp.begin(), dp.end(), t, greater<long long>());
    cout << it-dp.begin()+1 << '\n';
  }
}