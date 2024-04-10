#include <iostream>
#include <vector>

using namespace std;

const int A = 26;
const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 5;

int dp [MAX_N][2][2]; // pos, repl prev, repl cur

void solve () {
  string s;
  cin >> s;

  int n = s.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = MAX_N;
      }
    }
  }
  
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int prv = 0; prv < 2; prv++) {
      for (int cur = 0; cur < 2; cur++) {
        bool must = false;
        if (i >= 2 && s[i - 2] == s[i] && !prv) {
          must = true;
        }
        if (i >= 1 && s[i - 1] == s[i] && !cur) {
          must = true;
        }

        dp[i + 1][cur][1] = min(dp[i + 1][cur][1], dp[i][prv][cur] + 1);
        if (!must) {
          dp[i + 1][cur][0] = min(dp[i + 1][cur][0], dp[i][prv][cur]);
        }
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ans = min(ans, dp[n][i][j]);
    }
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}