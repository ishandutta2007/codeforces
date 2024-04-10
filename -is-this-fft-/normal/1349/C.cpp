#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 5;
const int MAX_EV = 2e6 + 5;

int ni [4] = {1, 0, -1, 0};
int nj [4] = {0, 1, 0, -1};

char grid [MAX_N][MAX_N];
int fflip [MAX_N][MAX_N]; // first iteration where flips

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  int n, m, qc;
  cin >> n >> m >> qc;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;

      grid[i][j] = c - '0';
    }
  }

  vector<pair<int, int>> cur;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int flips = 0;
      for (int k = 0; k < 4; k++) {
        if (1 <= i + ni[k] && i + ni[k] <= n &&
            1 <= j + nj[k] && j + nj[k] <= m) {
          if (grid[i][j] == grid[i + ni[k]][j + nj[k]]) {
            flips = 1;
          }
        }
      }

      if (flips) {
        fflip[i][j] = 1;
        cur.push_back(make_pair(i, j));
      }
    }
  }

  while (true) {
    vector<pair<int, int>> nxt;
    for (auto pr : cur) {
      int x = pr.first;
      int y = pr.second;

      for (int k = 0; k < 4; k++) {
        int nx = x + ni[k];
        int ny = y + nj[k];
        if (1 <= nx && nx <= n &&
            1 <= ny && ny <= m) {
          if (fflip[nx][ny] == 0) {
            // we know grid[x][y] != grid[nx][ny]
            fflip[nx][ny] = fflip[x][y] + 1;
            nxt.push_back(make_pair(nx, ny));
          }
        }
      }
    }

    if (nxt.empty()) {
      break;
    } else {
      cur = nxt;
    }
  }

  for (int i = 0; i < qc; i++) {
    int x, y;
    ll p;
    cin >> x >> y >> p;

    if (fflip[x][y] == 0 || fflip[x][y] > p) {
      cout << (int) grid[x][y] << '\n';
    } else {
      if (fflip[x][y] % 2 == p % 2) {
        cout << (int) !grid[x][y] << '\n';
      } else {
        cout << (int) grid[x][y] << '\n';
      }
    }
  }
}