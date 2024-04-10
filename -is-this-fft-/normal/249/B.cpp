#include <iostream>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 1 << 19;

int n;
int right_home;
int surplus [MAX_N];

int dp [MAX_N];
int get_min_time (int add) {
  dp[0] = 0;
  int m3dp = 0, m2dp = 0;
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    if (add + surplus[i] < 0) {
      dp[i] = INF;
      continue;
    }

    dp[i] = dp[i - 1] + 1;
    dp[i] = min(dp[i], 3 * i + m3dp - 2);
    if (i >= right_home) {
      dp[i] = min(dp[i], 2 * i + m2dp - 1);
      ans = min(ans, dp[i]);
    }

    m3dp = min(m3dp, dp[i] - 3 * i);
    m2dp = min(m2dp, dp[i] - 2 * i);
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int T;
  cin >> n >> T;

  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') {
      right_home = i + 1;
      surplus[i + 1] = -1;
    } else if (s[i] == 'S') {
      surplus[i + 1] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    surplus[i] += surplus[i - 1];
  }

  if (get_min_time(n) > T) {
    cout << -1 << endl;
    return 0;
  }
  
  if (get_min_time(0) <= T) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  for (int k = MAX_N; k != 0; k /= 2) {
    if (get_min_time(ans + k) > T) {
      ans += k;
    }
  }

  cout << ans + 1 << endl;
}