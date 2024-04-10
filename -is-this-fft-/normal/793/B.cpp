#include <iostream>

const int MAX_HEIGHT = 1005;

using namespace std;

int height, width;
int nr [4] = {1, 0, -1, 0};
int nc [4] = {0, 1, 0, -1};
bool found;
char grid [MAX_HEIGHT][MAX_HEIGHT];

bool vis [MAX_HEIGHT][MAX_HEIGHT][4][5];
void dfs (int row, int col, int dir, int turnc) {
  if (row < 0 || row >= height || col < 0 || col >= width || turnc > 2) {
    return;
  }

  if (vis[row][col][dir][turnc]) {
    return;
  }
  vis[row][col][dir][turnc] = true;

  if (grid[row][col] == 'T') {
    found = true;
    return;
  }

  if (grid[row][col] == '*') {
    return;
  }

  dfs(row + nr[dir], col + nc[dir], dir, turnc);
  for (int i = 0; i < 4; i++) {
    dfs(row + nr[i], col + nc[i], i, turnc + 1);
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> height >> width;
  int startr, startc;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'S') {
        startr = i;
        startc = j;
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    dfs(startr, startc, i, 0);
  }

  cout << (found ? "YES" : "NO") << endl;
}