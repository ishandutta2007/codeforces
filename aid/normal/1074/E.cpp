#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 25;
int n, m;
int a[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  return true;
}

const int maxv = (int) 4e5 + 5;
map<int, int> ids;
vector<int> ps[maxv];
int d[maxv];
int p[maxv];
vector<int> pc[maxv];

int getHash(const vector<int> &p) {
  int res = 0;
  for (int i = 0; i < sz(p); i++) {
    res = res * 9 + p[i];
  }
  return res;
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

int b[maxn][maxn];
int used[maxn][maxn];

bool inside(int x, int y) {
  return 0 <= x && x < 3 && 0 <= y && y < 3;
}

vector<vector<int>> ans;

void solve3() {
  int n = 3;
  {
    vector<int> perm;
    for (int i = 0; i < n * n; i++) {
      perm.push_back(i);
    }
    ids.clear();
    int cur = 0;
    while (true) {
      ps[cur] = perm;
      d[cur] = inf;
      p[cur] = -1;
      pc[cur].clear();
      ids[getHash(perm)] = cur++;
      if (!next_permutation(perm.begin(), perm.end())) {
        break;
      }
    }
  }
  vector<int> q;
  d[0] = 0;
  q.push_back(0);
  memset(used, 0, sizeof(used));
  vector<vector<int>> es;
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j + 1 < n; j++) {
      vector<int> curc = {i * n + j, (i + 1) * n + j, (i + 1) * n + (j + 1), i * n + (j + 1)};
      es.push_back(curc);
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    const auto &curp = ps[v];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        b[i][j] = curp[i * n + j];
      }
    }
    vector<int> curq(n * n);
    for (int i = 0; i < n * n; i++) {
      curq[curp[i]] = i;
    }
    for (int e = 0; e < sz(es); e++) {
      vector<int> np = curp;
      const auto &cure = es[e];
      for (int i = 0; i < sz(cure); i++) {
        int ni = (i + 1) % sz(cure);
        np[cure[ni]] = curp[cure[i]];
      }
      int u = ids[getHash(np)];
      if (d[u] >= inf) {
        d[u] = d[v] + 1;
        p[u] = v;
        pc[u] = cure;
        reverse(pc[u].begin(), pc[u].end());
        for (int i = 0; i < sz(pc[u]); i++) {
          pc[u][i] = np[pc[u][i]];
        }
        q.push_back(u);
      }
    }
  }
  for (int i = 0; i < sz(ids); i++) {
    assert(d[i] < inf);
  }
  vector<int> curp(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = a[i][j] / m, y = a[i][j] % m;
      curp[i * n + j] = x * n + y;
    }
  }
  int k = sz(ans);
  int v = ids[getHash(curp)];
  while (v) {
    ans.push_back(pc[v]);
    v = p[v];
  }
  for (int i = k; i < sz(ans); i++) {
    for (int j = 0; j < sz(ans[i]); j++) {
      int x = ans[i][j] / n, y = ans[i][j] % n;
      ans[i][j] = x * m + y;
    }
  }
}

void getPos(int v, int &x, int &y) {
  for (int ii = 0; ii < n; ii++) {
    for (int jj = 0; jj < m; jj++) {
      if (a[ii][jj] == v) {
        x = ii;
        y = jj;
        return;
      }
    }
  }
}

void rot(const vector<int> &c) {
  vector<int> ids;
  int tmp = a[c.back() / m][c.back() % m];
  for (int i = sz(c) - 1; i >= 0; i--) {
    int x = c[i] / m, y = c[i] % m;
    int val;
    if (i) {
      int px = c[i - 1] / m, py = c[i - 1] % m;
      val = a[px][py];
    } else {
      val = tmp;
    }
    a[x][y] = val;
    ids.push_back(val);
  }
  reverse(ids.begin(), ids.end());
  ans.push_back(ids);
}

void solve() {
  ans.clear();
  for (int i = n - 1; i > 1; i--) {
    for (int j = m - 1; j > 1; j--) {
      int v = i * m + j;
      int x = -1, y = -1;
      while (a[0][0] != v) {
        getPos(v, x, y);
        vector<int> c;
        if (!x) {
          c = {x * m + y, x * m + (y - 1), (x + 1) * m + (y - 1), (x + 1) * m + y};
        } else if (!y) {
          c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y + 1), x * m + (y + 1)};
        } else {
          c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y - 1), x * m + (y - 1)};
        }
        rot(c);
      }
      while (a[i][j] != v) {
        getPos(v, x, y);
        vector<int> c;
        if (x == i) {
          c = {x * m + y, x * m + (y + 1), (x - 1) * m + (y + 1), (x - 1) * m + y};
        } else if (y == j) {
          c = {x * m + y, (x + 1) * m + y, (x + 1) * m + (y - 1), x * m + (y - 1)};
        } else {
          c = {x * m + y, (x + 1) * m + y, (x + 1) * m + (y + 1), x * m + (y + 1)};
        }
        rot(c);
      }
    }
    {
      int v = i * m + 1, u = i * m + 0;
      int x = -1, y = -1;
      while (a[0][0] != v) {
        getPos(v, x, y);
        vector<int> c;
        if (!x) {
          c = {x * m + y, x * m + (y - 1), (x + 1) * m + (y - 1), (x + 1) * m + y};
        } else if (!y) {
          c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y + 1), x * m + (y + 1)};
        } else {
          c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y - 1), x * m + (y - 1)};
        }
        rot(c);
      }
      while (true) {
        getPos(u, x, y);
        if (x <= 1 && y <= 1) {
          break;
        }
        vector<int> c;
        if (!x) {
          c = {x * m + y, x * m + (y - 1), (x + 1) * m + (y - 1), (x + 1) * m + y};
        } else if (!y) {
          c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y + 1), x * m + (y + 1)};
        } else {
          c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y - 1), x * m + (y - 1)};
        }
        rot(c);
      }
      if (x == 1) {
        vector<int> c;
        if (y == 0) {
          c = {1 * m + 0, 1 * m + 1, 2 * m + 1, 2 * m + 0};
          rot(c);
        }
        c = {0 * m + 1, 0 * m + 2, 1 * m + 2, 1 * m + 1};
        rot(c);
      }
      vector<int> c;
      for (int ii = 0; ii <= i; ii++) {
        c.push_back(ii * m + 0);
      }
      for (int ii = i; ii >= 0; ii--) {
        c.push_back(ii * m + 1);
      }
      while (a[i][1] != v) {
        rot(c);
      }
    }
  }
  for (int j = m - 1; j > 2; j--) {
    int v = 1 * m + j, u = 0 * m + j;
    int x = -1, y = -1;
    while (a[0][0] != v) {
      getPos(v, x, y);
      vector<int> c;
      if (!x) {
        c = {x * m + y, x * m + (y - 1), (x + 1) * m + (y - 1), (x + 1) * m + y};
      } else if (!y) {
        c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y + 1), x * m + (y + 1)};
      } else {
        c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y - 1), x * m + (y - 1)};
      }
      rot(c);
    }
    while (true) {
      getPos(u, x, y);
      if (x <= 1 && y <= 1) {
        break;
      }
      vector<int> c;
      if (!x) {
        c = {x * m + y, x * m + (y - 1), (x + 1) * m + (y - 1), (x + 1) * m + y};
      } else if (!y) {
        c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y + 1), x * m + (y + 1)};
      } else {
        c = {x * m + y, (x - 1) * m + y, (x - 1) * m + (y - 1), x * m + (y - 1)};
      }
      rot(c);
    }
    if (y == 1) {
      vector<int> c;
      if (x == 0) {
        c = {0 * m + 1, 0 * m + 2, 1 * m + 2, 1 * m + 1};
        rot(c);
        rot(c);
        rot(c);
      }
      c = {1 * m + 0, 1 * m + 1, 2 * m + 1, 2 * m + 0};
      rot(c);
      rot(c);
      rot(c);
    }
    vector<int> c;
    for (int jj = 0; jj <= j; jj++) {
      c.push_back(0 * m + jj);
    }
    for (int jj = j; jj >= 0; jj--) {
      c.push_back(1 * m + jj);
    }
    while (a[1][j] != v) {
      rot(c);
    }
  }
  solve3();
  int cnt = 0;
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", sz(ans[i]));
    cnt += sz(ans[i]);
    for (int j = 0; j < sz(ans[i]); j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
  }
  eprintf("%d\n", cnt);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}