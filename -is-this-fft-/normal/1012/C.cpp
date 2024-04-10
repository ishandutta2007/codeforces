#include <iostream>
#include <assert.h>

using namespace std;

typedef long long llong;

const int MAX_N = 5005;

llong arr [MAX_N];
llong dp [MAX_N][MAX_N][2];

const llong INF = 1023456789;

int main () {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  
  int hillc;
  cin >> hillc;

  for (int i = 1; i <= hillc; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i <= hillc; i++) {
    dp[i][0][0] = 0;
  }

  for (int i = 1; i <= hillc; i++) {
    for (int j = 1; j <= hillc; j++) {
      if (i - 2 >= 0) {
        dp[i][j][1] = dp[i - 2][j - 1][1]
          + max(0LL, min(arr[i - 1], arr[i - 2] - 1) - (arr[i] - 1))
          + max(0LL, arr[i + 1] - (arr[i] - 1));
      } else if (j == 1) {
        dp[i][j][1] = max(0LL, arr[i - 1] - (arr[i] - 1))
          + max(0LL, arr[i + 1] - (arr[i] - 1));
      }

      if (i - 2 >= 0) {
        dp[i][j][1] = min(dp[i][j][1],
                          dp[i - 2][j - 1][0]
                          + max(0LL, arr[i - 1] - (arr[i] - 1))
                          + max(0LL, arr[i + 1] - (arr[i] - 1)));
      } else if (j == 1) {
        dp[i][j][1] = min(dp[i][j][1],
                          + max(0LL, arr[i - 1] - (arr[i] - 1))
                          + max(0LL, arr[i + 1] - (arr[i] - 1)));
      }

      dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
    }
  }

  for (int i = 1; i <= (hillc + 1) / 2; i++) {
    cout << min(dp[hillc][i][0], dp[hillc][i][1]) << " ";
  }
  cout << endl;
}