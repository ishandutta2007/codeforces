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

const int maxlen = (int) 2e6 + 5, maxn = (int) 1e5 + 5;
char tmp[maxlen];
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  return true;
}

int cnt[maxlen][2];
int ps[2][maxlen];

int get(int n, int pos) {
  if (n <= 1) {
    return pos;
  }
  int l = n / 2, r = n - l;
  pos = get(l, pos);
  if (pos < 0) {
    return pos;
  }
  pos = get(r, pos);
  if (pos < 0) {
    return pos;
  }
  int res = inf;
  for (int c = 0; c < 2; ++c) {
    int x = cnt[pos][c] + (!c ? l : r);
    if (x > cnt[sz(s)][c]) {
      continue;
    }
    res = min(res, ps[c][x - 1] + 1);
  }
  if (res >= inf) {
    res = -1;
  }
  return res;
}

int p[maxn], q[maxn];

void rec(int l, int r, int &pos) {
  if (r - l <= 1) {
    p[l] = 0;
    return;
  }
  int m = (l + r) / 2;
  rec(l, m, pos);
  rec(m, r, pos);
  {
    int i = l, j = m, cur = 0;
    while (i < m && j < r) {
      if (s[pos++] == '0') {
        q[i++] = cur++;
      } else {
        q[j++] = cur++;
      }
    }
    while (i < m) {
      q[i++] = cur++;
    }
    while (j < r) {
      q[j++] = cur++;
    }
  }
  for (int i = l; i < m; ++i) {
    p[i] = q[l + p[i]];
  }
  for (int i = m; i < r; ++i) {
    p[i] = q[m + p[i]];
  }
}

void getAns(int n) {
  int pos = 0;
  rec(0, n, pos);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d ", p[i] + 1);
  }
  printf("\n");
}

void solve() {
  {
    int c[2] = {0, 0};
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    for (int i = 0; i < sz(s); ++i) {
      int cur = s[i] - '0';
      ps[cur][c[cur]] = i;
      ++c[cur];
      cnt[i + 1][0] = c[0];
      cnt[i + 1][1] = c[1];
    }
  }
  int l = 1, r = (int) 1e5;
  while (l < r) {
    int m = (l + r) / 2;
    int x = get(m, 0);
    if (x < 0) {
      r = m - 1;
    } else if (x < sz(s)) {
      l = m + 1;
    } else {
      getAns(m);
      return;
    }
  }
  getAns(l);
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