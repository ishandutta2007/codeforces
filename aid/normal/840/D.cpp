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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 3e5 + 5, maxk = 5;
int n, q;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

set<int> ps[maxn];
int b[maxn];

int get(int x, int l, int r) {
  int res = 0;
  for (int iter = 0; iter < 2; iter++) {
    auto it = ps[x].lower_bound(!iter ? r : l);
    int toadd;
    if (it == ps[x].end()) {
      toadd = sz(ps[x]);
    } else {
      toadd = b[*it];
    }
    if (!iter) {
      res += toadd;
    } else {
      res -= toadd;
    }
  }
  return res;
}

vector< pair<pair<int, int>, pair<int, int> > > qs[4 * maxn];
int ans[maxn];

void addQuery(int v, int tl, int tr, int l, int r, int k, int id) {
  if (tl == tr - 1) {
    qs[v].push_back(make_pair(make_pair(l, r), make_pair(k, id)));
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm && r > tm) {
    qs[v].push_back(make_pair(make_pair(l, r), make_pair(k, id)));
    return;
  }
  if (r <= tm) {
    addQuery(2 * v, tl, tm, l, r, k, id);
  } else {
    addQuery(2 * v + 1, tm, tr, l, r, k, id);
  }
}

int cnt[maxn];
int x[maxn][maxk];

void solve(int v, int tl, int tr) {
  if (tl == tr - 1) {
    for (int i = 0; i < sz(qs[v]); i++) {
      ans[qs[v][i].second.second] = a[tl];
    }
    return;
  }
  int tm = (tl + tr) / 2;
  solve(2 * v, tl, tm);
  solve(2 * v + 1, tm, tr);
  if (qs[v].empty()) {
    return;
  }
  {
    for (int i = 0; i < maxk; i++) {
      x[tm][i] = maxn - 1;
    }
    for (int i = tm; i < tr; i++) {
      for (int j = 0; j < maxk; j++) {
        x[i + 1][j] = x[i][j];
      }
      cnt[a[i]]++;
      bool ok = true;
      for (int j = 0; j < maxk; j++) {
        if (x[i + 1][j] == a[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int j = 0; j < maxk; j++) {
          if (cnt[x[i + 1][j]] < cnt[a[i]]) {
            x[i + 1][j] = a[i];
            break;
          }
        }
      }
    }
    for (int i = 0; i < sz(qs[v]); i++) {
      int l = qs[v][i].first.first, r = qs[v][i].first.second, k = qs[v][i].second.first, id = qs[v][i].second.second;
      for (int j = 0; j < maxk; j++) {
        if (get(x[r][j], l, r) * k > r - l) {
          ans[id] = min(ans[id], x[r][j]);
        }
      }
    }
    for (int i = tm; i < tr; i++) {
      cnt[a[i]] = 0;
    }
  }
  {
    for (int i = 0; i < maxk; i++) {
      x[tm][i] = maxn - 1;
    }
    for (int i = tm - 1; i >= tl; i--) {
      for (int j = 0; j < maxk; j++) {
        x[i][j] = x[i + 1][j];
      }
      cnt[a[i]]++;
      bool ok = true;
      for (int j = 0; j < maxk; j++) {
        if (x[i][j] == a[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int j = 0; j < maxk; j++) {
          if (cnt[x[i][j]] < cnt[a[i]]) {
            x[i][j] = a[i];
            break;
          }
        }
      }
    }
    for (int i = 0; i < sz(qs[v]); i++) {
      int l = qs[v][i].first.first, r = qs[v][i].first.second, k = qs[v][i].second.first, id = qs[v][i].second.second;
      for (int j = 0; j < maxk; j++) {
        if (get(x[l][j], l, r) * k > r - l) {
          ans[id] = min(ans[id], x[l][j]);
        }
      }
    }
    for (int i = tl; i < tm; i++) {
      cnt[a[i]] = 0;
    }
  }
}

void solve() {
  for (int i = 0; i < maxn; i++) {
    ps[i].clear();
  }
  for (int i = 0; i < n; i++) {
    b[i] = sz(ps[a[i]]);
    ps[a[i]].insert(i);
  }
  for (int i = 0; i < 4 * maxn; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--;
    addQuery(1, 0, n, l, r, k, i);
    ans[i] = inf;
  }
  solve(1, 0, n);
  for (int i = 0; i < q; i++) {
    if (ans[i] >= inf) {
      ans[i] = -1;
    }
    printf("%d\n", ans[i]);
  }
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