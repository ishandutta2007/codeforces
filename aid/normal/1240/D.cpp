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
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int c[maxn];
int len[maxn];
int cs;
map<int, int> mp[maxn];

void solve() {
  cs = 1;
  mp[0].clear();
  c[n] = 0;
  len[n] = 0;
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = a[i];
    int cc = c[i + 1];
    if (!mp[cc].count(x)) {
      mp[cs].clear();
      mp[cs][x] = i;
      c[i] = cs++;
      len[i] = 0;
    } else {
      int j = mp[cc][x] + 1;
      c[i] = c[j];
      mp[c[i]][x] = i;
      len[i] = len[j] + 1;
    }
    res += len[i];
  }
  printf("%lld\n", res);
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