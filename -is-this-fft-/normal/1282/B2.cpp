#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

typedef long long ll;

int arr [MAX_N];
ll dp [MAX_N];

void solve () {
  int n, money, k;
  cin >> n >> money >> k;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  sort(arr + 1, arr + n + 1);

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = arr[i] + dp[i - 1];
    if (i >= k) {
      dp[i] = min(dp[i], arr[i] + dp[i - k]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[i] <= money) {
      ans = i;
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}