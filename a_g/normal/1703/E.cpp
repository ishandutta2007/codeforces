#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (vector<int>& row: grid) {
      string s;
      cin >> s;
      for (int i = 0; i < n; i++) {
        row[i] = s[i]-'0';
      }
    }

    int ans = 0;
    for (int i = 0; i < n/2; i++) {
      for (int j = 0; j < (n+1)/2; j++) {
        int z = grid[i][j]+grid[j][n-1-i]+grid[n-1-i][n-1-j]+grid[n-1-j][i];
        ans += min(z, 4-z);
      }
    }
    cout << ans << '\n';
  }
}