#include <bits/stdc++.h>
#define set asasdas

using namespace std;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct triple {
  int col, x, y, z, t;
};

vector <vector <vector <vector <triple> > > > e;
vector <vector <vector <char> > > emp;

 int n, m, k;

void set(int x, int y, int z, int col, int t) {
  if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= k) {
    cout << -1 << endl;
    exit(0);
  }
  if (emp[x][y][z]) {
    set(x + dx[t], y + dy[t], z + dz[t], col, t);
  } else {
    bool bad = false;
    for (auto c : e[x][y][z]) {
      if (c.col != col) {
        bad = true;
      }
    }
    e[x][y][z].push_back({col, x, y, z, t});
    if (bad) {
      emp[x][y][z] = true;
      auto f = e[x][y][z];
      e[x][y][z].clear();
      for (auto c : f) {
        set(c.x + dx[c.t], c.y + dy[c.t], c.z + dz[c.t], c.col, c.t);
      }
    }
  }
}

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  e.resize(n, vector <vector <vector <triple>> > (m, vector <vector <triple> > (k)));
  emp.resize(n, vector <vector <char> > (m, vector <char> (k)));
  vector <vector <int> > a(m, vector <int> (k));
  vector <vector <int> > b(m, vector <int> (k));
  vector <vector <int> > c(n, vector <int> (k));
  vector <vector <int> > d(n, vector <int> (k));
  vector <vector <int> > x(n, vector <int> (m));
  vector <vector <int> > y(n, vector <int> (m));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        for (int t = 0; t < n; t++) {
          emp[t][i][j] = true;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      cin >> b[i][j];
      if (b[i][j] == 0) {
        for (int t = 0; t < n; t++) {
          emp[t][i][j] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> c[i][j];
      if (c[i][j] == 0) {
        for (int t = 0; t < m; t++) {
          emp[i][t][j] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> d[i][j];
      if (d[i][j] == 0) {
        for (int t = 0; t < m; t++) {
          emp[i][t][j] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x[i][j];
      if (x[i][j] == 0) {
        for (int t = 0; t < k; t++) {
          emp[i][j][t] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> y[i][j];
      if (y[i][j] == 0) {
        for (int t = 0; t < k; t++) {
          emp[i][j][t] = true;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      if (a[i][j] != 0) {
        set(0, i, j, a[i][j], 0);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      if (b[i][j] != 0) {
        set(n - 1, i, j, b[i][j], 1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (c[i][j] != 0) {
        set(i, 0, j, c[i][j], 2);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (d[i][j] != 0) {
        set(i, m - 1, j, d[i][j], 3);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (x[i][j] != 0) {
        set(i, j, 0, x[i][j], 4);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (y[i][j] != 0) {
        set(i, j, k - 1, y[i][j], 5);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int t = 0; t < k; t++) {
        if (e[i][j][t].empty()) cout << 0 << ' ';
        else cout << e[i][j][t][0].col << ' ';
      }
    }
  }
  cout << endl;
}