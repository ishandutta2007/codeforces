#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 1505;

void success () {
  cout << "Yes" << endl;
  exit(0);
}

char _grid [MAX_N][MAX_N];

int n, m;
bool blocked (int x, int y) {
  x %= n;
  y %= m;
  if (x < 0) x += n;
  if (y < 0) y += m;
  return _grid[x][y] == '#';
}

const int dx [4] = {1, 0, -1, 0};
const int dy [4] = {0, 1, 0, -1};

bool _vis [MAX_N][MAX_N];
bool &vis (int x, int y) {
  x %= n;
  y %= m;
  if (x < 0) x += n;
  if (y < 0) y += m;
  return _vis[x][y];
}

pair<int, int> _vis_at [MAX_N][MAX_N];
pair<int, int> &vis_at (int x, int y) {
  x %= n;
  y %= m;
  if (x < 0) x += n;
  if (y < 0) y += m;
  return _vis_at[x][y];
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int sx, sy;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> _grid[i][j];
      if (_grid[i][j] == 'S') {
        sx = i;
        sy = j;
      }
    }
  }

  queue<pair<int, int>> Q;
  Q.push({sx, sy});
  vis(sx, sy) = true;
  vis_at(sx, sy) = make_pair(sx, sy);
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int k = 0; k < 4; k++) {
      int nx = cur.first + dx[k], ny = cur.second + dy[k];
      if (blocked(nx, ny)) {
        continue;
      }

      if (vis(nx, ny)) {
        if (vis_at(nx, ny) != make_pair(nx, ny)) {
          success();
        }
      } else {
        vis(nx, ny) = true;
        vis_at(nx, ny) = make_pair(nx, ny);
        Q.push({nx, ny});
      }
    }
  }

  cout << "No" << endl;
}