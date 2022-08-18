#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 105;

pair<int, pair<int, int>> dp [MAX_N]; // <min #, <type of string, start pos>>

void solve () {
  string t;
  cin >> t;

  int n;
  cin >> n;
  
  vector<string> ss (n);
  for (int i = 0; i < n; i++) {
    cin >> ss[i];
  }

  int m = t.size();
  for (int i = 1; i <= m; i++) {
    dp[i] = {INF, {0, 0}};
  }
  dp[0] = {0, {0, 0}};

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if ((int) ss[j].size() <= i && t.substr(i - (int) ss[j].size(), ss[j].size()) == ss[j]) {
        int sta = i - (int) ss[j].size();
        dp[i] = min(dp[i], make_pair(1 + dp[sta].first, make_pair(j, sta)));
      }
    }

    for (int j = i - 1; j > 0; j--) {
      dp[j] = min(dp[j], dp[j + 1]);
    }
  }

  if (dp[m].first >= INF) {
    cout << -1 << '\n';
    return;
  }
  
  cout << dp[m].first << '\n';
  int cur = m;
  while (cur != 0) {
    cout << 1 + dp[cur].second.first << " " << 1 + dp[cur].second.second << '\n';
    cur = dp[cur].second.second;
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}