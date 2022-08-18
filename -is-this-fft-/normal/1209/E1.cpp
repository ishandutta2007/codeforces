#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Cell {
  int row, col, val;

  Cell () {}
  Cell (int _row, int _col, int _val) :
    row(_row), col(_col), val(_val) {}
};

bool byval (Cell c, Cell d) {
  return c.val > d.val;
}

bool byrowcol (Cell c, Cell d) {
  return make_pair(c.col, c.row) < make_pair(d.col, d.row);
}

bool feasible (vector<Cell> topcells) {
  if ((topcells[0].col == topcells[1].col) &&
      (topcells[1].col != topcells[2].col) &&
      (topcells[2].col == topcells[3].col)) {
    int adiff = abs(topcells[1].row - topcells[0].row);
    int bdiff = abs(topcells[3].row - topcells[2].row);
    if (adiff == 3) adiff = 1;
    if (bdiff == 3) bdiff = 1;
    if (adiff != bdiff) {
      return false;
    }
  }
  return true;
}

int bestFeasible (vector<Cell> topcells) {
  sort(topcells.begin(), topcells.end(), byrowcol);
  int tcc = topcells.size();
  int ans = 0;
  for (int i = 0; i < 1 << tcc; i++) {
    if (__builtin_popcount(i) == 4) {
      vector<Cell> cur;
      int curScore = 0;
      for (int j = 0; j < tcc; j++) {
        if (i & 1 << j) {
          cur.push_back(topcells[j]);
          curScore += topcells[j].val;
        }
      }

      if (feasible(cur)) {
        ans = max(ans, curScore);
      }
    }
  }
  return ans;
}

int table [4][100];

void solve () {
  int height, width;
  cin >> height >> width;

  vector<Cell> cells;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> table[i][j];

      cells.push_back(Cell(i, j, table[i][j]));
    }
  }

  sort(cells.begin(), cells.end(), byval);

  if (height <= 3) {
    int ans = 0;
    for (int i = 0; i < height; i++) {
      ans += cells[i].val;
    }
    cout << ans << '\n';
    return;
  }

  vector<Cell> topcells;
  for (int i = 0; i < min(7, (int) cells.size()); i++) {
    topcells.push_back(cells[i]);
  }
  cout << bestFeasible(topcells) << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}