#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 5e4 + 5;

ll arr [MAX_N];
int dp [MAX_N][4];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  ll x;
  cin >> x;
  
  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    arr[i] -= x * i;
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
    for (int k = 0; k < 4; k++) {
      dp[i][0] = max(dp[i][0], dp[i - 1][k]);
    }

    dp[i][1] = 1 + dp[i - 1][0];

    if (i >= 2 && arr[i] >= arr[i - 2]) {
      dp[i][2] = 1 + dp[i - 1][1];
    } else {
      dp[i][2] = 0;
    }

    if (i >= 3 && arr[i] >= arr[i - 2] && arr[i] >= arr[i - 3]) {
      dp[i][3] = 1 + max(dp[i - 1][2], dp[i - 1][3]);
    } else {
      dp[i][3] = 0;
    }
  }

  int ans = 0;
  for (int k = 0; k < 4; k++) {
    ans = max(ans, dp[n][k]);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}