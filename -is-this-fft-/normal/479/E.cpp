#include <iostream>

typedef long long llong;

const int MAX_FLOOR = 5005;
const int MOD = 1000000007;

using namespace std;

llong dp [MAX_FLOOR][MAX_FLOOR]; /* # of paths with i jumps to floors 0...j */

int main () {
  int floorc, begin, secret, jumpc;
  cin >> floorc >> begin >> secret >> jumpc;
  begin--;
  secret--;

  for (int i = begin; i < floorc; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i <= jumpc; i++) {
    for (int j = 0; j < floorc; j++) {
      if (j != 0) {
        dp[i][j] = dp[i][j - 1];
      }

      if (j < secret) {
        dp[i][j] += dp[i - 1][(j + secret - 1) / 2];
        dp[i][j] %= MOD;

        dp[i][j] -= dp[i - 1][j];
        dp[i][j] += MOD;
        dp[i][j] %= MOD;

        if (j != 0) {
          dp[i][j] += dp[i - 1][j - 1];
          dp[i][j] %= MOD;
        }
      } else if (j > secret) {
        dp[i][j] += dp[i - 1][floorc - 1];
        dp[i][j] %= MOD;

        dp[i][j] -= dp[i - 1][(j + secret) / 2];
        dp[i][j] += MOD;
        dp[i][j] %= MOD;

        dp[i][j] -= dp[i - 1][j];
        dp[i][j] += MOD;
        dp[i][j] %= MOD;

        if (j != 0) {
          dp[i][j] += dp[i - 1][j - 1];
          dp[i][j] %= MOD;
        }
      }
    }
  }

  cout << dp[jumpc][floorc - 1] << endl;
}