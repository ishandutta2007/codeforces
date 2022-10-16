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

  point operator * (int k) const {
    return point(x * k, y * k);
  }

  long long operator ^ (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }

  int type() const {
    return x > 0 || (x == 0 && y > 0);
  }
};

bool operator < (const point &a, const point &b) {
  return (a ^ b) > 0;
}

const int maxk = 11, maxn = (int) 1e5 + 5;
int k, n, q;
point vs[maxk];
point fs[maxn];
int as[maxn];
point ps[maxn];
int t[maxn];

bool read() {
  if (scanf("%d%d%d", &k, &n, &q) < 3) {
    return false;
  }
  for (int i = 0; i < k; i++) {
    vs[i].read();
  }
  for (int i = 0; i < n; i++) {
    fs[i].read();
    scanf("%d", &as[i]);
  }
  for (int i = 0; i < q; i++) {
    ps[i].read();
    scanf("%d", &t[i]);
  }
  return true;
}

long long ans[maxn];

vector<pair<long long, int>> evs1;

void solve1(const point &a, const point &b, int sgn) {
  point dir = (b - a);
  evs1.clear();
  for (int i = 0; i < q; i++) {
    point aa = ps[i] + a * t[i];
    long long x = (dir ^ aa);
    evs1.push_back(make_pair(x, -i));
  }
  for (int i = 0; i < n; i++) {
    long long x = (dir ^ fs[i]);
    evs1.push_back(make_pair(x, as[i]));
  }
  sort(evs1.begin(), evs1.end());
  long long s = 0;
  for (int i = 0; i < sz(evs1); i++) {
    if (evs1[i].second <= 0) {
      int id = -evs1[i].second;
      ans[id] += s * sgn;
    } else {
      s += evs1[i].second;
    }
  }
}

vector<long long> ys;
vector<long long> fen;

void add(int i, int x) {
  for (; i < sz(fen); i |= i + 1) {
    fen[i] += x;
  }
}

long long get(int i) {
  long long res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

vector<pair<long long, pair<int, int>>> evs2;

void solve2(const point &a, const point &b, const point &c, const point &d, int sgn) {
  point dirx = (b - a), diry = (d - c);
  ys.clear();
  for (int i = 0; i < q; i++) {
    point cc = ps[i] + c * t[i];
    long long y = (diry ^ cc);
    ys.push_back(y);
  }
  for (int i = 0; i < n; i++) {
    long long y = (diry ^ fs[i]);
    ys.push_back(y);
  }
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  fen.clear();
  fen.resize(sz(ys));
  evs2.clear();
  for (int i = 0; i < q; i++) {
    point aa = ps[i] + a * t[i];
    long long x = (dirx ^ aa);
    point cc = ps[i] + c * t[i];
    long long yy = (diry ^ cc);
    int y = lower_bound(ys.begin(), ys.end(), yy) - ys.begin();
    evs2.push_back(make_pair(x, make_pair(-i, y)));
  }
  for (int i = 0; i < n; i++) {
    long long x = (dirx ^ fs[i]);
    long long yy = (diry ^ fs[i]);
    int y = lower_bound(ys.begin(), ys.end(), yy) - ys.begin();
    evs2.push_back(make_pair(x, make_pair(as[i], y)));
  }
  sort(evs2.begin(), evs2.end());
  for (int i = 0; i < sz(evs2); i++) {
    int y = evs2[i].second.second;
    if (evs2[i].second.first <= 0) {
      int id = -evs2[i].second.first;
      ans[id] += get(y - 1) * sgn;
    } else {
      add(y, evs2[i].second.first);
    }
  }
}

vector<point> pol;

void solve() {
  {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += as[i];
    }
    for (int i = 0; i < q; i++) {
      ans[i] = cnt;
    }
  }
  {
    point s;
    for (int i = 0; i < k; i++) {
      if (!vs[i].type()) {
        vs[i] = vs[i] * -1;
      }
      s = s - vs[i];
    }
    sort(vs, vs + k);
    pol.clear();
    pol.push_back(s);
    for (int i = 0; i < k; i++) {
      s = s + vs[i] * 2;
      pol.push_back(s);
    }
    for (int i = 0; i < k; i++) {
      s = s - vs[i] * 2;
      pol.push_back(s);
    }
  }
  for (int i = 0; i + 1 < sz(pol); i++) {
    solve1(pol[i], pol[i + 1], -1);
    if (!i) {
      continue;
    }
    solve2(pol[i - 1], pol[i], pol[i], pol[i + 1], 1);
    if (((pol[i + 1] - pol[i]) ^ (pol[1] - pol[0])) <= 0) {
      continue;
    }
    solve2(pol[i], pol[i + 1], pol[0], pol[1], 1);
    if (((pol[i] - pol[i - 1]) ^ (pol[1] - pol[0])) <= 0) {
      continue;
    }
    solve2(pol[i - 1], pol[i], pol[0], pol[1], -1);
  }
  for (int i = 0; i < q; i++) {
    printf("%lld\n", ans[i]);
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