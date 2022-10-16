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
int n, m;
long long bal[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    bal[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    bal[v] += w;
    bal[u] -= w;
  }
  return true;
}

vector<pair<pair<int, int>, long long>> es;

void solve() {
  es.clear();
  for (int v = 0, u = 0; v < n; v++) {
    if (bal[v] <= 0) {
      continue;
    }
    while (bal[v]) {
      while (bal[u] >= 0) {
        u++;
      }
      long long x = min(bal[v], -bal[u]);
      es.push_back(make_pair(make_pair(v, u), x));
      bal[v] -= x;
      bal[u] += x;
    }
  }
  printf("%d\n", sz(es));
  for (int i = 0; i < sz(es); i++) {
    printf("%d %d %lld\n", es[i].first.first + 1, es[i].first.second + 1, es[i].second);
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