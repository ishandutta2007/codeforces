#include <iostream>

using namespace std;

const int MAX_N = 505;

char grid [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int sta = 0;
  if (n % 3 == 0) {
    sta = 1;
  }

  for (int i = sta; i < n; i += 3) {
    for (int j = 0; j < m; j++) {
      grid[i][j] = 'X';
    }
  }

  for (int i = sta; i + 3 < n; i += 3) {
    for (int j = 0; j < m; j++) {
      bool fits = false;
      if (grid[i + 1][j] == 'X' || grid[i + 2][j] == 'X') {
        fits = true;
      }

      bool clrl = false;
      if (j == 0) {
        clrl = true;
      } else if (grid[i + 1][j - 1] == '.' && grid[i + 2][j - 1] == '.') {
        clrl = true;
      }

      bool clrr = false;
      if (j == m - 1) {
        clrr = true;
      } else if (grid[i + 1][j + 1] == '.' && grid[i + 2][j + 1] == '.') {
        clrr = true;
      }

      if (clrl && clrr) {
        fits = true;
      }

      if (fits) {
        grid[i + 1][j] = 'X';
        grid[i + 2][j] = 'X';
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}