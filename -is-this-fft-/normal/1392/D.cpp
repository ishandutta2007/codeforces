#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int dp [MAX_N][2][2][2][2];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    if (c == 'R') {
      arr[i] = 1;
    } else {
      arr[i] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 2; c++) {
          for (int d = 0; d < 2; d++) {
            dp[i][a][b][c][d] = MAX_N + 5;
          }
        }
      }
    }
  }
  
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      dp[1][a][b][a][b] = (int) (arr[0] != a) + (int) (arr[1] != b);
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 2; c++) {
          for (int d = 0; d < 2; d++) {
            for (int e = 0; e < 2; e++) {
              if (!(c == d && d == e)) {
                dp[i + 1][a][b][d][e] = min(dp[i + 1][a][b][d][e],
                                            dp[i][a][b][c][d] + (int) (arr[i + 1] != e));
              }
            }
          }
        }
      }
    }
  }

  int ans = MAX_N + 5;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      for (int c = 0; c < 2; c++) {
        for (int d = 0; d < 2; d++) {
          if (!(c == d && d == a)) {
            if (!(d == a && a == b)) {
              ans = min(ans, dp[n - 1][a][b][c][d]);
            }
          }
        }
      }
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