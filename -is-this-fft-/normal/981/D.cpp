#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 60;

ll arr [MAX_N];
ll cum [MAX_N];
ll sumlr (int l, int r) {
  return cum[r] - cum[l - 1];
}

int n, k;
int dp [MAX_N][MAX_N]; // dp[i][j] --- is it possible to split into i pieces, last at pos j
bool can (ll prefix) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int p = 0; p < j; p++) {
        if (dp[i - 1][p] && (sumlr(p + 1, j) & prefix) == prefix) {
          dp[i][j] = 1;
        }
      }
    }
  }
  
  return dp[k][n];
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    cum[i] = cum[i - 1] + arr[i];
  }

  ll ans = 0;
  for (ll p = 1LL << 60; p != 0; p /= 2) {
    if (can(ans + p)) ans += p;
  }
  cout << ans << endl;
}