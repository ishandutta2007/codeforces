#include <iostream>

using namespace std;

const int MAX_N = 105;
const int MAX_M = 1e4 + 5;
const int INF = 1e9 + 5;

string grid [MAX_N];
int cost [MAX_N][MAX_M];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '1') {
        cost[i][j] = 0;
      } else {
        cost[i][j] = MAX_M;
      }
    }

    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < m; j++) {
        cost[i][j] = min(cost[i][j], 1 + cost[i][(m + j - 1) % m]);
      }
    }

    for (int k = 0; k < 2; k++) {
      for (int j = m - 1; j >= 0; j--) {
        cost[i][j] = min(cost[i][j], 1 + cost[i][(j + 1) % m]);
      }
    }

    if (cost[i][0] == MAX_M) {
      cout << -1 << endl;
      return 0;
    }
  }

  int ans = INF;
  for (int j = 0; j < m; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += cost[i][j];
    }
    ans = min(ans, cur);
  }

  cout << ans << endl;
}