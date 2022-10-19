#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int grid[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  int downs[m];
  for (int i = 0; i < m; i++) {
    downs[i] = n;
  }
  while (k--) {
    int col;
    int row = 0;
    int lastrow = 0;
    cin >> col;
    col--;
    bool early = false;
    while (row <= n) {
      if (downs[col] <= row) {
        cout << col+1 << " ";
        downs[col] = lastrow;
        early = true;
        break;
      }
      else {
        int a = grid[row][col];
        grid[row][col] = 2;
        if (a == 1) {
          col++;
          lastrow = row;
        }
        else if (a == 3) {
          col--;
          lastrow = row;
        }
        else {
          row++;
        }
      }
    }
    if (!early) {
      cout << col+1 << " ";
      downs[col] = lastrow;
    }
  }
  cout << endl;
}