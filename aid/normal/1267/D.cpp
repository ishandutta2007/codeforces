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

const int maxn = 256;
int n;
int need[maxn], can[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    auto &cur = need[i];
    cur = 0;
    for (int j = 0; j < 3; j++) {
      int x;
      scanf("%d", &x);
      cur |= (x << j);
    }
  }
  for (int i = 0; i < n; i++) {
    auto &cur = can[i];
    cur = 0;
    for (int j = 0; j < 3; j++) {
      int x;
      scanf("%d", &x);
      cur |= (x << j);
    }
  }
  return true;
}

int vs[8], us[8];
int good[maxn];
int t[maxn];
vector<pair<int, int>> es;

void solve() {
  es.clear();
  for (int i = 0; i < 8; i++) {
    vs[i] = -1;
    us[i] = -1;
  }
  vs[0] = -2;
  for (int i = 0; i < n; i++) {
    if (us[need[i]] == -1) {
      us[need[i]] = i;
    }
    good[i] = false;
    if (need[i] == 0) {
      good[i] = true;
    }
    t[i] = true;
  }
  good[0] = true;
  while (true) {
    bool found = false;
    for (int v = 0; v < n; v++) {
      if (!good[v]) {
        continue;
      }
      int msk = (need[v] & can[v]);
      if (vs[msk] == -1) {
        found = true;
        vs[msk] = v;
        for (int u = 0; u < n; u++) {
          if (good[u] || need[u] != msk) {
            continue;
          }
          good[u] = true;
          es.push_back(make_pair(v, u));
        }
      }
    }
    for (int a = 0; a < 3; a++) {
      if (vs[(1 << a)] == -1) {
        continue;
      }
      for (int b = a + 1; b < 3; b++) {
        if (vs[(1 << b)] == -1) {
          continue;
        }
        int msk = ((1 << a) | (1 << b));
        if (vs[msk] != -1 || us[msk] == -1) {
          continue;
        }
        found = true;
        int va = vs[(1 << a)], vb = vs[(1 << b)], vab = us[msk];
        t[vab] = false;
        es.push_back(make_pair(va, vab));
        es.push_back(make_pair(vb, vab));
        vs[msk] = vab;
        good[vab] = true;
        for (int u = 0; u < n; u++) {
          if (good[u] || need[u] != msk) {
            continue;
          }
          good[u] = true;
          es.push_back(make_pair(vab, u));
        }
      }
    }
    if (!found) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!good[i]) {
      printf("Impossible\n");
      return;
    }
  }
  printf("Possible\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", t[i]);
  }
  printf("\n");
  printf("%d\n", sz(es));
  for (int i = 0; i < sz(es); i++) {
    printf("%d %d\n", es[i].first + 1, es[i].second + 1);
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