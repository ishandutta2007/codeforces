#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string& row: grid) cin >> row;
    int a = 10;
    int b = 10;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'R') {
          a = min(a, i);
          b = min(b, j);
        }
      }
    }
    cout << (grid[a][b] == 'R' ? "YES" : "NO") << '\n';
  }
}