#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    long long s1 = 0, s2 = 0;
    for (pair<int, int>& p: a) {
      cin >> p.first >> p.second;
      s1 += p.first;
      s2 += p.second;
    }
    vector<pair<long long, long long>> dp(n+1); // min fish, max fish
    for (int i = 0; i < n; i++) {
      dp[i+1] = dp[i];
      dp[i+1].first += max(0, m-a[i].second);
      dp[i+1].second += min(m, a[i].first);
    }
    function<long long(long long)> calc = [&] (long long x) {
      return (s1-x)-(s2-(1LL*m*n-x));
    };
    long long target = 0;
    long long d1 = calc(dp[n].first);
    long long d2 = calc(dp[n].second); 
    if (d1 >= 0 && d2 <= 0) {
      target = (1LL*m*n+s1-s2)/2;
      if (target < dp[n].first) target++;
      if (target > dp[n].second) target--;
    }
    else {
      target = (abs(d1) > abs(d2) ? dp[n].second : dp[n].first);
    }
    cout << abs(calc(target)) << '\n';
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--) {
      for (int v: {max(0, m-a[i].second), min(m, a[i].first), (int)(target-dp[i].first), (int)(target-dp[i].second)}) {
        if (v >= 0 && v <= min(a[i].first, m) && a[i].second >= m-v && dp[i].first <= target-v && target-v <= dp[i].second) {
          ans[i] = v;
          target -= v;
          break;
        }
      }
    }
    for (int& x: ans) {
      cout << x << " " << m-x << '\n';
    }
  }
}