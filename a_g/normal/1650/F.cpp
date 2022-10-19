#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1e6;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<tuple<int, int, int>>> options(n);
    for (int i = 1; i <= m; i++) {
      int e, t, p;
      cin >> e >> t >> p;
      options[e-1].emplace_back(t, p, i);
    }

    bool fail = 0;
    vector<int> ans;
    long long time = 0;
    for (int i = 0; i < n; i++) {
      vector<pair<long long, vector<int>>> dp(101, make_pair(INF, vector<int>()));
      dp[0] = make_pair(0, vector<int>());
      // percentage -> (best time, task list)
      for (tuple<int, int, int>& op: options[i]) {
        int t, p, j;
        tie(t, p, j) = op;
        for (int k = 99; k >= 0; k--) {
          if (get<0>(dp[k]) + t < get<0>(dp[min(100, k+p)])) {
            dp[min(100, k+p)] = make_pair(dp[k].first + t, dp[k].second);
            dp[min(100, k+p)].second.push_back(j);
          }
        }
      }
      if (time + get<0>(dp[100]) > a[i]) {
        fail = 1;
        break;
      }
      time += get<0>(dp[100]);
      ans.insert(ans.end(), dp[100].second.begin(), dp[100].second.end());
    }

    if (fail) {
      cout << "-1\n";
      continue;
    }
    cout << ans.size() << '\n';
    for (int i: ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}