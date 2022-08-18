#include <iostream>

const int MAX_DAY = 105;
const int INF = 1023456789;

using namespace std;

int can [MAX_DAY][2];
int dp [MAX_DAY][2];

/* least rest days up to day i
 * if he does j on that day */

int main () {
  int dayc;
  cin >> dayc;

  for (int i = 0; i < dayc; i++) {
    int bm;
    cin >> bm;

    can[i][0] = (bm & 1) >> 0;
    can[i][1] = (bm & 2) >> 1;
  }

  for (int i = 0; i < MAX_DAY; i++) {
    dp[i][0] = INF;
    dp[i][1] = INF;
  }

  dp[0][0] = !can[0][0];
  dp[0][1] = !can[0][1];
  for (int i = 1; i < dayc; i++) {
    for (int j = 0; j < 2; j++) {
      if (can[i][j]) {
        dp[i][j] = dp[i - 1][!j] + !can[i][j];
      } else {
        dp[i][j] = min(dp[i - 1][!j] + 1, dp[i - 1][j] + 1);
      }
    }
  }
 
  cout << min(dp[dayc - 1][0], dp[dayc - 1][1]) << endl;
}