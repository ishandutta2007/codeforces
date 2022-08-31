#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;

int dp [MAX_N];

int main () {
  string str;
  cin >> str;

  dp[0] = 1;
  for (int i = 0; i < (int) str.size(); i++) {
    if (str[i] == 'm' || str[i] == 'w') {
      cout << 0 << endl;
      return 0;
    }

    if ((str[i] == 'n' || str[i] == 'u') && i != 0 && str[i - 1] == str[i]) {
      dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
    } else {
      dp[i + 1] = dp[i];
    }
  }

  cout << dp[str.size()] << endl;
}