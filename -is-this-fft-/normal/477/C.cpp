#include <iostream>

using namespace std;

const int MAX_N = 2e3 + 5;
const int MAX_M = 5e2 + 5;

int sfx [MAX_M][MAX_N];
int dp [MAX_N][MAX_N];
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  string s, p;
  cin >> s >> p;

  int n = s.size(), m = p.size();

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      sfx[i][j] = MAX_N;
    }
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == p[m - 1]) {
      sfx[m - 1][i] = i + 1;
    }
  }

  for (int k = m - 2; k >= 0; k--) {
    for (int i = n - 1; i >= 0; i--) {
      sfx[k + 1][i] = min(sfx[k + 1][i], sfx[k + 1][i + 1]);
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == p[k]) {
        sfx[k][i] = sfx[k + 1][i + 1];
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = MAX_N;
    }
  }

  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] < MAX_N) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        if (sfx[0][i] < MAX_N) {
          dp[sfx[0][i]][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + sfx[0][i] - i - m);
        }
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    if (dp[n][i] < MAX_N) {
      int lic = dp[n][i];
      for (int x = lic; x <= n - i * m; x++) {
        ans[x] = max(ans[x], i);
      }
    }
  }

  for (int x = 0; x <= n; x++) {
    cout << ans[x] << " ";
  }
  cout << endl;
}