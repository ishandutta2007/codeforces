#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define x first
#define y second

const int INF = 1e9 + 5;
const int MAX_N = 505;

char grid [MAX_N][MAX_N];
int dist [MAX_N][MAX_N];

const int dx [4] = {0, 1, 0, -1};
const int dy [4] = {1, 0, -1, 0};

int main () {
  int n, m, K;
  cin >> n >> m >> K;

  pair<int, int> sta;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      dist[i][j] = INF;
      if (grid[i][j] == '.') {
        sta = make_pair(i, j);
      }
    }
  }

  queue<pair<int, int>> Q;
  dist[sta.x][sta.y] = 0;
  Q.push(sta);

  vector<pair<int, int>> ord;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    ord.push_back(cur);
    for (int k = 0; k < 4; k++) {
      int nx = cur.x + dx[k];
      int ny = cur.y + dy[k];
      if (grid[nx][ny] == '.' && dist[nx][ny] == INF) {
        dist[nx][ny] = dist[cur.x][cur.y] + 1;
        Q.push(make_pair(nx, ny));
      }
    }
  }

  reverse(ord.begin(), ord.end());
  for (int i = 0; i < K; i++) {
    grid[ord[i].x][ord[i].y] = 'X';
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
}