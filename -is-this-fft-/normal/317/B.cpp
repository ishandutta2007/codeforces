#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Point;
#define x first
#define y second

const int dx [4] = {1, 0, -1, 0};
const int dy [4] = {0, 1, 0, -1};

const int MAX_A = 200;
const int ZERO = 100;

int _grid [MAX_A][MAX_A];
int& grid (int x, int y) {
  return _grid[ZERO + x][ZERO + y];
}

void try_update (Point p, vector<Point> &del, vector<Point> &upd) {
  if (grid(p.x, p.y) >= 4) {
    del.push_back(p);
    for (int k = 0; k < 4; k++) {
      upd.push_back({p.x + dx[k], p.y + dy[k]});
    }
  }
}

vector<Point> step (const vector<Point> &cands) {
  vector<Point> del;
  vector<Point> upd;

  for (auto p : cands) {
    try_update(p, del, upd);
  }
  try_update({0, 0}, del, upd);

  for (auto p : del) {
    grid(p.x, p.y) -= 4;
  }
  
  vector<Point> nxt;
  for (auto p : upd) {
    grid(p.x, p.y)++;
    if (grid(p.x, p.y) == 4 && (p.x != 0 || p.y != 0)) {
      nxt.push_back(p);
    }
  }

  return nxt;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, qc;
  cin >> n >> qc;

  grid(0, 0) = n;
  vector<Point> cands;
  while (true) {
    cands = step(cands);
    if (cands.empty() && grid(0, 0) < 4) {
      break;
    }
  }

  for (int i = 0; i < qc; i++) {
    int x, y;
    cin >> x >> y;

    if (abs(x) >= ZERO || abs(y) >= ZERO) {
      cout << 0 << '\n';
    } else {
      cout << grid(x, y) << '\n';
    }
  }
}