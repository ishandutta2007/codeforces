#include <iostream>
#define MAX_Q 100005

using namespace std;

int result [MAX_Q];
int dp [MAX_Q][3];

int main () {
  int length;
  cin >> length;

  char c;
  for (int i = 0; i < length; i++) {
    cin >> c;
    result[i] = c - '0';
  }

  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[0][2] = 0;

  for (int i = 1; i < length; i++) {
    if (result[i-1] != result[i]) {
      dp[i][0] = dp[i-1][0] + 1;
      dp[i][1] = dp[i-1][1] + 1;
      dp[i][2] = dp[i-1][2] + 1;
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = max(dp[i-1][1], dp[i-1][0] + 1);
      dp[i][2] = max(dp[i-1][2], dp[i-1][1] + 1);
    }
  }

  cout << max(dp[length-1][1], dp[length-1][2]) << endl;
}