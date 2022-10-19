#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

using state = pair<int, int>;
// first: number of operations
// second: number of ways
state operator + (const state& a, const state& b) {
  if (a.first != b.first) return min(a, b);
  return make_pair(a.first, (a.second+b.second)%MOD);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<int> occ;
    for (int i = 0; i < n; i++) {
      if (s.substr(i, m) == t) {
        occ.push_back(i);
      }
    }
    int k = (int)occ.size();
    vector<state> dp(k);
    for (int i = k-1; i >= 0; i--) {
      int limit = INF;
      dp[i].first = INF;
      for (int j = i+1; j < k; j++) {
        if (occ[j] >= limit) break;
        if (occ[j]-occ[i] < m) continue;
        limit = min(limit, occ[j]+m);
        dp[i] = dp[i]+dp[j];
      }
      if (dp[i].first == INF) dp[i] = make_pair(1, 1);
      else dp[i].first += 1;
    }
    int limit = 1e9;
    pair<int, int> ans = make_pair(INF, 0);
    for (int i = 0; i < k; i++) {
      if (occ[i] >= limit) break;
      limit = min(limit, occ[i]+m);
      ans = ans+dp[i];
    }
    if (ans.first == INF) ans = make_pair(0, 1);
    cout << ans.first << ' ' << ans.second << '\n';
  }
}