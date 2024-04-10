#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 2005;

pair<int, int> dp[2*N]; // dp[N+i] = (#configurations, sum of dist over configs) where s_k-t_k = i
pair<int, int> tmp[2*N];

unordered_map<char, vector<int>> charvals;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  charvals['0'] = {0};
  charvals['1'] = {1};
  charvals['?'] = {0, 1};
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    
    dp[N] = {1, 0};
    for (int i = 0; i < n; i++) {
      int sign = (i&1 ? -1 : 1);
      for (int j = -N; j < N; j++) {
        if (!dp[j+N].first && !dp[j+N].second) continue;
        for (int u: charvals[s[i]]) {
          for (int v: charvals[t[i]]) {
            int newdiff = j+sign*(u-v);
            tmp[newdiff+N].first += dp[j+N].first;
            tmp[newdiff+N].first %= MOD;
            tmp[newdiff+N].second += (dp[j+N].second + 1LL * dp[j+N].first * abs(newdiff)) % MOD;
            tmp[newdiff+N].second %= MOD;
          }
        }
      }

      for (int j = -N; j < N; j++) {
        dp[j+N] = tmp[j+N];
        tmp[j+N] = make_pair(0, 0);
      }
    }

    cout << dp[N].second << '\n';

    for (int j = -N; j < N; j++) {
      dp[j+N] = make_pair(0, 0);
    }
  }
}