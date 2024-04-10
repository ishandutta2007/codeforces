#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Cell;
#define x first
#define y second

const int INF = 1e9 + 5;
const int MAX_N = 1e3 + 5;

const int dx [4] = {0, 1, 0, -1};
const int dy [4] = {1, 0, -1, 0};

char grid [MAX_N][MAX_N];
int dist [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      grid[i][j] = 'T';
      dist[i][j] = INF;
    }
  }

  Cell start, finish;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'E') {
        finish = make_pair(i, j);
      }
      if (grid[i][j] == 'S') {
        start = make_pair(i, j);
      }
    }
  }

  queue<Cell> Q;
  Q.push(finish);
  dist[finish.x][finish.y] = 0;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int k = 0; k < 4; k++) {
      auto nxt = make_pair(cur.x + dx[k], cur.y + dy[k]);
      if (grid[nxt.x][nxt.y] != 'T' && dist[nxt.x][nxt.y] == INF) {
        dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
        Q.push(nxt);
      }
    }
  }

  int maxd = dist[start.x][start.y];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char cur = grid[i][j];
      if ('0' <= cur && cur <= '9') {
        if (dist[i][j] <= maxd) {
          ans += cur - '0';
        }
      }
    }
  }

  cout << ans << endl;
}