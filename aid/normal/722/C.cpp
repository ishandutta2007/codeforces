#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn], per[maxn];
int p[maxn], ts[maxn];
long long sum[maxn], ans[maxn], curans;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &per[i]);
    per[i]--;
  }
  return true;
}

int get(int x) {
  return p[x] == x? x : p[x] = get(p[x]);
}

void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  p[y] = x;
  ts[x] += ts[y];
  sum[x] += sum[y];
  curans = max(curans, sum[x]);
}

void solve() {
  curans = 0;
  for (int i = 0; i < n; i++) {
    p[i] = -1;
    ts[i] = 1;
    sum[i] = a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = curans;
    int x = per[i];
    p[x] = x;
    curans = max(curans, sum[x]);
    if (x + 1 < n && p[x + 1] != -1) {
      unite(x, x + 1);
    }
    if (x > 0 && p[x - 1] != -1) {
      unite(x - 1, x);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%lld\n", ans[i]);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}