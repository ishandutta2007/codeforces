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

const int maxn = (int) 5e5 + 5;
int n, k;
char tmp[maxn];
string s, t;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

void solve() {
  if (k == 1) {
    printf("%d\n", n);
    return;
  }
  long long res = 0;
  {
    int pos = 0;
    while (pos < n && s[pos] == t[pos]) {
      pos++;
    }
    if (pos >= n) {
      printf("%d\n", n);
      return;
    }
    res += pos;
    s = s.substr(pos, n - pos);
    t = t.substr(pos, n - pos);
    n -= pos;
  }
  int cnt = 0;
  if (k == 2) {
    res += 2 * n;
    printf("%lld\n", res);
    return;
  }
  res += 2;
  for (int i = 1; i < n; i++) {
    int ncnt = 2 * cnt;
    if (s[i] == 'a') {
      ncnt++;
    }
    if (t[i] == 'b') {
      ncnt++;
    }
    if (ncnt >= k - 2) {
      res += (long long) k * (n - i);
      printf("%lld\n", res);
      return;
    }
    cnt = ncnt;
    res += cnt + 2;
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