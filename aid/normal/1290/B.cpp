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
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

const int sigma = 26;
int sum[maxn][sigma];

bool check(int l, int r) {
  int cnt = 0;
  for (int c = 0; c < sigma; c++) {
    if (sum[r][c] > sum[l][c]) {
      cnt++;
    }
  }
  if (cnt >= 3) {
    return true;
  }
  if (cnt == 2) {
    return s[l] != s[r - 1];
  }
  return r - l == 1;
}

void solve() {
  for (int c = 0; c < sigma; c++) {
    sum[0][c] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < sigma; c++) {
      sum[i + 1][c] = sum[i][c];
    }
    sum[i + 1][s[i] - 'a']++;
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    if (check(l, r)) {
      printf("Yes\n");
    } else {
      printf("No\n");
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