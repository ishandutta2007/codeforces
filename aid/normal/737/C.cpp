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

const int maxn = (int) 2e5 + 5;
int n, s;
int a[maxn];
int ok[maxn], sup[maxn], sdown[maxn];

int read() {
  if (scanf("%d%d", &n, &s) < 2) {
    return false;
  }
  s--;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

#define free mfree

void solve() {
  int ss = 0;
  if (a[s]) {
    a[s] = 0;
    ss++;
  }
  if (n == 1) {
    printf("%d\n", ss);
    return;
  }
  int free = 0;
  for (int i = 0; i < n; i++) {
    if (i != s && !a[i]) {
      free++;
    }
  }
  for (int i = 0; i < n; i++) {
    ok[i] = 0;
    sup[i] = 0;
    sdown[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    ok[a[i]] = 1;
    sup[a[i]]++;
    sdown[a[i]]++;
  }
  sup[0] = 0;
  sdown[0] = 0;
  for (int i = 1; i < n; i++) {
    sup[i] = max(0, sup[i] - 1);
    sup[i] += sup[i - 1];
    ok[i] += ok[i - 1];
  }
  sdown[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    sdown[i] += sdown[i + 1];
  }
  int res = inf;
  for (int d = 1; d < n; d++) {
    int have = free + sdown[d + 1];
    int need = max(0, d + 1 - ok[d] - have);
    if (sup[d] < need) {
      continue;
    }
    int cur = ss + have + need;
    res = min(res, cur);
  }
  printf("%d\n", res);
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