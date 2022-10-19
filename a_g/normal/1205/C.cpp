#include <bits/stdc++.h>
using namespace std;

bool query (int a, int b, int c, int d) {
  int ans;
  cout << "? " << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
  cin >> ans;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int grid[n][n];
  grid[0][0] = 1;
  grid[n-1][n-1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i+j > 0 && !(i&1)^(j&1)) {
        if (j > 1) {
          grid[i][j] = query(i, j-2, i, j) ? grid[i][j-2] : 1-grid[i][j-2];
        }
        else if (i > 0 && j > 0) {
          grid[i][j] = query(i-1, j-1, i, j) ? grid[i-1][j-1] : 1-grid[i-1][j-1];
        }
        else {
          grid[i][j] = query(i-2, j, i, j) ? grid[i-2][j] : 1-grid[i-2][j];
        }
      }
    }
  }

  grid[0][1] = 0;
  grid[1][2] = query(0, 1, 1, 2) ? grid[0][1] : 1-grid[0][1];
  grid[1][0] = query(1, 0, 1, 2) ? grid[1][2] : 1-grid[1][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i+j > 0 && (i&1)^(j&1)) {
        if (j > 1) {
          if (j > 2 || i > 1) {
            grid[i][j] = query(i, j-2, i, j) ? grid[i][j-2] : 1-grid[i][j-2];
          }
        }
        else if (i > 0 && j > 0) {
          grid[i][j] = query(i-1, j-1, i, j) ? grid[i-1][j-1] : 1-grid[i-1][j-1];
        }
        else if (i > 1) {
          grid[i][j] = query(i-2, j, i, j) ? grid[i-2][j] : 1-grid[i-2][j];
        }
      }
    }
  }

  vector<vector<int>> path;
  for (int i = 0; i < n; i++) {
    path.push_back({0, i, grid[0][i]});
  }
  for (int i = 1; i < n; i++) {
    path.push_back({i, n-1, grid[i][n-1]});
  }
  for (int i = 0; i < 2*n-4; i++) {
    if (!path[i][2]^path[i+1][2]^path[i+2][2]^path[i+3][2]) {
      if (!query(path[i][0], path[i][1], path[i+3][0], path[i+3][1])^path[i][2]^path[i+3][2]) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if ((i&1)^(j&1)) {
              grid[i][j] = 1-grid[i][j];
            }
          }
        }
      }
      break;
    }
  }

  cout << "!" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}