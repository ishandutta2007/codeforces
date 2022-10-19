#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int grid[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        grid[i][j] = s[j] == '1';
      }
    }
    if (grid[0][0]) {
      cout << "-1\n";
      continue;
    }
    vector<tuple<int, int, int, int>> ops;
    for (int i = n-1; i >= 0; i--) {
      for (int j = m-1; j >= 0; j--) {
        if (grid[i][j]) {
          if (j) {
            ops.push_back(make_tuple(i, j-1, i, j));
          }
          else {
            ops.push_back(make_tuple(i-1, j, i, j));
          }
        }
      }
    }

    cout << ops.size() << '\n';
    for (tuple<int, int, int, int>& op: ops) {
      int u, v, w, x;
      tie(u, v, w, x) = op;
      cout << u+1 << " " << v+1 << " " << w+1 << " " << x+1 << '\n';
    }
  }
}