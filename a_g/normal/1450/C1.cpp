#include <bits/stdc++.h>
using namespace std;

const int N = 305;
char grid[N][N];
int ops[3];
// 0X, 2O
// 1X, 0O
// 2X, 1O

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < 3; i++) ops[i] = 0;
    int n;
    cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        grid[i][j] = s[j];
        if (grid[i][j] == 'X') {
          ops[(i+j+1)%3]++;
          k++;
        }
        else if (grid[i][j] == 'O') {
          ops[(i+j)%3]++;
          k++;
        }
      }
    }
    for (int r = 0; r < 3; r++) {
      if (ops[r] <= k/3) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if ((i+j+2*r)%3 == 0 && grid[i][j] == 'O') grid[i][j] = 'X';
            if ((i+j+2*r+1)%3 == 0 && grid[i][j] == 'X') grid[i][j] = 'O';
          }
        }
        break;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << grid[i][j];
      }
      cout << '\n';
    }
  }
}