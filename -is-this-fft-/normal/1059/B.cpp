#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5;

char grid [MAX_N][MAX_N];
char forg [MAX_N][MAX_N];
int ni [] = {1, 1, 1, 0, -1, -1, -1, 0};
int nj [] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      forg[i][j] = '.';
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      bool ok = true;
      for (int k = 0; k < 8; k++) {
        if (grid[i + ni[k]][j + nj[k]] != '#') {
          ok = false;
        }
      }

      if (ok) {
        for (int k = 0; k < 8; k++) {
          forg[i + ni[k]][j + nj[k]] = '#';
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != forg[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
}