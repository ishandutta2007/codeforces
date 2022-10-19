#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const vector<pair<int, int>> nbrs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool grid[N][N];
int a[N][N];
vector<pair<int, int>> G[N][N];

void dfs(pair<int, int>& v, pair<int, int>& p, int k) {
  if (a[v.first][v.second]) return;
  a[v.first][v.second] = k;
  for (pair<int, int>& u: G[v.first][v.second]) {
    if (u != p) {
      dfs(u, v, 5-k);
    }
  }
}

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = (c == 'X');
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!grid[i][j]) continue;
      vector<pair<int, int>> Z;
      for (const pair<int, int>& p: nbrs) {
        int x = i+p.first;
        int y = j+p.second;
        if (!grid[x][y]) Z.push_back(make_pair(x, y));
      }
      if (Z.size() & 1) {
        cout << "NO\n";
        return 0;
      }
      a[i][j] = 5 * (Z.size()/2);
      for (int i = 0; i < (int)Z.size(); i += 2) {
        // ordering of nbrs makes this correct
        G[Z[i].first][Z[i].second].push_back(Z[1+i]);
        G[Z[1+i].first][Z[1+i].second].push_back(Z[i]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!grid[i][j] && !a[i][j]) {
        pair<int, int> v = make_pair(i, j);
        dfs(v, v, 1);
      }
    }
  }

  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}