#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;

ll arr [MAX_N][3];
ll dp [MAX_N][3];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int k = 1; k <= 2; k++) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[i][k];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= 2; k++) {
      for (int l = 0; l <= 2; l++) {
        if (k != l){
          dp[i][k] = max(dp[i][k], dp[i - 1][l]);
        }
      }
      dp[i][k] += arr[i][k];
    }
  }

  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}