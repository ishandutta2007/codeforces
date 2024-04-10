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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
string s, t;
int p[maxn];
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  for (int i = 0; i < sz(s); i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int del[maxn];

bool check(int k) {
  for (int i = 0; i < sz(s); i++) {
    del[i] = false;
  }
  for (int i = 0; i < k; i++) {
    del[p[i]] = true;
  }
  string ss;
  for (int i = 0; i < sz(s); i++) {
    if (!del[i]) {
      ss += s[i];
    }
  }
  int j = 0;
  for (int i = 0; i < sz(ss); i++) {
    if (j < sz(t) && ss[i] == t[j]) {
      j++;
    }
  }
  return j >= sz(t);
}

void solve() {
  int l = 0, r = sz(s);
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%d\n", l);
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