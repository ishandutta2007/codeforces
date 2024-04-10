#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 507;
const int N = M * M;

int n, k;
char f[M][M];
int a[M][M];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m = 1;
bool u[M][M];
int sz[N];
int cnt[N];
int tot;

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

void ini() {
  tot = 0;
  fill(cnt, cnt + N, 0);
}

int income(int x) {
  if (x == 0)
    return cnt[x];
  return cnt[x] > 0 ? sz[x] : 0;
}

void upd(int x, int by) {
  tot -= income(x);
  cnt[x] += by;
  tot += income(x);
}

void add(int x, int y, bool flag = false) {
  if (!inside(x, y))
    return;
  if (flag && a[x][y] == 0)
    return;
  upd(a[x][y], 1);
}

void rem(int x, int y, bool flag = false) {
  if (!inside(x, y))
    return;
  if (flag && a[x][y] == 0)
    return;
  upd(a[x][y], -1);
}

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> f[i][j];
}

void dfs(int x, int y, int col) {
  u[x][y] = true;
  a[x][y] = col;
  sz[col]++;

  for (int k = 0; k < 4; ++k) {
    int tx = x + dx[k];
    int ty = y + dy[k];

    if (!inside(tx, ty))
      continue;

    if (u[tx][ty] || f[tx][ty] == 'X')
      continue;

    dfs(tx, ty, col);
  }
}


void kill() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) 
      if (!u[i][j]) {
        if (f[i][j] == 'X') {
          a[i][j] = 0;
          sz[0]++;
        } else {
          dfs(i, j, m++);
        }
      }

  //for (int i = 0; i < n; ++i, cerr << endl)
  //  for (int j = 0; j < n; ++j)
  //    cerr << a[i][j];

  int ans = 0;

  for (int i = 0; i + k <= n; ++i) {
    ini();
    for (int x = i; x < i + k; ++x)
      for (int y = 0; y < k; ++y)
        add(x, y);

    for (int j = 0; j + k <= n; ++j) {
      // (i, j) -- upper left
      for (int t = 0; t < k; ++t) {
        add(i - 1, j + t, true);
        add(i + t, j + k, true);
        add(i + k, j + t, true);
        add(i + t, j - 1, true);
      }

      ans = max(ans, tot);

      for (int t = 0; t < k; ++t) {
        rem(i - 1, j + t, true);
        rem(i + t, j + k, true);
        rem(i + k, j + t, true);
        rem(i + t, j - 1, true);
      }

      for (int t = 0; t < k; ++t) {
        rem(i + t, j);
        add(i + t, j + k);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}