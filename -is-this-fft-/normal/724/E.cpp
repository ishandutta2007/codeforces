#include <iostream>

using namespace std;

const int MAX_N = 10005;

typedef long long ll;

ll incoming [MAX_N];
ll outgoing [MAX_N];
ll dp [2][MAX_N];

int main () {
  int length;
  ll cap;

  cin >> length >> cap;
  for (int i = 1; i <= length; i++) {
    cin >> incoming[i];
  }

  for (int i = 1; i <= length; i++) {
    cin >> outgoing[i];
  }

  for (int i = 1; i <= length; i++) {
    dp[i % 2][0] = dp[!(i % 2)][0] + incoming[i];
    for (int j = 1; j < i; j++) {
      dp[i % 2][j] = min(dp[!(i % 2)][j - 1] + outgoing[i],
                         dp[!(i % 2)][j] + incoming[i] + cap * j);
    }
    dp[i % 2][i] = dp[!(i % 2)][i - 1] + outgoing[i];

    /*
    for (int j = 0; j <= i; j++) {
      cout << dp[i % 2][j] << " ";
    }
    cout << endl;
    */
  }

  ll ans = 1LL << 60;
  for (int i = 0; i <= length; i++) {
    ans = min(ans, dp[length % 2][i]);
  }
  cout << ans << endl;
}