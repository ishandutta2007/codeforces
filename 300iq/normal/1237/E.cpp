#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1e6 + 7;
const int M = 998244353;

int dp[N][2];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> small(n + 1);
  dp[0][0] = dp[0][1] = 1;
  vector <int> ans;
  ans.push_back(0);
  for (int i = 1; i <= n; i++) {
    small[i] = i + small[(i - 1) / 2] + small[i / 2];
    for (int t = 0; t < 2; t++) {
      for (int j : ans) {
        if (small[i] == i + small[j] + small[i - 1 - j] && j % 2 == t) {
          dp[i][t] += (dp[j][t ^ 1] * (ll) dp[i - 1 - j][1]) % M;
          if (dp[i][t] >= M) {
            dp[i][t] -= M;
          }
        }
      }
    }
    if (dp[i][0] || dp[i][1]) {
      ans.push_back(i);
    }
  }
  cout << (dp[n][0] + dp[n][1]) % M << endl;
}