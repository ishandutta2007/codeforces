#include <bits/stdc++.h>
using namespace std;

const int N = 42;
int f[N], to[N][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int m = (int)s.size();
  vector<int> f(m+1);
  f[1] = 0;
  for (int i = 0; i < m; i++) {
    int c = s[i]-'0';
    f[i+1] = to[f[i]][c];
    to[i][c] = i+1;
    to[i][c^1] = to[f[i]][c^1];
  }

  long long ans = 1LL<<n;
  for (int i = 0; i < m; i++) {
    vector<long long> dp(m+1);
    dp[i] = 1;
    for (int j = 0; j < n; j++) {
      vector<long long> new_dp(m+1);
      for (int k = 0; k < m; k++) {
        for (int z: {0, 1}) {
          new_dp[to[k][z]] += dp[k];
        }
      }
      swap(dp, new_dp);
    }
    ans -= dp[i];
  }
  cout << ans << '\n';
}