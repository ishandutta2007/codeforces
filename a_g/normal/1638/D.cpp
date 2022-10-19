#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N];
int n, m;
set<pair<int, int>> positions;
vector<tuple<int, int, int>> ops;

void check(int i, int j) {
  if (i < 1 || j < 1 || i >= n || j >= m) return;
  int val = 0;
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 2; y++) {
      if (a[i+x][j+y]) {
        if (val && a[i+x][j+y] != val) return;
        val = a[i+x][j+y];
      }
    }
  }
  if (val) {
    positions.emplace(i, j);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      check(i, j);
    }
  }

  while (!positions.empty()) {
    pair<int, int> p = *positions.begin();
    positions.erase(*positions.begin());
    int val = 0;
    int i = p.first;
    int j = p.second;
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        if (a[i+x][j+y]) {
          val = a[i+x][j+y];
        }
      }
    }
    if (!val) continue;
    ops.push_back(make_tuple(i, j, val));
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        a[i+x][j+y] = 0;
      }
    }
    for (int x = -1; x < 2; x++) {
      for (int y = -1; y < 2; y++) {
        check(i+x, j+y);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  }

  cout << ops.size() << '\n';
  reverse(ops.begin(), ops.end());
  for (tuple<int, int, int> t: ops) {
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
  }
}