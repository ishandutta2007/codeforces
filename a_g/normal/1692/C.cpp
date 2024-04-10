#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    vector<string> grid(8);
    vector<vector<bool>> good(8, vector<bool>(8, true));
    for (string& row: grid) cin >> row;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (grid[i][j] == '#') {
          for (int k = 0; k < 8; k++) {
            for (int l = 0; l < 8; l++) {
              if (k+l != i+j && k-l != i-j) {
                good[k][l] = 0;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (good[i][j]) {
          cout << i+1 << " " << j+1 << '\n';
        }
      }
    }
  }
}