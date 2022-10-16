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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
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

  long long operator * (const point &p) const {
    return (long long) x * p.x + (long long) y * p.y;
  }

  long long slen() const {
    return *this * *this;
  }

  ld len() const {
    return sqrt(slen());
  }

  pair<point, int> norm() const {
    if (x == 0 && y == 0) {
      return make_pair(*this, 1);
    }
    int g = gcd(abs(x), abs(y));
    return make_pair(point(x / g, y / g), g);
  }

  bool operator == (const point &p) const {
    return x == p.x && y == p.y;
  }
};

bool operator < (const point &a, const point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const int maxn = (int) 5e5 + 5;
int n, k;
point ps[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

vector<point> dirs;
vector<vector<int>> qs;
vector<int> taken;
priority_queue<pair<ld, int>> pq;

void add(int i) {
  if (taken[i] >= sz(qs[i])) {
    return;
  }
  int c = k - 1 - 2 * taken[i];
  if (c < 0) {
    return;
  }
  ld d = dirs[i].len() * qs[i][taken[i]];
  pq.push(make_pair(c * d, i));
}

void solve() {
  dirs.clear();
  for (int i = 0; i < n; i++) {
    if (ps[i] == point()) {
      continue;
    }
    dirs.push_back(ps[i].norm().first);
  }
  sort(dirs.begin(), dirs.end());
  dirs.erase(unique(dirs.begin(), dirs.end()), dirs.end());
  qs.clear();
  qs.resize(sz(dirs));
  for (int i = 0; i < n; i++) {
    if (ps[i] == point()) {
      continue;
    }
    auto p = ps[i].norm();
    point dir = p.first;
    int k = p.second;
    int pos = lower_bound(dirs.begin(), dirs.end(), dir) - dirs.begin();
    qs[pos].push_back(k);
  }
  taken.resize(sz(dirs));
  while (!pq.empty()) {
    pq.pop();
  }
  for (int i = 0; i < sz(dirs); i++) {
    sort(qs[i].begin(), qs[i].end(), greater<int>());
    taken[i] = 0;
    add(i);
  }
  int need = k;
  ld res = 0;
  while (need && !pq.empty()) {
    res += pq.top().first;
    int i = pq.top().second;
    pq.pop();
    taken[i]++;
    need--;
    add(i);
  }
  if (need) {
    need--;
  }
  if (need) {
    for (int i = 0; i < sz(dirs); i++) {
      int cc = k - 1 - 2 * taken[i];
      if (cc < 0) {
        for (int j = sz(qs[i]) - need; j < sz(qs[i]); j++) {
          int c = k - 1 - 2 * taken[i];
          ld d = dirs[i].len() * qs[i][j];
          res += c * d;
          taken[i]++;
        }
        break;
      }
    }
  }
  printf("%.12f\n", (double) res);
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