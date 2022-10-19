#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string prevrow;
    string row;
    int grid[n][m];
    for (int i = 0; i < n; i++) {
      cin >> row;
      for (int j = 0; j < m; j++) {
        if (row[j] == 'X' || i % 3 == 0) grid[i][j] = 1;
        else grid[i][j] = 0;
      }
    }

    for (int i = 1; i <= n-3; i += 3) {
      bool connected = false;
      int j = 0;
      while (!connected && j < m) {
        if (grid[i][j]) {
          grid[i+1][j] = 1;
          connected = true;
        }
        if (grid[i+1][j]) {
          grid[i][j] = 1;
          connected = true;
        }
        j++;
      }
      if (!connected) {
        grid[i][0] = 1;
        grid[i+1][0] = 1;
      }
    }

    if (n % 3 == 0) {
      for (int j = 0; j < m; j++) {
        if (grid[n-1][j]) grid[n-2][j] = 1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) cout << 'X';
        else cout << '.';
      }
      cout << endl;
    }
  }
}