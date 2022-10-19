#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  bool grid[n][m];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      grid[i][j] = (s[j] == 'X');
    }
  }
  vector<int> sums(m);
  sums[0] = 0;
  for (int i = 0; i < m-1; i++) {
    sums[i+1] = sums[i];
    for (int j = 0; j < n-1; j++) {
      if (grid[j][i+1] && grid[j+1][i]) {
        sums[i+1]++;
        break;
      };
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << ((sums[x-1] == sums[y-1]) ? "YES\n" : "NO\n");
  }
}