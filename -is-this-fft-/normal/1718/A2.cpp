#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int dp [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  map<int, int> last;
  last[0] = 0;
  dp[0] = 0;

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur ^= arr[i];
    dp[i] = 1 + dp[i - 1];
    if (last.count(cur)) {
      dp[i] = min(dp[i], i - last[cur] - 1 + dp[last[cur]]);
    }
    last[cur] = i;
  }

  cout << dp[n] << '\n';
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