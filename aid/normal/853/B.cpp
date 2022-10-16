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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5, maxt = (int) 1e6 + 5;
int n, m, k;
vector< pair<pair<int, int>, int> > evs[maxt];

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < maxt; i++) {
    evs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int d, f, t, c;
    scanf("%d%d%d%d", &d, &f, &t, &c);
    evs[d].push_back(make_pair(make_pair(f, t), c));
  }
  return true;
}

int c[maxn];
long long l[maxt], r[maxt];

void solve() {
  c[0] = 0;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = inf;
    sum += c[i];
  }
  int cnt = n;
  for (int t = 0; t < maxt; t++) {
    if (!cnt) {
      l[t] = sum;
    } else {
      l[t] = infll;
    }
    for (int i = 0; i < sz(evs[t]); i++) {
      int v = evs[t][i].first.first, u = evs[t][i].first.second, w = evs[t][i].second;
      if (u == 0) {
        if (c[v] == inf) {
          cnt--;
        }
        sum -= c[v];
        c[v] = min(c[v], w);
        sum += c[v];
      }
    }
  }
  c[0] = 0;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = inf;
    sum += c[i];
  }
  cnt = n;
  for (int t = maxt - 1; t >= 0; t--) {
    for (int i = 0; i < sz(evs[t]); i++) {
      int v = evs[t][i].first.first, u = evs[t][i].first.second, w = evs[t][i].second;
      if (v == 0) {
        if (c[u] == inf) {
          cnt--;
        }
        sum -= c[u];
        c[u] = min(c[u], w);
        sum += c[u];
      }
    }
    if (!cnt) {
      r[t] = sum;
    } else {
      r[t] = infll;
    }
  }
  long long res = infll;
  for (int i = 0; i + k < maxt; i++) {
    res = min(res, l[i] + r[i + k]);
  }
  if (res >= infll) {
    res = -1;
  }
  printf("%lld\n", res);
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