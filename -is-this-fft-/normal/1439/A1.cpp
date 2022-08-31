#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Point;
#define x first
#define y second

struct Step {
  Point a, b, c;
  Step () {}
  Step (Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {}
};

const int MAX_N = 105;

int grid [MAX_N][MAX_N];

void apply (Point p) {
  grid[p.x][p.y] ^= 1;
}

void add_step (vector<Step> &sol, Point p, Point q, Point r) {
  apply(p);
  apply(q);
  apply(r);
  sol.push_back(Step(p, q, r));
}

void fix_row (int row, int m, vector<Step> &sol) {
  for (int j = 0; j < m; j += 2) {
    if (j == m - 1) {
      if (grid[row][j]) {
        add_step(sol, make_pair(row, j), make_pair(row + 1, j - 1), make_pair(row + 1, j));
      }
    } else if (grid[row][j] && grid[row][j + 1]) {
      add_step(sol, make_pair(row, j), make_pair(row, j + 1), make_pair(row + 1, j));
    } else if (grid[row][j]) {
      add_step(sol, make_pair(row, j), make_pair(row + 1, j), make_pair(row + 1, j + 1));
    } else if (grid[row][j + 1]) {
      add_step(sol, make_pair(row, j + 1), make_pair(row + 1, j), make_pair(row + 1, j + 1));
    }
  }
}

void fix_brick (int row, int col, vector<Step> &sol) {
  if (grid[row][col] && grid[row + 1][col]) {
    add_step(sol, make_pair(row, col), make_pair(row + 1, col), make_pair(row, col + 1));
  } else if (grid[row][col]) {
    add_step(sol, make_pair(row, col), make_pair(row, col + 1), make_pair(row + 1, col + 1));
  } else if (grid[row + 1][col]) {
    add_step(sol, make_pair(row + 1, col), make_pair(row + 1, col + 1), make_pair(row, col + 1));
  }
}

void add_corner (int row, int col, int dx, int dy, vector<Step> &sol) {
  add_step(sol,
           make_pair(row + dx, col + dy),
           make_pair(row + !dx, col + dy),
           make_pair(row + dx, col + !dy));
}

bool has_corner (int row, int col, int dx, int dy) {
  return (grid[row + dx][col + dy] + grid[row + dx][col + !dy] + grid[row + !dx][col + dy]) == 3;
}

void fix_square (int row, int col, vector<Step> &sol) {
  int sum = 0;
  for (int dx = 0; dx < 2; dx++) {
    for (int dy = 0; dy < 2; dy++) {
      sum += grid[row + dx][col + dy];
    }
  }

  if (sum == 2) {
    for (int dx = 0; dx < 2; dx++) {
      for (int dy = 0; dy < 2; dy++) {
        if (grid[row + dx][col + dy]) {
          add_corner(row, col, dx, dy, sol);
          goto sumout0;
        }
      }
    }
  }
 sumout0:
  
  for (int dx = 0; dx < 2; dx++) {
    for (int dy = 0; dy < 2; dy++) {
      if (has_corner(row, col, dx, dy)) {
        add_corner(row, col, dx, dy, sol);
      }
    }
  }

  sum = 0;
  for (int dx = 0; dx < 2; dx++) {
    for (int dy = 0; dy < 2; dy++) {
      sum += grid[row + dx][col + dy];
    }
  }

  if (sum == 2) {
    for (int dx = 0; dx < 2; dx++) {
      for (int dy = 0; dy < 2; dy++) {
        if (grid[row + dx][col + dy]) {
          add_corner(row, col, dx, dy, sol);
          goto sumout; // O_O
        }
      }
    }
  }
 sumout:
  
  for (int dx = 0; dx < 2; dx++) {
    for (int dy = 0; dy < 2; dy++) {
      if (grid[row + dx][col + dy]) {
        add_corner(row, col, dx, dy, sol);
        add_corner(row, col, !dx, dy, sol);
        add_corner(row, col, dx, !dy, sol);
      }
    }
  }
}

ostream& operator<< (ostream &out, Point p) {
  out << p.x + 1 << " " << p.y + 1;
  return out;
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }
  
  vector<Step> sol;
  for (int i = 0; i < n - 2; i++) {
    fix_row(i, m, sol);
  }

  for (int j = 0; j < m - 2; j++) {
    fix_brick(n - 2, j, sol);
  }

  fix_square(n - 2, m - 2, sol);

  cout << (int) sol.size() << '\n';
  for (auto step : sol) {
    cout << step.a << " " << step.b << " " << step.c << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}