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
    int rows = 0, cols = 0;
    for (int i = 0; i < n; i++) {
      int s = 0;
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        s += a[i][j];
      }
      if (s == 0) rows++;
    }
    for (int i = 0; i < m; i++) {
      int s = 0;
      for (int j = 0; j < n; j++) {
        s += a[j][i];
      }
      if (s == 0) cols++;
    }
    cout << (min(rows, cols)&1 ? "Ashish" : "Vivek") << '\n';
  }
}