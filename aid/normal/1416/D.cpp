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

const int maxn = (int) 2e5 + 5, maxm = (int) 3e5 + 5, maxq = (int) 5e5 + 5;
int n, m, q;
int a[maxn];
int es[maxm][2];
int qs[maxq][2];

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &es[i][j]);
      --es[i][j];
    }
  }
  for (int i = 0; i < q; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &qs[i][j]);
    }
    --qs[i][1];
  }
  return true;
}

int del[maxm];
int delv[maxn];
int p[maxn];
int who[maxn];
priority_queue<int> vs[maxn];
vector<int> vvs[maxn];
vector<pair<int, int>> st;

int get(int x) {
  return (p[x] == x ? x : get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (sz(vvs[x]) < sz(vvs[y])) {
    swap(x, y);
  }
  p[y] = x;
  vvs[x].insert(vvs[x].end(), vvs[y].begin(), vvs[y].end());
  st.push_back(make_pair(x, y));
  return true;
}

void rollback() {
  int y = st.back().second;
  st.pop_back();
  for (auto val : vvs[y]) {
    if (delv[val]) {
      continue;
    }
    vs[y].push(val);
    who[val] = y;
  }
  p[y] = y;
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    delv[i] = false;
  }
  for (int i = 0; i < m; ++i) {
    del[i] = false;
  }
  for (int i = 0; i < q; ++i) {
    if (qs[i][0] == 2) {
      del[qs[i][1]] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    vvs[i] = {a[i]};
  }
  st.clear();
  for (int i = 0; i < m; ++i) {
    if (del[i]) {
      continue;
    }
    unite(es[i][0], es[i][1]);
  }
  for (int i = q - 1; i >= 0; --i) {
    if (qs[i][0] != 2) {
      continue;
    }
    int e = qs[i][1];
    qs[i][1] = unite(es[e][0], es[e][1]);
  }
  for (int i = 0; i < n; ++i) {
    while (!vs[i].empty()) {
      vs[i].pop();
    }
    if (p[i] == i) {
      for (auto val : vvs[i]) {
        vs[i].push(val);
        who[val] = i;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    if (qs[i][0] == 1) {
      int v = qs[i][1];
      v = get(v);
      int res = 0;
      while (!vs[v].empty() && (delv[vs[v].top()] || who[vs[v].top()] != v)) {
        vs[v].pop();
      }
      if (!vs[v].empty()) {
        res = vs[v].top();
        vs[v].pop();
        delv[res] = true;
      }
      printf("%d\n", res);
    } else {
      if (qs[i][1]) {
        rollback();
      }
    }
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