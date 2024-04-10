#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 705;
int pw[N];
int dp[N][2], ndp[N][2];
// (number of digits >= d, is already less than x)

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = 10LL*pw[i-1] % MOD;
  }
  for (int i = 1; i < N; i++) {
    add(pw[i], pw[i-1]);
  }

  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int d = 1; d < 10; d++) {
    // count contribution from digits equal to d
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k < 2; k++) {
          if (k == 1) {
            add(ndp[j+1][1], 1LL*(10-d)*dp[j][k] % MOD);
            add(ndp[j][1], 1LL*d*dp[j][k] % MOD);
          }
          else {
            for (int u = 0; u < s[i]-'0'; u++) {
              add(ndp[j+(u>=d)][1], dp[j][k]);
            }
            add(ndp[j+(s[i]-'0' >= d)][0], dp[j][k]);
          }
        }
      }

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
          dp[i][j] = ndp[i][j];
          ndp[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 2; j++) {
        if (i && dp[i][j]) {
          add(ans, 1LL*dp[i][j]*pw[i-1] % MOD);
        }
        dp[i][j] = 0;
      }
    }
  }
  cout << ans << '\n';
}