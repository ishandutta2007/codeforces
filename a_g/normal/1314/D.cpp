#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  const int maxn = 81;
  int dists[maxn][maxn];
  int c[maxn];
  srand(time(0));
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dists[i][j];
    }
  }
  int trials = 5000;
  int ans = 1e9;
  int dp[maxn];
  while (trials--) {
    vector<int> a = {0};
    vector<int> b;
    for (int i = 1; i < n; i++) {
      if (rand()&1) a.push_back(i);
      else b.push_back(i);
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++) dp[i] = 1e9;
    for (int i = 0; i < k/2; i++) {
      for (int z: b) dp[z] = 1e9;
      for (int x: a) {
        for (int y: b) {
          dp[y] = min(dp[y], dp[x] + dists[x][y]);
        }
      }
      for (int z: a) dp[z] = 1e9;
      for (int x: b) {
        for (int y: a) {
          dp[y] = min(dp[y], dp[x] + dists[x][y]);
        }
      }
    }
    ans = min(ans, dp[0]);
  }
  cout << ans << endl;
}