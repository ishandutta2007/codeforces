#include <bits/stdc++.h>
using namespace std;

const int N = 120;
long long dp[N][N];

long long f(long long t, int x, int y) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = t;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i+1 < N) dp[i+1][j] += dp[i][j]/2;
      if (j+1 < N) dp[i][j+1] += (dp[i][j]+1)/2;
    }
  }
  return dp[x][y];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long t;
    int x, y;
    cin >> t >> x >> y;
    t -= x+y;
    if (t < 0) {
      cout << "NO\n";
      continue;
    }
    cout << (f(t+1, x, y) > f(t, x, y) ? "YES" : "NO") << '\n';
  }
}