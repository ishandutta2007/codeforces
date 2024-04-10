#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector a(2, vector(n, vector<int>(m)));
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[z][i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[0][i][j] > a[1][i][j]) swap(a[0][i][j], a[1][i][j]);
    }
  }
  bool ok = 1;
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j+1 < m && a[z][i][j] >= a[z][i][j+1]) ok = 0;
        if (i+1 < n && a[z][i][j] >= a[z][i+1][j]) ok = 0;
      }
    }
  }
  cout << (ok ? "Possible" : "Impossible") << '\n';
}