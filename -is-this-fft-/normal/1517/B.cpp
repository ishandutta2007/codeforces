#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;

int grid [MAX_N][MAX_N];
pair<int, int> at [MAX_N][MAX_N]; // the item at (i, j)
pair<int, int> pos [MAX_N][MAX_N]; // position of the item (i, j)

void swapat (pair<int, int> p, pair<int, int> q) {
  swap(pos[p.first][p.second], pos[q.first][q.second]);
  auto pp = pos[p.first][p.second];
  auto qq = pos[q.first][q.second];
  swap(at[pp.first][pp.second], at[qq.first][qq.second]);
}

void solve () {
  int n, m;
  cin >> n >> m;

  vector<pair<int, pair<int, int>>> ord;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      at[i][j] = make_pair(i, j);
      pos[i][j] = make_pair(i, j);
      ord.push_back(make_pair(grid[i][j], make_pair(i, j)));
    }
  }

  sort(ord.begin(), ord.end());

  for (int i = 0; i < m; i++) {
    auto cur = ord[i].second;
    if (pos[cur.first][cur.second] != make_pair(cur.first, i)) {
      swapat(cur, at[cur.first][i]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto pr = at[i][j];
      cout << grid[pr.first][pr.second] << " ";
    }
    cout << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}