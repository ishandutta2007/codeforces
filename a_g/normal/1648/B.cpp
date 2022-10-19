#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    if (a[0] != 1) {
      cout << "No\n";
      continue;
    }
    bool good = 1;
    int prv = 0;
    vector<int> dp(c+2);
    vector<int> missing;
    for (int val: a) {
      for (int j = prv+1; j < val; j++) {
        missing.push_back(j);
      }
      prv = val;
    }
    for (int val: a) {
      for (int m: missing) {
        if (c+1 < 1LL*m*val) break;
        dp[m*val]++;
        dp[min<long long>(c+1, m*val+val)]--;
      }
    }
    for (int i = 1; i <= c; i++) {
      dp[i] += dp[i-1];
    }

    for (int val: a) {
      if (dp[val]) {
        good = 0;
        break;
      }
    }
    cout << (good ? "Yes" : "No") << '\n';
  }
}