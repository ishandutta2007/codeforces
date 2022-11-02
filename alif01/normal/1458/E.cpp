#include <bits/stdc++.h>
using namespace std;

const int N = 100005, MAX = 1011000000;;
int n, m, x[N], y[N], vis[N];
int sx[N], sy[N], sz[N], p = 0;
set<pair<int, int> > t;

int main() {
  scanf("%d%d", &n, &m);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qx, qy;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    t.insert(make_pair(x[i], y[i]));
    qx.push(make_pair(x[i], i));
    qy.push(make_pair(y[i], i));
  }
  qx.push(make_pair(MAX, 0));
  qy.push(make_pair(MAX, 0));
  int curx = 0;
  int cury = 0;
  while (qx.top().first != MAX || qy.top().first != MAX) {
    int i;
    if (qx.top().first - curx <= qy.top().first - cury) {
      i = qx.top().second;
      qx.pop();
    } else {
      i = qy.top().second;
      qy.pop();
    }
    vis[i]++;
    if (vis[i] == 2 && (x[i] >= curx || y[i] >= cury)) {
      int nx, ny, cnt = max(x[i] - curx, y[i] - cury);
      if (x[i] - curx == y[i] - cury) {
        nx = x[i] + 1;
        ny = y[i] + 1;
      } else if (x[i] - curx < y[i] - cury) {
        ny = y[i] + 1;
        nx = curx + y[i] - cury;
      } else {
        nx = x[i] + 1;
        ny = cury + x[i] - curx;
      }
      if (cnt) {
        sx[++p] = curx;
        sy[p] = cury;
        sz[p] = cnt;
      }
      curx = nx;
      cury = ny;
    }
  }
  sx[++p] = curx;
  sy[p] = cury;
  sz[p] = MAX;
  while (m--) {
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    if (t.find(make_pair(xx, yy)) != t.end()) {
      puts("LOSE");
    } else {
      int u = upper_bound(sx + 1, sx + 1 + p, xx) - sx - 1;
      if (u && xx - yy == sx[u] - sy[u] && xx - sx[u] + 1 <= sz[u]) {
        puts("LOSE");
      } else {
        puts("WIN");
      }
    }
  }
}