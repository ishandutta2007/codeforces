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

  point(int _x, int _y): x(_x), y(_y) {}

  bool read() {
    return scanf("%d%d", &x, &y) == 2;
  }

  void print() {
    printf("%d %d\n", x, y);
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
    return x < 0 || (x == 0 && y > 0);
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  return (a ^ b) > 0;
}

bool cmp(const point &a, const point &b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.y > b.y;
}

const int maxn = 2005;
int n;
long long s;
point ps[maxn];

bool read() {
  if (scanf("%d%lld", &n, &s) < 2) {
    return false;
  }
  s *= 2;
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

point ps0[maxn];
vector<pair<pair<point, long long>, pair<int, int>>> ls;

int get(const point &dir, long long x) {
  int l = 0, r = n;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if ((dir ^ ps[m]) > x) {
      r = m;
    } else {
      l = m;
    }
  }
  if ((dir ^ ps[l]) != x) {
    return -1;
  }
  return l;
}

void solve() {
  for (int i = 0; i < n; i++) {
    ps0[i] = ps[i];
  }
  ls.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) {
        continue;
      }
      ls.push_back(make_pair(make_pair(ps[j] - ps[i], s + ((ps[j] - ps[i]) ^ ps[i])), make_pair(i, j)));
    }
  }
  sort(ls.begin(), ls.end());
  sort(ps, ps + n, cmp);
  for (int i = 0; i < sz(ls); i++) {
    point dir = ls[i].first.first;
    long long need = ls[i].first.second;
    int v = ls[i].second.first, u = ls[i].second.second;
    int p = get(dir, need);
    if (p != -1) {
      printf("Yes\n");
      ps0[v].print();
      ps0[u].print();
      ps[p].print();
      return;
    }
    p = get(dir, need - s);
    swap(ps[p - 1], ps[p]);
  }
  printf("No\n");
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