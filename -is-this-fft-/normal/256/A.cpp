#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 4e3 + 5;

int arr [MAX_N];
int dp [MAX_N][MAX_N];
int last [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  map<int, int> compr;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    compr[arr[i]] = 0;
  }

  int cur = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = compr[arr[i]];
    last[i] = -1;
  }

  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = 1;
      if (last[j] >= 0) {
        dp[i][j] += dp[last[j]][arr[i]];
      }
      ans = max(ans, dp[i][j]);
    }

    last[arr[i]] = i;
  }
  cout << ans << endl;
}