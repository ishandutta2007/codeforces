#ifdef DEBUG
#define _GLIBCXX_DEBUG
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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5, maxk = 10;
int n, m, k;
vector<pair<int, int>> g[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    --w;
    g[v].push_back(make_pair(w, u));
  }
  return true;
}

vector<int> vs[maxk][maxk];
int bad[maxk][maxk][maxk][maxk];
int taken[maxk];

bool check(const vector<int> &a, const vector<int> &b) {
  for (int i = 0, j = 0; i < sz(a) && j < sz(b);) {
    if (a[i] == b[j]) {
      return true;
    }
    if (a[i] < b[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  return false;
}

int gen(int p) {
  if (p > k) {
    return 1;
  }
  int res = 0;
  for (int i = 0; i < p; ++i) {
    taken[p] = i;
    bool ok = true;
    for (int q = 1; q <= p; ++q) {
      if (bad[q][taken[q]][p][taken[p]]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res += gen(p + 1);
    }
  }
  return res;
}

void solve() {
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < i; ++j) {
      vs[i][j].clear();
    }
  }
  for (int v = 0; v < n; ++v) {
    sort(g[v].begin(), g[v].end());
    int deg = sz(g[v]);
    for (int i = 0; i < deg; ++i) {
      int u = g[v][i].second;
      vs[deg][i].push_back(u);
    }
  }
  memset(bad, 0, sizeof(bad));
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < i; ++j) {
      auto &a = vs[i][j];
      sort(a.begin(), a.end());
      for (int l = 0; l + 1 < sz(a); ++l) {
        if (a[l + 1] == a[l]) {
          bad[i][j][i][j] = true;
        }
      }
    }
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < i; ++j) {
      const auto &a = vs[i][j];
      for (int ii = 1; ii <= k; ++ii) {
        for (int jj = 0; jj < ii; ++jj) {
          if (make_pair(ii, jj) <= make_pair(i, j)) {
            continue;
          }
          const auto &b = vs[ii][jj];
          if (check(a, b)) {
            bad[i][j][ii][jj] = true;
            bad[ii][jj][i][j] = true;
          }
        }
      }
    }
  }
  printf("%d\n", gen(1));
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