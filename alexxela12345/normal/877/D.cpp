#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

bool check(int x, int n) {
  return x >= 0 && x < n;
}

void solve() {
  int n, m, sp;
  cin >> n >> m >> sp;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--;
  x2--;
  y1--;
  y2--;
  vector<vector<int>> dist(n, vector<int> (m, -1));
  dist[x1][y1] = 0;
  deque<pair<int, int>> q;
  q.push_back({x1, y1});
  vector<int> dx = {-1, 0, 0, 1};
  vector<int> dy = {0, -1, 1, 0};
  vector<set<int>> used1(n);
  vector<set<int>> used2(m);
  vector<set<int>> bx(n), by(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        used1[i].insert(j);
        used2[j].insert(i);
      } else {
        bx[i].insert(j);
        by[j].insert(i);
      }
    }
  }
  used1[x1].erase(y1);
  used2[y1].erase(x1);
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();
    while (true) {
      auto it = used1[x].lower_bound(y);
      if (it == used1[x].end())
        break;
      int yy = *it;
      if (yy > y + sp)
        break;
      auto it2 = bx[x].lower_bound(y);
      if (it2 != bx[x].end() && *it2 < yy)
        break;
      int cur_x = x;
      int cur_y = yy;
      if (dist[cur_x][cur_y] == -1) {
        dist[cur_x][cur_y] = dist[x][y] + 1;
        q.push_back({cur_x, cur_y});
        used1[cur_x].erase(cur_y);
        used2[cur_y].erase(cur_x);
      }
    }
    while (true) {
      auto it = used1[x].lower_bound(y);
      if (it == used1[x].begin())
        break;
      it--;
      int yy = *it;
      if (yy < y - sp)
        break;
      auto it2 = bx[x].lower_bound(y);
      if (it2 != bx[x].begin()) {
        it2--;
        if (*it2 > yy)
          break;
      }
      int cur_x = x;
      int cur_y = yy;
      if (dist[cur_x][cur_y] == -1) {
        dist[cur_x][cur_y] = dist[x][y] + 1;
        q.push_back({cur_x, cur_y});
        used1[cur_x].erase(cur_y);
        used2[cur_y].erase(cur_x);
      }
    }

    while (true) {
      auto it = used2[y].lower_bound(x);
      if (it == used2[y].end())
        break;
      int xx = *it;
      if (xx > x + sp)
        break;
      auto it2 = by[y].lower_bound(x);
      if (it2 != by[y].end() && *it2 < xx)
        break;
      int cur_x = xx;
      int cur_y = y;
      if (dist[cur_x][cur_y] == -1) {
        dist[cur_x][cur_y] = dist[x][y] + 1;
        q.push_back({cur_x, cur_y});
        used1[cur_x].erase(cur_y);
        used2[cur_y].erase(cur_x);
      }
    }
    while (true) {
      auto it = used2[y].lower_bound(x);
      if (it == used2[y].begin())
        break;
      it--;
      int xx = *it;
      if (xx < x - sp)
        break;
      auto it2 = by[y].lower_bound(x);
      if (it2 != by[y].begin()) {
        it2--;
        if (*it2 > xx)
          break;
      }
      int cur_x = xx;
      int cur_y = y;
      if (dist[cur_x][cur_y] == -1) {
        dist[cur_x][cur_y] = dist[x][y] + 1;
        q.push_back({cur_x, cur_y});
        used1[cur_x].erase(cur_y);
        used2[cur_y].erase(cur_x);
      }
    }
  }
  cout << dist[x2][y2] << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}