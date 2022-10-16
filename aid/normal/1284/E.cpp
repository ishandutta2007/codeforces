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

struct point {
  int x, y;

  point(): x(0), y(0) {}

  point(int xx, int yy): x(xx), y(yy) {}

  bool read() {
    return scanf("%d%d", &x, &y) == 2;
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

  int type() const {
    return (x < 0 || (x == 0 && y < 0));
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  return (a ^ b) > 0;
}

const int maxn = 2505;
int n;
point ps[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

point qs[2 * maxn];

bool good(const point &a, const point &b) {
  long long cp = (a ^ b);
  return (cp > 0 || (cp == 0 && (a * b) > 0));
}

void solve() {
  long long res = (long long) n * (long long) (n - 1) * (long long) (n - 2) *
                  (long long) (n - 3) * (long long) (n - 4) / (4ll * 3ll * 2ll);
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < s; i++) {
      qs[i] = ps[i] - ps[s];
    }
    for (int i = s + 1; i < n; i++) {
      qs[i - 1] = ps[i] - ps[s];
    }
    sort(qs, qs + n - 1);
    for (int i = 0; i < n - 1; i++) {
      qs[n - 1 + i] = qs[i];
    }
    for (int l = 0, r = 0; l < n - 1; l++) {
      r = max(r, l);
      while (r < l + n - 1 && good(qs[l], qs[r])) {
        r++;
      }
      long long k = r - l - 1;
      res -= k * (k - 1) * (k - 2) / (3ll * 2ll);
    }
  }
  printf("%lld\n", res);
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