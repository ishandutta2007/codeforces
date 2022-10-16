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
char tmp[maxn];
int n, q;
string s;

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

void solve() {
  int res = 0;
  for (int i = 0; i + 3 <= n; ++i) {
    if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
      ++res;
    }
  }
  for (int qq = 0; qq < q; ++qq) {
    int i;
    scanf("%d%s", &i, tmp);
    --i;
    char c = tmp[0];
    for (int j = max(0, i - 2); j <= min(i, n - 3); ++j) {
      if (s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c') {
        --res;
      }
    }
    s[i] = c;
    for (int j = max(0, i - 2); j <= min(i, n - 3); ++j) {
      if (s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c') {
        ++res;
      }
    }
    printf("%d\n", res);
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