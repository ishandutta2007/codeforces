#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end());

    vector<pair<int, int>> segments;
    segments.reserve(m);
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      auto it = lower_bound(a.begin(), a.end(), l);
      if (it != a.end() && *it <= r) continue;
      segments.emplace_back(l, r);
    }
    sort(segments.begin(), segments.end(), greater<pair<int, int>>());
    vector<pair<int, int>> key_segments;
    int r = 1e9+1;
    for (pair<int, int>& seg: segments) {
      if (seg.second >= r) continue;
      key_segments.emplace_back(seg);
      r = seg.second;
    }
    reverse(key_segments.begin(), key_segments.end());
    segments = key_segments;
    m = segments.size();

    vector<long long> dp(m+1, INF);
    dp[0] = 0;

    pair<int, int> pre = make_pair(0, 0);
    while (pre.second < m && segments[pre.second].second < a[0]) {
      pre.second++;
    }
    for (int i = 0; i < n; i++) {
      pair<int, int> interval = make_pair(pre.second, pre.second);
      if (i == n-1) interval.second = m;
      else {
        while (interval.second < m && segments[interval.second].second < a[i+1]) {
          interval.second++;
        }
      }
      long long best1 = INF;
      long long best2 = INF;
      for (int j = pre.first; j < pre.second; j++) {
        best1 = min(best1, dp[j]+a[i]-2*segments[j].second);
        best2 = min(best2, dp[j]-a[i]-segments[j].second);
      }
      for (int j = interval.first+1; j <= interval.second; j++) {
        dp[j] = min({dp[interval.first] + segments[j-1].first-a[i],
          best1 + segments[j-1].first,
          best2 + 2*segments[j-1].first
          });
      }
      for (int j = pre.first; j < pre.second; j++) {
        dp[interval.first] = min(dp[interval.first], dp[j]+a[i]-segments[j].second);
      }
      pre = interval;
    }

    cout << dp[m] << '\n';
  }
}