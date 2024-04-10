#include <iostream>
#include <string>

using namespace std;

const int MAX_L = 55;
const int ALPHA = 130;
const int MAX_N = 1e3 + 5;
const int INF = 50000;

int nxt_s [MAX_L][ALPHA];
int nxt_t [MAX_L][ALPHA];
int dp [MAX_N][MAX_L][MAX_L];

int main () {
  ios::sync_with_stdio(false);

  string found;
  string s, t;
  cin >> found >> s >> t;

  for (int i = 0; i < (int) s.size(); i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      for (int j = 1; j < (int) s.size() && j <= i + 1; j++) {
        bool ok = true;
        for (int k = 0; k < j - 1; k++) {
          if (s[k] != s[k - (j - 2) + (i - 1)]) {
            ok = false;
          }
        }
        if (ok && s[j - 1] == c) {
          nxt_s[i][c] = j;
        }
      }
    }
  }

  for (int i = 0; i < (int) t.size(); i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      for (int j = 1; j < (int) t.size() && j <= i + 1; j++) {
        bool ok = true;
        for (int k = 0; k < j - 1; k++) {
          if (t[k] != t[k - (j - 2) + (i - 1)]) {
            ok = false;
          }
        }
        if (ok && t[j - 1] == c) {
          nxt_t[i][c] = j;
        }
      }
    }
  }

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_L; j++) {
      for (int k = 0; k < MAX_L; k++) {
        dp[i][j][k] = -INF;
      }
    }
  }

  dp[0][0][0] = 0;
  for (int i = 0; i < (int) found.size(); i++) {
    for (int j = 0; j < (int) s.size(); j++) {
      for (int k = 0; k < (int) t.size(); k++) {
        if (found[i] == '*') {
          for (char c = 'a'; c <= 'z'; c++) {
            int modif = (c == s.back() && j == (int) s.size() - 1 ? 1 : 0)
              - (c == t.back() && k == (int) t.size() - 1 ? 1 : 0);
            dp[i + 1][nxt_s[j][c]][nxt_t[k][c]] =
              max(dp[i + 1][nxt_s[j][c]][nxt_t[k][c]], dp[i][j][k] + modif);
          }
        } else {
          char c = found[i];
          int modif = (c == s.back() && j == (int) s.size() - 1 ? 1 : 0)
            - (c == t.back() && k == (int) t.size() - 1 ? 1 : 0);
          dp[i + 1][nxt_s[j][c]][nxt_t[k][c]] =
            max(dp[i + 1][nxt_s[j][c]][nxt_t[k][c]], dp[i][j][k] + modif);
        }
      }
    }
  }

  int ans = -INF;
  for (int j = 0; j < (int) s.size(); j++) {
    for (int k = 0; k < (int) t.size(); k++) {
      ans = max(ans, dp[(int) found.size()][j][k]);
    }
  }

  cout << ans << endl;
}