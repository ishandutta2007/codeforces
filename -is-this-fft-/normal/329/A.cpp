#include <iostream>

using namespace std;

const int MAX_N = 105;

char grid [MAX_N][MAX_N];

int rcnt [MAX_N];
int ccnt [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == 'E') {
        rcnt[i]++;
        ccnt[j]++;
      }
    }
  }

  bool rows_ok = true;
  for (int i = 0; i < n; i++) {
    if (rcnt[i] == n) {
      rows_ok = false;
    }
  }

  if (rows_ok) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << '\n';
          break;
        }
      }
    }
    return 0;
  }

  bool cols_ok = true;
  for (int i = 0; i < n; i++) {
    if (ccnt[i] == n) {
      cols_ok = false;
    }
  }

  if (cols_ok) {
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (grid[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << '\n';
          break;
        }
      }
    }
    return 0;
  }

  cout << -1 << endl;
}