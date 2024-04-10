#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pos(n*m);
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      x--;
      grid[i][j] = x;
      pos[x] = {i, j};
    }
  }
  vector<int> a(n*m);
  vector<int> badnums;
  vector<vector<int>> low(n, vector<int>(m));
  for (int i = 0; i < n*m; i++) {
    int x = pos[i].first;
    int y = pos[i].second;
    if (i == 0) {
      low[x][y] = 100;
      continue;
    }
    if (x > 0) low[x][y]+= grid[x-1][y] < i;
    if (x < n-1) low[x][y]+= grid[x+1][y] < i;
    if (y > 0) low[x][y] += grid[x][y-1] < i;
    if (y < m-1) low[x][y] += grid[x][y+1] < i;
    if (!low[x][y]) badnums.push_back(i);
  }

  if (!badnums.size()) {
    cout << "0\n";
    return 0;
  }

  if (badnums.size() > 10) {
    cout << "2\n";
    return 0;
  }

  vector<pair<int, int>> first_positions;
  for (int x: badnums) {
    first_positions.emplace_back(pos[x].first, pos[x].second);
    first_positions.emplace_back(pos[x].first+1, pos[x].second);
    first_positions.emplace_back(pos[x].first-1, pos[x].second);
    first_positions.emplace_back(pos[x].first, pos[x].second+1);
    first_positions.emplace_back(pos[x].first, pos[x].second-1);
  }
  sort(first_positions.begin(), first_positions.end());
  first_positions.resize(unique(first_positions.begin(), first_positions.end())-first_positions.begin());

  vector<pair<pair<int, int>, pair<int, int>>> goodpairs;

  auto upd = [&] (pair<int, int>& p) {
    int x = p.first;
    int y = p.second;
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    int nl = 0;
    if (x > 0)  nl += grid[x-1][y] < grid[x][y];
    if (x < n-1) nl += grid[x+1][y] < grid[x][y];
    if (y > 0) nl += grid[x][y-1] < grid[x][y];
    if (y < m-1) nl += grid[x][y+1] < grid[x][y];
    return (nl == 0 && grid[x][y] > 0) - (low[x][y] == 0);
  };

  auto check = [&] (pair<int, int> p, pair<int, int> q) {
    if (p == q) return;
    swap(grid[p.first][p.second], grid[q.first][q.second]);
    int diff = 0;
    vector<pair<int, int>> to_update;
    for (pair<int, int> r: {p, q}) {
      to_update.emplace_back(r.first, r.second);
      to_update.emplace_back(r.first+1, r.second);
      to_update.emplace_back(r.first-1, r.second);
      to_update.emplace_back(r.first, r.second+1);
      to_update.emplace_back(r.first, r.second-1);
    }
    sort(to_update.begin(), to_update.end());
    to_update.resize(unique(to_update.begin(), to_update.end())-to_update.begin());
    for (pair<int, int> r: to_update) {
      diff += upd(r);
    }
    swap(grid[p.first][p.second], grid[q.first][q.second]);
    if (diff+badnums.size() == 0) goodpairs.emplace_back(min(p, q), max(p, q));
  };

  for (pair<int, int>& p: first_positions) {
    if (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m) {
      vector<pair<int, int>> other;
      for (int x: badnums) {
        pair<int, int> q = pos[x];
        if (abs(q.first-p.first) + abs(q.second-p.second) > 1) {
          other.emplace_back(q);
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          bool good = 1;
          for (pair<int, int>& q: other) {
            if (abs(i-q.first) + abs(j-q.second) > 1) {
              good = 0;
              break;
            }
          }
          if (good) check(p, make_pair(i, j));
        }
      }
    }
  }

  sort(goodpairs.begin(), goodpairs.end());
  goodpairs.resize(unique(goodpairs.begin(), goodpairs.end())-goodpairs.begin());
  if (!goodpairs.size()) {
    cout << "2\n";
    return 0;
  }
  else {
    cout << "1 " << goodpairs.size() << '\n';
  }
}