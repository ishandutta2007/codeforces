#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;
const int ROW = 0;
const int COL = 55;

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

char grid [MAX_N][MAX_N];
char ours [MAX_N][MAX_N];

vector<int> rows [MAX_N];
vector<int> cols [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '#') {
        merge(ROW + i, COL + j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    rows[find(ROW + i)].push_back(i);
  }

  for (int j = 0; j < m; j++) {
    cols[find(COL + j)].push_back(j);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ours[i][j] = '.';
    }
  }
  
  for (int i = 0; i < MAX_N; i++) {
    if (find(i) == i) {
      for (int x : rows[i]) {
        for (int y : cols[i]) {
          ours[x][y] = '#';
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ours[i][j] != grid[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}