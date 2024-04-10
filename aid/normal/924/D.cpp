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

  void read() {
    assert(scanf("%d%d", &x, &y) == 2);
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
};

bool cmp0(const pair<point, int> &a, const pair<point, int> &b) {
  point pa = a.first, pb = b.first;
  if (pa.x < 0) {
    pa.x *= -1;
    pa.y *= -1;
  }
  if (pb.x < 0) {
    pb.x *= -1;
    pb.y *= -1;
  }
  long long cp = (pa ^ pb);
  if (cp) {
    return cp > 0;
  }
  pa = a.first;
  pb = b.first;
  if ((pa.x < 0) != (pb.x < 0)) {
    return pa.x < 0;
  }
  return pa.x > pb.x;
}

bool cmp1(const pair<point, int> &a, const pair<point, int> &b) {
  point pa = a.first, pb = b.first;
  if (pa.x < 0) {
    pa.x *= -1;
    pa.y *= -1;
  }
  if (pb.x < 0) {
    pb.x *= -1;
    pb.y *= -1;
  }
  long long cp = (pa ^ pb);
  if (cp) {
    return cp > 0;
  }
  pa = a.first;
  pb = b.first;
  if ((pa.x < 0) != (pb.x < 0)) {
    return pa.x > 0;
  }
  return pa.x < pb.x;
}

const int maxn = (int) 1e5 + 5;
int n, w;
point ps[maxn];

int read() {
  if (scanf("%d%d", &n, &w) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

pair<point, int> tosort[maxn];
int a[maxn], b[maxn];
int pos[maxn];
int fen[maxn];

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

void add(int i, int toadd) {
  for (; i < n; i |= i + 1) {
    fen[i] += toadd;
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(ps[i] - point(0, -w), i);
  }
  sort(tosort, tosort + n, cmp0);
  for (int i = 0; i < n; i++) {
    a[i] = tosort[i].second;
  }
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(ps[i] - point(0, w), i);
  }
  sort(tosort, tosort + n, cmp1);
  for (int i = 0; i < n; i++) {
    b[i] = tosort[i].second;
  }
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    res += get(pos[b[i]]);
    add(pos[b[i]], 1);
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