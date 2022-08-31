#include <iostream>

using namespace std;

const int MAX_D = 1e3 + 100;
const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 5;

int dp [MAX_N];
int cdp [MAX_N];
int x [MAX_N], y [MAX_N], t [MAX_N];

bool can (int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]) <= abs(t[i] - t[j]);
}

int main () {
  int R, n;
  cin >> R >> n;

  x[0] = 1;
  y[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  cdp[0] = -INF;
  for (int i = 1; i <= n; i++) {
    dp[i] = -INF;
    if (can(0, i)) {
      dp[i] = 1;
    }

    for (int j = 1; j < MAX_D && 0 < i - j; j++) {
      if (can(i - j, i)) {
        dp[i] = max(dp[i], 1 + dp[i - j]);
      }
    }

    if (i - MAX_D > 0) {
      dp[i] = max(dp[i], 1 + cdp[i - MAX_D]);
    }

    cdp[i] = max(cdp[i - 1], dp[i]);
  }
  cout << max(0, cdp[n]) << '\n';
}