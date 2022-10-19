#include <bits/stdc++.h>
using namespace std;

const int T = 2e4+5;
const int N = 4005;
int* dp[2][T];
int dp2[2*N][N];
int ptr = 1;
vector<pair<int, int>> items[T];

void calc(int* a, int k) {
  for (auto& [c, h]: items[k]) {
    for (int i = N-1; i-c >= 0; i--) {
      a[i] = max(a[i], a[i-c]+h);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    int c, h, t;
    cin >> c >> h >> t;
    items[t].emplace_back(c, h);
  }
  for (int k = 0; k < T; k += p) {
    dp[0][k] = dp2[0];
    for (int z = 0; z < p && k+z < T; z++) {
      if (z) {
        dp[0][k+z] = dp[0][k+z-1];
      }
      if (items[k+z].size()) {
        for (int i = 0; i < N; i++) {
          dp2[ptr][i] = dp[0][k+z][i];
        }
        calc(dp2[ptr], k+z);
        dp[0][k+z] = dp2[ptr++];
      }
    }
    dp[1][k] = dp2[0];
    for (int z = 1; z < p && k-z >= 0; z++) {
      dp[1][k-z] = dp[1][k-z+1];
      if (items[k-z].size()) {
        for (int i = 0; i < N; i++) {
          dp2[ptr][i] = dp[1][k-z][i];
        }
        calc(dp2[ptr], k-z);
        dp[1][k-z] = dp2[ptr++];
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a-p+1 >= 0) {
      int ans = 0;
      for (int i = 0; i <= b; i++) {
        ans = max(ans, dp[1][a-p+1][i]+dp[0][a][b-i]);
      }
      cout << ans << '\n';
    }
    else {
      cout << dp[0][a][b] << '\n';
    }
  }
}