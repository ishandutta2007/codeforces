#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int total = 0;
    for (int i = 0; i < n; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < m; j++) {
        a[i][j] = row[j] == '1';
        total += a[i][j];
      }
    }
    if (total == 0) {
      cout << "0\n";
      continue;
    }
    int min_first = 3;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int y: {1, -1}) {
          for (int z: {1, -1}) {
            if (i+y >= 0 && i+y < n && j+z >= 0 && j+z < m) {
              int k = a[i][j]+a[i+y][j]+a[i][j+z];
              if (k) min_first = min(min_first, k);
            }
          }
        }
      }
    }

    cout << total+1-min_first << '\n';
  }
}