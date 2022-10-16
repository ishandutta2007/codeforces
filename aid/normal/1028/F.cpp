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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
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

  void norm() {
    int g = gcd(x, y);
    x /= g;
    y /= g;
  }

  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }

  bool operator == (const point &p) const {
    return x == p.x && y == p.y;
  }
};

const int maxn = (int) 2e5 + 5;
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int k;
map<long long, int> ids;
vector<point> vs[maxn];
vector<int> dels[maxn];
map<point, int> ans;

int getId(long long x) {
  auto it = ids.find(x);
  if (it == ids.end()) {
    int id = sz(ids);
    ids[x] = id;
    vs[id].clear();
    dels[id].clear();
    return id;
  }
  return it->second;
}

void add(const point &p) {
  int id = getId(p.slen());
  auto &v = vs[id];
  auto &del = dels[id];
  for (int i = 0; i < sz(v); i++) {
    if (del[i]) {
      continue;
    }
    point cur = p + v[i];
    cur.norm();
    ans[cur] += 2;
  }
  {
    point cur = p;
    cur.norm();
    ans[cur]++;
  }
  v.push_back(p);
  del.push_back(false);
  k++;
}

void del(const point &p) {
  int id = getId(p.slen());
  auto &v = vs[id];
  auto &del = dels[id];
  for (int i = 0; i < sz(v); i++) {
    if (del[i]) {
      continue;
    }
    if (v[i] == p) {
      del[i] = true;
      continue;
    }
    point cur = p + v[i];
    cur.norm();
    ans[cur] -= 2;
  }
  {
    point cur = p;
    cur.norm();
    ans[cur]--;
  }
  k--;
}

void solve() {
  ids.clear();
  k = 0;
  for (int it = 0; it < n; it++) {
    int t;
    scanf("%d", &t);
    point p;
    p.read();
    if (t == 1) {
      add(p);
    } else if (t == 2) {
      del(p);
    } else {
      p.norm();
      int res = k;
      auto it = ans.find(p);
      if (it != ans.end()) {
        res -= it->second;
      }
      printf("%d\n", res);
    }
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