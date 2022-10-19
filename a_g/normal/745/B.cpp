#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++) {
      a[i][j] = row[j] == 'X';
    }
  }
  for (int i = 0; i+1 < n; i++) {
    for (int j = 0; j+1 < m; j++) {
      if (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1] == 3) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
}