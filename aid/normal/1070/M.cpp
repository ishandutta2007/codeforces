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
  int id, deg;

  point(): x(0), y(0) {}

  point(int _x, int _y): x(_x), y(_y), id(-1), deg(-1) {}

  bool read() {
    return scanf("%d%d", &x, &y) == 2;
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  int operator ^ (const point &p) const {
    return x * p.y - y * p.x;
  }
};

bool operator < (const point &a, const point &b) {
  return (a ^ b) > 0;
}

vector<point> ps;

int read() {
  int a, b;
  if (scanf("%d%d", &a, &b) < 2) {
    return false;
  }
  vector<int> rs(b);
  for (int i = 0; i < b; i++) {
    scanf("%d", &rs[i]);
  }
  ps.clear();
  ps.resize(a + b);
  for (int i = 0; i < a + b; i++) {
    ps[i].read();
    if (i < a) {
      ps[i].id = i;
      ps[i].deg = -1;
    } else {
      ps[i].id = i - a;
      ps[i].deg = rs[i - a] - 1;
    }
  }
  return true;
}

vector<pair<int, int>> es;

void solve(vector<point> ps) {
  int n = sz(ps);
  if (n <= 1) {
    return;
  }
  for (int i = 1; i < n; i++) {
    if (ps[i].x < ps[0].x || (ps[i].x == ps[0].x && ps[i].y < ps[0].y)) {
      swap(ps[0], ps[i]);
    }
  }
  for (int i = 1; i < n; i++) {
    ps[i].x -= ps[0].x;
    ps[i].y -= ps[0].y;
  }
  sort(ps.begin() + 1, ps.end());
  for (int i = 1; i < n; i++) {
    ps[i].x += ps[0].x;
    ps[i].y += ps[0].y;
  }
  if (ps[0].deg < 0) {
    for (int i = 1; i < n;) {
      int bal = 0;
      int j = i;
      while (true) {
        assert(i < n);
        bal += ps[i].deg;
        if (bal >= 0) {
          break;
        }
        i++;
      }
      es.push_back(make_pair(ps[i].id, ps[0].id));
      ps[i].deg--;
      {
        ps[i].deg -= bal;
        vector<point> qs;
        for (int k = j; k <= i; k++) {
          qs.push_back(ps[k]);
        }
        solve(qs);
        ps[i].deg = bal - 1;
      }
      j = i;
      i++;
      while (bal > 0) {
        assert(i < n);
        bal += ps[i].deg;
        i++;
      }
      assert(!bal);
      {
        vector<point> qs;
        for (int k = j; k < i; k++) {
          qs.push_back(ps[k]);
        }
        solve(qs);
      }
    }
  } else {
    int i;
    for (i = 1; i < n && ps[0].deg >= 0;) {
      int bal = 1;
      int j = i;
      while (bal > 0) {
        assert(i < n);
        bal += ps[i].deg;
        i++;
      }
      assert(!bal);
      es.push_back(make_pair(ps[0].id, ps[i - 1].id));
      ps[0].deg--;
      {
        vector<point> qs;
        for (int k = j; k < i; k++) {
          qs.push_back(ps[k]);
        }
        solve(qs);
      }
    }
    {
      vector<point> qs;
      for (int j = i - 1; j < n; j++) {
        qs.push_back(ps[j]);
      }
      solve(qs);
    }
  }
}

void solve() {
  es.clear();
  solve(ps);
  printf("YES\n");
  for (int i = 0; i < sz(es); i++) {
    printf("%d %d\n", es[i].first + 1, es[i].second + 1);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}