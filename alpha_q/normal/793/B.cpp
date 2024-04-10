#include <bits/stdc++.h> 

using namespace std;

const int N = 1005;

struct state {
  int x, y, dir, has;
  state () {}
  state (int a, int b, int c, int d) {
    x = a, y = b, dir = c, has = d;
  }
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
char g[N][N];
int sx, sy, tx, ty;
int d[N][N][5][4];
queue <state> q;

bool valid (int x, int y) {
  return x > 0 and y > 0 and x <= n and y <= m and g[x][y] != '*';
}

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == 'S') {
        sx = i, sy = j;
      }
      if (g[i][j] == 'T') {
        tx = i, ty = j;
      }
    }
  }
  memset(d, -1, sizeof d);
  for (int i = 0; i < 4; ++i) {
    q.push(state(sx, sy, i, 2));
    d[sx][sy][i][2] = 0;
  }
  while (not q.empty()) {
    state top = q.front(); q.pop();
    int x = top.x, y = top.y, dir = top.dir, has = top.has;
    int nx = x + dx[dir], ny = y + dy[dir];
    if (valid(nx, ny) and d[nx][ny][dir][has] == -1) {
      d[nx][ny][dir][has] = d[x][y][dir][has] + 1;
      q.push(state(nx, ny, dir, has));
    }
    if (has == 0) continue;
    for (int i = 0; i < 4; ++i) {
      if (i == dir) continue;
      nx = x + dx[i], ny = y + dy[i];
      if (valid(nx, ny) and d[nx][ny][i][has - 1] == -1) {
        d[nx][ny][i][has - 1] = d[x][y][dir][has] + 1;
        q.push(state(nx, ny, i, has - 1));
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j <= 2; ++j) {
      if (d[tx][ty][i][j] != -1) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}