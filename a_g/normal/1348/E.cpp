#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int INF = 1e9;
long long dp[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;

  int rem = 0;
  for (int i = 0; i < n; i++) {
    int s = a[i]+b[i];
    for (int x = 0; x <= min(a[i], k-1); x++) {
      int y = (s-x)%k;
      if (y <= b[i]) {
        for (int z = 0; z < k; z++) {
          int w = (rem-z < 0 ? rem-z+k : rem-z);
          int ex = (x+z >= k) + (y+w >= k);
          dp[i+1][(x+z >= k ? x+z-k : x+z)] = max(dp[i+1][(x+z >= k ? x+z-k : x+z)], dp[i][z]+ex+(s-x-y)/k);
        }
      }
    }
    rem = (rem+s)%k;
  }

  long long ans = 0;
  for (int j = 0; j < k; j++) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans << '\n';
}