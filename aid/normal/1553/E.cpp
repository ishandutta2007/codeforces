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

const int maxn = (int) 3e5 + 5;
int n, m;
int p[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  return true;
}

set<int> ans;
int used[maxn];

void solve() {
  ans.clear();
  for (int it = 0; it < 50; ++it) {
    int pos = rnd(n);
    int sh = (pos - p[pos] + n) % n;
    rotate(p, p + sh, p + n);
    for (int i = 0; i < n; ++i) {
      used[i] = false;
    }
    int need = n;
    for (int s = 0; s < n; ++s) {
      if (used[s]) {
        continue;
      }
      for (int v = s; !used[v]; v = p[v]) {
        used[v] = true;
      }
      --need;
    }
    if (need <= m) {
      ans.insert(sh);
    }
    sh = (n - sh) % n;
    rotate(p, p + sh, p + n);
  }
  printf("%d ", sz(ans));
  for (auto sh : ans) {
    printf("%d ", sh);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}