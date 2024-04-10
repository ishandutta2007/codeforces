#include <iostream>

using namespace std;

const int MAX_N = 10;

char grid [MAX_N][MAX_N];
int ch [MAX_N][MAX_N];
int cv [MAX_N][MAX_N];

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ch[i][j] = MAX_N;
      cv[i][j] = MAX_N;
      if (j == m - 1) ch[i][j]++;
      if (i == n - 1) cv[i][j]++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m - 2; j >= 0; j--) {
      if (grid[i][j + 1] == '*') {
        ch[i][j] = 1;
      } else {
        ch[i][j] = min(ch[i][j], ch[i][j + 1] + 1);
      }
    }
  }
  
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (grid[i + 1][j] == '*') {
        cv[i][j] = 1;
      } else {
        cv[i][j] = min(cv[i][j], cv[i + 1][j] + 1);
      }
    }
  }
  
  int x = 0, y = 0, ans = 0;
  if (grid[0][0] == '*') {
    ans++;
  }
  
  while (x != n - 1 || y != m - 1) {
    if (ch[x][y] <= cv[x][y]) {
      y++;
    } else {
      x++;
    }
    
    if (grid[x][y] == '*') {
      ans++;
    }
  }

  cout << ans << endl;
}