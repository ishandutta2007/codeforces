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

const int maxn = (int) 2e5 + 5;
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%d%s", &n, tmp) < 2) {
    return false;
  }
  s = tmp;
  return true;
}

string a, b;

void solve() {
  if (s[0] != '1' || s[n - 1] != '1') {
    printf("NO\n");
    return;
  }
  a.resize(n);
  b.resize(n);
  a[0] = '(';
  b[0] = '(';
  int x = 1, y = 1;
  for (int i = 1; i < n - 1; ++i) {
    if (s[i] == '1') {
      if ((x == 1 && y == 1) || (x == 0 && y == 2)) {
        a[i] = '(';
        ++x;
        b[i] = '(';
        ++y;
      } else {
        a[i] = ')';
        --x;
        b[i] = ')';
        --y;
      }
    } else {
      if (x == y) {
        a[i] = ')';
        --x;
        b[i] = '(';
        ++y;
      } else {
        a[i] = '(';
        ++x;
        b[i] = ')';
        --y;
      }
    }
  }
  if (x != 1 || y != 1) {
    printf("NO\n");
    return;
  }
  a[n - 1] = ')';
  b[n - 1] = ')';
  printf("YES\n");
  printf("%s\n", a.c_str());
  printf("%s\n", b.c_str());
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