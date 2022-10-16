#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

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

  int type() const {
    return x > 0 || (x == 0 && y > 0);
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  return (a ^ b) > 0;
}

const int maxn = 4005;
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

point qs[maxn];

void solve() {
  long long res = 0;
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < n; i++) {
      if (i == s) {
        continue;
      }
      int ii = (i < s ? i : i - 1);
      qs[ii] = ps[i] - ps[s];
    }
    sort(qs, qs + n - 1);
    for (int i = 0; i < n - 1; i++) {
      qs[n - 1 + i] = qs[i];
    }
    for (int l = 0, r = 0; l < n - 1; l++) {
      r = max(r, l + 1);
      while (r < l + n - 1 && (qs[l] ^ qs[r]) > 0) {
        r++;
      }
      int a = (r - l - 1), b = n - a - 2;
      res += (long long) (a * (a - 1) / 2) * (long long) (b * (b - 1) / 2);
    }
  }
  eprintf("%lld\n", res);
  assert(!(res % 2));
  res /= 2;
  printf("%lld\n", res);
}

int main() {
#ifdef DEBUG
	assert(freopen("text.in", "r", stdin));
	assert(freopen("text.out", "w", stdout));
#endif
	while (read()) {
		solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	}
	return 0;
}