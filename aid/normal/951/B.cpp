#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

const int maxn = 55;
int n, m;
int xs[maxn], ys[maxn];
int xt[maxn], yt[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &xs[i], &ys[i]);
    xs[i]--;
    ys[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &xt[i], &yt[i]);
    xt[i]--;
    yt[i]--;
  }
  return true;
}

pair<pair<int, int>, int> tosort[maxn];
vector<vector<int>> ans;
int c[maxn][maxn];

void move(int id, int nx, int ny) {
  ans.push_back({xs[id], ys[id], nx, ny});
  c[xs[id]][ys[id]] = -1;
  xs[id] = nx;
  ys[id] = ny;
  c[xs[id]][ys[id]] = id;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = -1;
    }
  }
  for (int i = 0; i < m; i++) {
    c[xs[i]][ys[i]] = i;
  }
  ans.clear();
  for (int i = 0; i < m; i++) {
    tosort[i] = make_pair(make_pair(ys[i], xs[i]), i);
  }
  sort(tosort, tosort + m);
  while (true) {
    {
      bool ok = true;
      for (int i = 0; i < m; i++) {
        int id = tosort[i].second;
        if (ys[id] != i) {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    for (int i = 0; i < m; i++) {
      int id = tosort[i].second;
      while (true) {
        if (ys[id] == i) {
          break;
        }
        int ny = (ys[id] < i ? ys[id] + 1 : ys[id] - 1);
        if (c[xs[id]][ny] == -1) {
          move(id, xs[id], ny);
        } else {
          break;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    tosort[i] = make_pair(make_pair(xt[i], yt[i]), i);
  }
  sort(tosort, tosort + m);
  for (int i = 0; i < m; i++) {
    int id = tosort[i].second;
    while (true) {
      if (xs[id] == i) {
        break;
      }
      int nx = (xs[id] < i ? xs[id] + 1 : xs[id] - 1);
      assert(c[nx][ys[id]] == -1);
      move(id, nx, ys[id]);
    }
  }
  for (int id = 0; id < m; id++) {
    while (true) {
      if (ys[id] == yt[id]) {
        break;
      }
      int ny = (ys[id] < yt[id] ? ys[id] + 1 : ys[id] - 1);
      assert(c[xs[id]][ny] == -1);
      move(id, xs[id], ny);
    }
  }
  while (true) {
    {
      bool ok = true;
      for (int id = 0; id < m; id++) {
        if (xs[id] != xt[id]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    for (int id = 0; id < m; id++) {
      while (true) {
        if (xs[id] == xt[id]) {
          break;
        }
        int nx = (xs[id] < xt[id] ? xs[id] + 1 : xs[id] - 1);
        if (c[nx][ys[id]] == -1) {
          move(id, nx, ys[id]);
        } else {
          break;
        }
      }
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    for (int j = 0; j < sz(ans[i]); j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
  }
}

int main() {
#ifdef DEBUG
	assert(freopen("text.in", "r", stdin));
	assert(freopen("text.out", "w", stdout));
#endif
	while (read()) {
		solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	}
	return 0;
}