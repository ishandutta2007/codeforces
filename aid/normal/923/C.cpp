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

const int maxn = (int) 3e5 + 5, maxb = 30;
int n;
int a[maxn], b[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

const int maxv = maxn * maxb;
int vs;
int go[maxv][2], cnt[maxv];

int newNode() {
  go[vs][0] = -1;
  go[vs][1] = -1;
  cnt[vs] = 0;
  return vs++;
}

void solve() {
  vs = 0;
  int root = newNode();
  for (int i = 0; i < n; i++) {
    int x = b[i];
    int v = root;
    cnt[v]++;
    for (int bit = maxb - 1; bit >= 0; bit--) {
      int d = ((x >> bit) & 1);
      if (go[v][d] == -1) {
        go[v][d] = newNode();
      }
      v = go[v][d];
      cnt[v]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int res = 0;
    int v = root;
    cnt[v]--;
    for (int bit = maxb - 1; bit >= 0; bit--) {
      int d = ((x >> bit) & 1);
      if (go[v][d] == -1 || !cnt[go[v][d]]) {
        d ^= 1;
        res ^= (1 << bit);
      }
      assert(go[v][d] != -1);
      v = go[v][d];
      assert(cnt[v]);
      cnt[v]--;
    }
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