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

string s;
char tmp[100];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  return true;
}

const int sigma = 26;
int cnt[sigma];
char ans[2][14];

void solve() {
  for (int i = 0; i < sigma; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < sz(s); i++) {
    cnt[s[i] - 'A']++;
  }
  char c;
  for (int i = 0; i < sigma; i++) {
    assert(cnt[i] >= 1);
    if (cnt[i] > 1) {
      c = 'A' + i;
    }
  }
  string a, b;
  int i0 = 0;
  for (; s[i0] != c; i0++) {
    a += s[i0];
  }
  reverse(a.begin(), a.end());
  int i1 = sz(s) - 1;
  for (; s[i1] != c; i1--) {
    a += s[i1];
  }
  if (i1 == i0 + 1) {
    printf("Impossible\n");
    return;
  }
  for (int i = i0 + 1; i < i1; i++) {
    b += s[i];
  }
  if (sz(a) & 1) {
    swap(a, b);
  }
  assert(!(sz(a) & 1));
  assert(sz(b) & 1);
  int l = sz(a) / 2;
  for (int i = 0; i < l; i++) {
    ans[0][i] = a[l - i - 1];
    ans[1][i] = a[l + i];
  }
  ans[0][l] = c;
  int r = sz(b) / 2;
  for (int i = 0; i < r; i++) {
    ans[0][l + 1 + i] = b[i];
    ans[1][l + 1 + i] = b[2 * r - i - 1];
  }
  ans[1][l] = b[2 * r];
  ans[0][13] = 0;
  ans[1][13] = 0;
  printf("%s\n%s\n", ans[0], ans[1]);
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