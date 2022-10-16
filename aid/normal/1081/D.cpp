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

const int maxn = (int) 1e5 + 5;
int n, m, k;
int good[maxn];
pair<int, pair<int, int>> es[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    good[i] = false;
  }
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    x--;
    good[x] = true;
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    es[i] = make_pair(w, make_pair(v, u));
  }
  return true;
}

int p[maxn], ts[maxn], cnt[maxn];

int get(int v) {
  return (p[v] == v ? v : p[v] = get(p[v]));
}

bool unite(int v, int u) {
  v = get(v);
  u = get(u);
  if (v == u) {
    return false;
  }
  if (ts[v] < ts[u]) {
    swap(v, u);
  }
  ts[v] += ts[u];
  cnt[v] += cnt[u];
  p[u] = v;
  return cnt[v] >= k;
}

void solve() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    ts[i] = 1;
    cnt[i] = good[i];
  }
  sort(es, es + m);
  int res = -1;
  for (int i = 0; i < m; i++) {
    int w = es[i].first, v = es[i].second.first, u = es[i].second.second;
    if (unite(v, u)) {
      res = w;
      break;
    }
  }
  assert(res != -1);
  for (int i = 0; i < k; i++) {
    printf("%d ", res);
  }
  printf("\n");
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