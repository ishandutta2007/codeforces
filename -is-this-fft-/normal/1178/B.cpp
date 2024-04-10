#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int MAX_L = 1000005;

ll dp [MAX_L][3];

int main () {
  string str;
  cin >> str;

  for (int i = 0; i < (int) str.size(); i++) {
    if (i != 0 && str[i] == 'v' && str[i - 1] == 'v') {
      dp[i + 1][0]++;
      dp[i + 1][2] += dp[i - 1][1];
    }

    if (i != 0 && str[i] == 'o') {
      dp[i + 1][1] += dp[i][0];
    }

    dp[i + 1][0] += dp[i][0];
    dp[i + 1][1] += dp[i][1];
    dp[i + 1][2] += dp[i][2];
  }

  cout << dp[(int) str.size()][2] << endl;
}