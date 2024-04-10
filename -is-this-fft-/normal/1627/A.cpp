#include <iostream>

using namespace std;

const int MAX_N = 55;

string grid [MAX_N];

void solve () {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  r--; c--;

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  if (grid[r][c] == 'B') {
    cout << 0 << '\n';
    return;
  }

  bool any = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'B') {
        if (i == r) {
          cout << 1 << '\n';
          return;
        }

        if (j == c) {
          cout << 1 << '\n';
          return;
        }

        any = true;
      }
    }
  }

  if (any) {
    cout << 2 << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}