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
int n;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int take[maxn];

void rec(int l, int r) {
  if (l >= r) {
    return;
  }
  if (l == r - 1) {
    take[l] = true;
    return;
  }
  if (s[l] == s[r - 1]) {
    take[l] = true;
    take[r - 1] = true;
    rec(l + 1, r - 1);
    return;
  }
  if (l == r - 2) {
    take[l] = true;
    return;
  }
  if (s[l] == s[r - 2]) {
    take[l] = true;
    take[r - 2] = true;
    rec(l + 1, r - 2);
    return;
  }
  if (s[l + 1] == s[r - 1]) {
    take[l + 1] = true;
    take[r - 1] = true;
    rec(l + 2, r - 1);
    return;
  }
  if (l == r - 3) {
    take[l] = true;
    return;
  }
  assert(s[l + 1] == s[r - 2]);
  take[l + 1] = true;
  take[r - 2] = true;
  rec(l + 2, r - 2);
}

void solve() {
  for (int i = 0; i < n; i++) {
    take[i] = false;
  }
  rec(0, n);
  string ans;
  for (int i = 0; i < n; i++) {
    if (take[i]) {
      ans += s[i];
    }
  }
  printf("%s\n", ans.c_str());
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