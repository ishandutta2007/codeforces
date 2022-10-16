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

const int maxn = (int) 3e5 + 5, maxlen = (int) 5e5 + 5;
char tmp[maxlen];
string s;
int n;
int xs[maxn][2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", tmp);
    s = tmp;
    int x = 0, y = 0;
    for (int j = 0; j < sz(s); ++j) {
      if (s[j] == 'B') {
        ++x;
      } else {
        ++y;
      }
    }
    xs[i][0] = x;
    xs[i][1] = y;
  }
  return true;
}

int ys[6];

void intersect(int i, int yi, int j, int yj, int &x, int &y) {
  if (j == 1) {
    swap(i, j);
    swap(yi, yj);
  }
  if (i == 1) {
    if (j == 0) {
      y = yj;
      x = y + yi;
    } else {
      x = yj;
      y = x - yi;
    }
    return;
  }
  if (i == 2) {
    swap(i, j);
    swap(yi, yj);
  }
  assert(i == 0 && j == 2);
  x = yj;
  y = yi;
}

bool inside(int x, int y) {
  return ys[0] <= y && x - y <= ys[1] && x <= ys[2] &&
         y <= ys[3] && ys[4] <= x - y && ys[5] <= x;
}

bool check(int d, bool out) {
  for (int it = 0; it < 2; ++it) {
    ys[0] = 0;
    ys[1] = maxlen;
    ys[2] = maxlen;
    ys[3] = maxlen;
    ys[4] = -maxlen;
    ys[5] = 0;
    if (!it) {
      ++ys[0];
    } else {
      ++ys[5];
    }
    for (int i = 0; i < n; ++i) {
      ys[0] = max(ys[0], xs[i][1] - d);
      ys[1] = min(ys[1], xs[i][0] - xs[i][1] + d);
      ys[2] = min(ys[2], xs[i][0] + d);
      ys[3] = min(ys[3], xs[i][1] + d);
      ys[4] = max(ys[4], xs[i][0] - xs[i][1] - d);
      ys[5] = max(ys[5], xs[i][0] - d);
    }
    if (ys[0] > ys[3] || ys[4] > ys[1] || ys[5] > ys[2]) {
      continue;
    }
    for (int i = 0; i < 6; ++i) {
      for (int j = i + 1; j < 6; ++j) {
        if (j - i == 3) {
          continue;
        }
        int x, y;
        intersect(i % 3, ys[i], j % 3, ys[j], x, y);
        if (inside(x, y)) {
          if (out) {
            printf("%d\n", d);
            string ans = string(x, 'B') + string(y, 'N');
            printf("%s\n", ans.c_str());
          }
          return true;
        }
      }
    }
  }
  return false;
}

void solve() {
  int l = -1, r = maxlen;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m, false)) {
      r = m;
    } else {
      l = m;
    }
  }
  assert(check(r, true));
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