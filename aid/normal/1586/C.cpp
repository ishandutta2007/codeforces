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

const int maxn = (int) 1e6 + 5;
char tmp[maxn];
int n, m;
vector<string> c;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  c.clear();
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", tmp);
    c[i] = tmp;
  }
  return true;
}

int a[maxn], s[maxn];

void solve() {
  for (int i = 0; i < m; ++i) {
    a[i] = 0;
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      if (c[i + 1][j] == 'X' && c[i][j + 1] == 'X') {
        a[j] = 1;
      }
    }
  }
  s[0] = 0;
  for (int i = 0; i < m; ++i) {
    s[i + 1] = s[i] + a[i];
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; ++qq) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;
    if (s[r] - s[l] > 0) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
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