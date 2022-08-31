#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 1e3 + 5;
const int MAX_P = MAX_N * MAX_N;

void failure() {
  cout << -1 <<endl;
  exit(0);
}

int root [MAX_P];
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

int idx (int r, int c) {
  return MAX_N * r + c;
}

int mni [MAX_N];
int mxi [MAX_N];
int mnj [MAX_N];
int mxj [MAX_N];

string grid [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_P; i++) {
    root[i] = i;
  }
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    mni[i] = MAX_N;
    mxi[i] = -1;
  }

  for (int j = 0; j < m; j++) {
    mnj[j] = MAX_N;
    mxj[j] = -1;
  }
  
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') {
        mni[i] = min(j, mni[i]);
        mxi[i] = max(j, mxi[i]);

        mnj[j] = min(i, mnj[j]);
        mxj[j] = max(i, mxj[j]);
      }
    }
  }

  int ers = 0;
  for (int i = 0; i < n; i++) {
    if (mni[i] > mxi[i]) {
      ers = 1;
    } else {
      for (int j = mni[i]; j <= mxi[i]; j++){
        if (grid[i][j] != '#') {
          failure();
        }
      }
    }
  }

  int ecs = 0;
  for (int j = 0; j < m; j++) {
    if (mnj[j] > mxj[j]) {
      ecs = 1;
    } else {
      for (int i = mnj[j]; i <= mxj[j]; i++) {
        if (grid[i][j] != '#') {
          failure();
        }
      }
    }
  }

  if (ers != ecs) {
    failure();
  }
  
  int compc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') {
        if (j + 1 < m && grid[i][j + 1] == '#') {
          merge(idx(i, j), idx(i, j + 1));
        }

        if (i + 1 < n && grid[i + 1][j] == '#') {
          merge(idx(i, j), idx(i + 1, j));
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') {
        int id = idx(i, j);
        if (find(id) == id) {
          compc++;
        }
      }
    }
  }

  cout << compc << endl;
}