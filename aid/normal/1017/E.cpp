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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct point {
  int x, y;

  point(): x(0), y(0) {}

  point(int _x, int _y): x(_x), y(_y) {}

  bool read() {
    return (scanf("%d%d", &x, &y) == 2);
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  long long operator ^ (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }

  long long operator * (const point &p) const {
    return (long long) x * p.x + (long long) y * p.y;
  }

  long long slen() const {
    return *this * *this;
  }
};

bool operator < (const point &a, const point &b) {
  long long cp = (a ^ b);
  if (cp) {
    return cp > 0;
  }
  return a.slen() < b.slen();
}

const int maxn = (int) 8e5 + 5;
int n[2];
point ps[2][maxn];

int read() {
  if (scanf("%d%d", &n[0], &n[1]) < 2) {
    return false;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n[t]; i++) {
      ps[t][i].read();
    }
  }
  return true;
}

vector<point> buildCH(int n, point ps[maxn]) {
  for (int i = 1; i < n; i++) {
    if (ps[i].x < ps[0].x || (ps[i].x == ps[0].x && ps[i].y < ps[0].y)) {
      swap(ps[i], ps[0]);
    }
  }
  for (int i = 1; i < n; i++) {
    ps[i] = ps[i] - ps[0];
  }
  sort(ps + 1, ps + n);
  for (int i = 1; i < n; i++) {
    ps[i] = ps[i] + ps[0];
  }
  vector<point> ch;
  for (int i = 0; i < n; i++) {
    while (sz(ch) >= 2 && ((ch[sz(ch) - 1] - ch[sz(ch) - 2]) ^ (ps[i] - ch[sz(ch) - 1])) <= 0) {
      ch.pop_back();
    }
    ch.push_back(ps[i]);
  }
  return ch;
}

long long a[2][maxn];
long long s[maxn];
long long z[maxn];

void solve() {
  for (int t = 0; t < 2; t++) {
    vector<point> ch = buildCH(n[t], ps[t]);
    n[t] = sz(ch);
    for (int i = 0; i < n[t]; i++) {
      ps[t][i] = ch[i];
    }
    ps[t][n[t]] = ps[t][0];
    ps[t][n[t] + 1] = ps[t][1];
    for (int i = 0; i < n[t]; i++) {
      a[t][2 * i] = (ps[t][i + 1] - ps[t][i]).slen();
      a[t][2 * i + 1] = ((ps[t][i + 1] - ps[t][i]) * (ps[t][i + 2] - ps[t][i + 1]));
    }
    for (int i = 0; i < 2 * n[t]; i++) {
      a[t][2 * n[t] + i] = a[t][i];
    }
  }
  for (int i = 0; i < 2 * n[1]; i++) {
    s[i] = a[1][i];
  }
  for (int i = 0; i < 4 * n[0]; i++) {
    s[2 * n[1] + i] = a[0][i];
  }
  z[0] = -1;
  int len = 2 * n[1] + 4 * n[0];
  for (int i = 1, l = 0, r = -1; i < len; i++) {
    if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < len && s[r - l] == s[r]) {
        r++;
      }
      z[i] = r - l;
    }
  }
  for (int i = 2 * n[1]; i < len; i += 2) {
    if (z[i] >= 2 * n[1]) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
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