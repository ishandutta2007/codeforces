#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

const int maxn = 2e6+5;
int dp[maxn];
int last[26];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 26; i++) last[i] = -1;
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  int m = t.size();

  dp[0] = 1;
  for (int i = 0; i < m; i++) {
    dp[i+1] = 2*dp[i] % MOD;
    int c = t[i]-'a';
    if (last[c] != -1) {
      dp[i+1] = (dp[i+1] + MOD - dp[last[c]]) % MOD;
    }
    last[c] = i;
  }

  vector<pair<int, int>> p;
  for (int i = 0; i < k; i++) {
    p.push_back({last[i], i});
  }
  sort(p.begin(), p.end());

  for (int i = 0; i < n; i++) {
    int j = i + m;
    dp[j+1] = 2*dp[j] % MOD;
    int c = p[i%k].second;
    if (last[c] != -1) {
      dp[j+1] = (dp[j+1] + MOD - dp[last[c]]) % MOD;
    }
    last[c] = j;
  }
  cout << dp[n+m] << endl;
}