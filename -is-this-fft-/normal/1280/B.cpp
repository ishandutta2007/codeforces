#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve () {
  int height, width;
  cin >> height >> width;
  vector<string> grid (height);
  for (int i = 0; i < height; i++) {
    cin >> grid[i];
  }

  vector<int> n_a_row (height, 0);
  vector<int> n_a_col (width, 0);
  int n_a = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == 'A') {
        n_a_row[i]++;
        n_a_col[j]++;
        n_a++;
      }
    }
  }

  if (n_a == 0) {
    cout << "MORTAL" << '\n';
    return;
  }

  if (n_a == height * width) {
    cout << 0 << '\n';
    return;
  }

  if (n_a_row[0] == width || n_a_row[height - 1] == width
      || n_a_col[0] == height || n_a_col[width - 1] == height) {
    cout << 1 << '\n';
    return;
  }

  if (grid[0][0] == 'A' || grid[height - 1][0] == 'A'
      || grid[0][width - 1] == 'A' || grid[height - 1][width - 1] == 'A') {
    cout << 2 << '\n';
    return;
  }
  
  int upl = width + 1, upr = -1;
  int dnl = width + 1, dnr = -1;
  for (int j = 0; j < width; j++) {
    if (grid[0][j] == 'P') {
      upl = min(upl, j);
      upr = max(upr, j);
    }

    if (grid[height - 1][j] == 'P') {
      dnl = min(dnl, j);
      dnr = max(dnr, j);
    }
  }

  for (int i = 0; i < height; i++) {
    bool ok = 1;
    for (int j = upl; j <= upr; j++) {
      if (grid[i][j] == 'P') {
        ok = 0;
      }
    }

    if (ok) {
      cout << 2 << '\n';
      return;
    }

    ok = 1;
    for (int j = dnl; j <= dnr; j++) {
      if (grid[i][j] == 'P') {
        ok = 0;
      }
    }

    if (ok) {
      cout << 2 << '\n';
      return;
    }
  }

  int lel = height + 1, ler = -1;
  int ril = height + 1, rir = -1;
  for (int i = 0; i < height; i++) {
    if (grid[i][0] == 'P') {
      lel = min(lel, i);
      ler = max(ler, i);
    }

    if (grid[i][width - 1] == 'P') {
      ril = min(ril, i);
      rir = max(rir, i);
    }
  }

  for (int j = 0; j < width; j++) {
    bool ok = 1;
    for (int i = lel; i <= ler; i++) {
      if (grid[i][j] == 'P') {
        ok = 0;
      }
    }

    if (ok) {
      cout << 2 << '\n';
      return;
    }

    ok = 1;
    for (int i = ril; i <= rir; i++) {
      if (grid[i][j] == 'P') {
        ok = 0;
      }
    }

    if (ok) {
      cout << 2 << '\n';
      return;
    }
  }
  
  for (int i = 0; i < height; i++) {
    if (n_a_row[i] == width) {
      cout << 2 << '\n';
      return;
    }
  }

  for (int i = 0; i < width; i++) {
    if (n_a_col[i] == height) {
      cout << 2 << '\n';
      return;
    }
  }

  if (n_a_row[0] > 0 || n_a_row[height - 1] > 0
      || n_a_col[0] > 0 || n_a_col[width - 1] > 0) {
    cout << 3 << '\n';
    return;
  }

  cout << 4 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}