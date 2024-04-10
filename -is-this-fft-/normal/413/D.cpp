#include <iostream>

typedef long long llong;

const int MOD = 1000000007;
const int MAX_LENGTH = 3005;
const int MAX_BIT = 12;

using namespace std;

llong dp [MAX_LENGTH][1 << MAX_BIT];
int seq [MAX_LENGTH];

int main () {
  int length, target;
  cin >> length >> target;
  
  for (int i = 0; i < length; i++) {
    cin >> seq[i];
  }

  /* establish base cases */
  if (seq[0] == 2) {
    if (target <= 1) {
      dp[0][0] += 1;
    } else {
      dp[0][2] += 1;
    }  
  
  } else if (seq[0] == 4) {
    if (target <= 2) {
      dp[0][0] += 1;
    } else {
      dp[0][4] += 1;
    }
  
  
  } else if (seq[0] == 0) {
    if (target <= 1) {
      dp[0][0] += 1;
    } else {
      dp[0][2] += 1;
    }  

    if (target <= 2) {
      dp[0][0] += 1;
    } else {
      dp[0][4] += 1;
    }

  }

  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < 1 << MAX_BIT; j += 2) {
      if (j == 0) {
        if (seq[i + 1] == 0) {
          dp[i + 1][j] += 2 * dp[i][j];
          dp[i + 1][j] %= MOD;
        } else {
          dp[i + 1][j] += dp[i][j];
          dp[i + 1][j] %= MOD;
        }
      } else {
        if (seq[i + 1] == 2) {
          int nxt = j + 2;

          if (nxt & 1 << target) {
            dp[i + 1][0] += dp[i][j];
            dp[i + 1][0] %= MOD;
          } else {
            dp[i + 1][nxt] += dp[i][j];
            dp[i + 1][nxt] %= MOD;
          }
        } else if (seq[i + 1] == 4) {
          int nxt;
          if (j & 2) {
            nxt = 4;
          } else {
            nxt = j + 4;
          }

          if (nxt & 1 << target) {
            dp[i + 1][0] += dp[i][j];
            dp[i + 1][0] %= MOD;
          } else {
            dp[i + 1][nxt] += dp[i][j];
            dp[i + 1][nxt] %= MOD;
          }
        } else {
          int nxt = j + 2;

          if (nxt & 1 << target) {
            dp[i + 1][0] += dp[i][j];
            dp[i + 1][0] %= MOD;
          } else {
            dp[i + 1][nxt] += dp[i][j];
            dp[i + 1][nxt] %= MOD;
          }

          if (j & 2) {
            nxt = 4;
          } else {
            nxt = j + 4;
          }

          if (nxt & 1 << target) {
            dp[i + 1][0] += dp[i][j];
            dp[i + 1][0] %= MOD;
          } else {
            dp[i + 1][nxt] += dp[i][j];
            dp[i + 1][nxt] %= MOD;
          }
        }
      }
    }
  }

  cout << dp[length - 1][0] << endl;
}