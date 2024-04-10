#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 205;
const int MAX_K = 1005;
const int MOD = 1e9 + 7;

int _trash;
int _dp [MAX_N][MAX_N][MAX_K];
// position, # of open brackets, sum if all brackets ended here

int& dp (int i, int j, int k) {
  if (j < 0) {
    return _trash;
  }
  if (k >= MAX_K) {
    return _trash;
  }
  else return _dp[i][j][k];
}

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int length, maxd;
  cin >> length >> maxd;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + length);

  dp(0, 0, 0) = 1;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      for (int k = 0; k <= maxd; k++) {
        int dx = arr[i + 1] - arr[i];
        if (i + 1 == length) {
          dx = 0;
        }
        
        // open and close immediately
        dp(i + 1, j, k + dx * j) += dp(i, j, k);
        dp(i + 1, j, k + dx * j) %= MOD;

        // open
        dp(i + 1, j + 1, k + dx * (j + 1)) += dp(i, j, k);
        dp(i + 1, j + 1, k + dx * (j + 1)) %= MOD;

        // close
        dp(i + 1, j - 1, k + dx * (j - 1)) += ((ll) dp(i, j, k) * (ll) j) % MOD;
        dp(i + 1, j - 1, k + dx * (j - 1)) %= MOD;

        // assign to bracket
        dp(i + 1, j, k + dx * j) += ((ll) dp(i, j, k) * (ll) j) % MOD;
        dp(i + 1, j, k + dx * j) %= MOD;      
      }
    }
  }

  ll ans = 0;
  for (int k = 0; k <= maxd; k++) {
    // cout << dp(length, 0, k) << endl;
    ans += dp(length, 0, k);
    ans %= MOD;
  }

  cout << ans << endl;
}