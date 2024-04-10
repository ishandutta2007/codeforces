#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 105;
const int INF = 1e9 + 5;

int arr [MAX_N];
int dp [MAX_N];
bool seen [MAX_N];

int get_mex (int l, int r) {
  int len = r - l + 1;
  for (int i = 0; i <= len; i++) {
    seen[i] = false;
  }

  for (int i = l; i <= r; i++) {
    if (arr[i] < MAX_N) {
      seen[arr[i]] = true;
    }
  }

  for (int i = 0; i <= len; i++) {
    if (!seen[i]) {
      return i;
    }
  }
  return 0;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = 0;
  for (int l = 0; l < n; l++) {
    dp[l] = 0;
    for (int i = l + 1; i <= n; i++) {
      dp[i] = 0;
    }

    for (int i = l + 1; i <= n; i++) {
      for (int k = l; k < i; k++) {
        dp[i] = max(dp[i], 1 + dp[k] + get_mex(k, i - 1));
      }
      ans += dp[i];
    }
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