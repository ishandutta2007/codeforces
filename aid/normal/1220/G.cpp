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
  long long x, y;

  point(): x(0), y(0) {}

  point(long long xx, long long yy): x(xx), y(yy) {}

  bool read() {
    return scanf("%lld%lld", &x, &y) == 2;
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  point operator * (long long k) const {
    return point(x * k, y * k);
  }

  point operator / (long long k) const {
    return point(x / k, y / k);
  }

  __int128 operator ^ (const point &p) const {
    return (__int128) x * p.y - (__int128) y * p.x;
  }

  __int128 operator * (const point &p) const {
    return (__int128) x * p.x + (__int128) y * p.y;
  }

  __int128 slen() const {
    return *this * *this;
  }

  bool operator == (const point &p) const {
    return x == p.x && y == p.y;
  }

  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

void intersect(point p0, __int128 rr0, point p1, __int128 rr1, vector<point> &ans) {
  if (rr0 < rr1) {
    swap(p0, p1);
    swap(rr0, rr1);
  }
  __int128 dd = (p1 - p0).slen();
  ld r0 = sqrt((ld) rr0), r1 = sqrt((ld) rr1);
  ld d = sqrt((ld) dd);
  if (r0 + r1 < d - eps) {
    return;
  }
  if (r1 + d < r0 - eps) {
    return;
  }
  ld cosa = (rr0 + dd - rr1) / (2 * r0 * d);
  ld sina = sqrt(max((ld) 0, 1 - cosa * cosa));
  ld vx = (p1 - p0).x / d * r0;
  ld vy = (p1 - p0).y / d * r0;
  ld ux = -vy, uy = vx;
  vx *= cosa;
  vy *= cosa;
  ux *= sina;
  uy *= sina;
  for (int dir = -1; dir <= 1; dir += 2) {
    ld x = p0.x + vx + dir * ux;
    ld y = p0.y + vy + dir * uy;
    point cur((long long) round(x), (long long) round(y));
    if ((cur - p0).slen() == rr0 && (cur - p1).slen() == rr1) {
      ans.push_back(cur);
    }
  }
}

const int maxn = (int) 1e5 + 5;
int n;
point ps[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
    ps[i] = ps[i] * n;
  }
  return true;
}

point c;
__int128 s;
__int128 d[maxn];
map<__int128, int> cnt, cnt1;
vector<point> ans;

bool check(const point &p) {
  if (p.x % n || p.y % n) {
    return false;
  }
  cnt1.clear();
  for (int i = 0; i < n; i++) {
    __int128 dd = (ps[i] - p).slen();
    auto &cur = cnt1[dd];
    cur++;
    if (cur > cnt[dd]) {
      return false;
    }
  }
  return true;
}

void solve1() {
  __int128 dc = 0;
  cnt.clear();
  for (int i = 0; i < n; i++) {
    long long dd;
    scanf("%lld", &dd);
    d[i] = dd;
    d[i] *= (__int128) n * n;
    dc += d[i];
    cnt[d[i]]++;
  }
  dc /= n;
  dc -= s;
  dc += c.slen();
  ans.clear();
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    intersect(ps[0], it->first, c, dc, ans);
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  int k = 0;
  for (int i = 0; i < sz(ans); i++) {
    if (check(ans[i])) {
      ans[k++] = ans[i] / n;
    }
  }
  ans.resize(k);
  printf("%d ", k);
  for (int i = 0; i < k; i++) {
    printf("%lld %lld ", ans[i].x, ans[i].y);
  }
  printf("\n");
}

void solve() {
  shuffle(ps, ps + n, mrand);
  c = point();
  s = 0;
  for (int i = 0; i < n; i++) {
    c = c + ps[i];
    s += ps[i].slen();
  }
  c = c / n;
  s /= n;
  if (ps[0] == c) {
    swap(ps[0], ps[1]);
  }
  assert(!(ps[0] == c));
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    solve1();
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