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
int n;
long long a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

const int maxb = 60;
int cnt[maxb];
int d[maxn];
vector<int> g[maxn];
vector<int> q;

void solve() {
  {
    int nn = 0;
    for (int i = 0; i < n; i++) {
      if (a[i]) {
        a[nn++] = a[i];
      }
    }
    n = nn;
  }
  for (int i = 0; i < maxb; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int b = 0; b < maxb; b++) {
      if ((a[i] >> b) & 1) {
        cnt[b]++;
      }
    }
  }
  for (int i = 0; i < maxb; i++) {
    if (cnt[i] >= 3) {
      printf("3\n");
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] & a[j]) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  int res = inf;
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < n; i++) {
      d[i] = inf;
    }
    q.clear();
    d[s] = 0;
    q.push_back(s);
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (d[u] < inf) {
          if (d[u] >= d[v]) {
            res = min(res, d[v] + d[u] + 1);
          }
          continue;
        }
        d[u] = d[v] + 1;
        q.push_back(u);
      }
    }
  }
  if (res >= inf) {
    res = -1;
  }
  printf("%d\n", res);
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