#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;

int n, m;
int grid [MAX_N][MAX_N];
int sumr [MAX_N];
int sumc [MAX_N];

void flip (int x, int y) {
  sumr[x] -= 2 * grid[x][y];
  sumc[y] -= 2 * grid[x][y];
  grid[x][y] *= -1;
}

bool fr [MAX_N];
bool fc [MAX_N];

void flip_row (int x) {
  for (int i = 0; i < m; i++) {
    flip(x, i);
  }
  fr[x] ^= 1;
}

void flip_col (int y) {
  for (int i = 0; i < n; i++) {
    flip(i, y);
  }
  fc[y] ^= 1;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      sumr[i] += grid[i][j];
      sumc[j] += grid[i][j];
    }
  }

  bool found = true;
  while (found) {
    found = false;
    for (int i = 0; i < n; i++) {
      if (sumr[i] < 0) {
        found = true;
        flip_row(i);
      }
    }

    for (int j = 0; j < m; j++) {
      if (sumc[j] < 0) {
        found = true;
        flip_col(j);
      }
    }
  }

  vector<int> rows;
  for (int i = 0; i < n; i++) {
    if (fr[i]) rows.push_back(i);
  }

  vector<int> cols;
  for (int i = 0; i < m; i++) {
    if (fc[i]) cols.push_back(i);
  }

  cout << (int) rows.size() << " ";
  for (int u : rows) {
    cout << 1 + u << " ";
  }
  cout << '\n';

  cout << (int) cols.size() << " ";
  for (int u : cols) {
    cout << 1 + u << " ";
  }
  cout << '\n';
}