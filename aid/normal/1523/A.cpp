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

const int maxn = 1005;
char tmp[maxn];
int n, t;
string s, ns;

bool read() {
  if (scanf("%d%d", &n, &t) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

void solve() {
  while (t) {
    bool found = false;
    ns = s;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        continue;
      }
      int cnt = 0;
      for (int d = -1; d <= 1; d += 2) {
        int j = i + d;
        if (0 <= j && j < n && s[j] == '1') {
          ++cnt;
        }
      }
      if (cnt == 1) {
        ns[i] = '1';
        found = true;
      }
    }
    s = ns;
    --t;
    if (!found) {
      break;
    }
  }
  printf("%s\n", s.c_str());
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