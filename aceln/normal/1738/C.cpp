#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1)
        odd++;
      else
        even++;
    }
    vector<vector<vector<int>>> dp(n + 1, vector(n + 1, vector<int>(2)));

    auto s = [&](int x, int y, int z) {
      if (x < 0 || y < 0 || z < 0)
        return 0;
      else
        return dp[x][y][z];
    };

    // 1 : alice, 2 : bob
    dp[0][0][0] = 1, dp[0][0][1] = 2; // odd, even, cursum
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) {
        if (i == 0 && j == 0)
          continue;
        if ((i + j + n) & 1) { // bob
          if (s(i - 1, j, 0) == 2 || s(i, j - 1, 0) == 2)
            dp[i][j][0] = 2;
          else
            dp[i][j][0] = 1;

          if (s(i - 1, j, 1) == 2 || s(i, j - 1, 1) == 2)
            dp[i][j][1] = 2;
          else
            dp[i][j][1] = 1;
        } else { // alice
          if (s(i - 1, j, 1) == 1 || s(i, j - 1, 0) == 1)
            dp[i][j][0] = 1;
          else
            dp[i][j][0] = 2;

          if (s(i - 1, j, 0) == 1 || s(i, j - 1, 1) == 1)
            dp[i][j][1] = 1;
          else
            dp[i][j][1] = 2;
        }
      }

    cout << (dp[odd][even][0] == 1 ? "Alice\n" : "Bob\n");
  }
}