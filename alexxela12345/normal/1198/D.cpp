#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
int arr[MAXN][MAXN];
int pref[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int get(int x1, int x2, int y1, int y2) {
  return pref[x2 + 1][y2 + 1] + pref[x1][y1] - pref[x1][y2 + 1] - pref[x2 + 1][y1];
}

int main() {
  int n;
  cin >> n;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c;
      if (c == '#') {
        arr[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + arr[i - 1][j - 1];
    }
  }
  for (int lenx = 1; lenx <= n; lenx++) {
    for (int x1 = 0; x1 <= n - lenx; x1++) {
      int x2 = x1 + lenx - 1;
      for (int leny = 1; leny <= n; leny++) {
        for (int y1 = 0; y1 <= n - leny; y1++) {
          int y2 = y1 + leny - 1;
          if (x1 == 0 && x2 == 1 && y1 == 0 && y2 == 1) {
            //cout << "KEK" << endl;
          }
          dp[x1][x2][y1][y2] = max(x2 - x1, y2 - y1) + 1;
          if (get(x1, x1, y1, y2) == 0) {
            dp[x1][x2][y1][y2] = dp[x1 + 1][x2][y1][y2];
          } else if (get(x2, x2, y1, y2) == 0) {
            dp[x1][x2][y1][y2] = dp[x1][x2 - 1][y1][y2];
          } else if (get(x1, x2, y1, y1) == 0) {
            dp[x1][x2][y1][y2] = dp[x1][x2][y1 + 1][y2];
          } else if (get(x1, x2, y2, y2) == 0) {
            dp[x1][x2][y1][y2] = dp[x1][x2][y1][y2 - 1];
          } else {
            for (int i = x1 + 1; i < x2; i++) {
              if (get(i, i, y1, y2) == 0) {
                dp[x1][x2][y1][y2] = min(dp[x1][x2][y1][y2], dp[x1][i - 1][y1][y2] + dp[i + 1][x2][y1][y2]);
              }
            }
            for (int j = y1 + 1; j < y2; j++) {
              if (get(x1, x2, j, j) == 0) {
                dp[x1][x2][y1][y2] = min(dp[x1][x2][y1][y2], dp[x1][x2][y1][j - 1] + dp[x1][x2][j + 1][y2]);
              }
            }
          }
        }
      }
    }
  }
  cout << dp[0][n - 1][0][n - 1] << endl;
}