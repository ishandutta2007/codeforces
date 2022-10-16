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

long long x, y, s;
vector<int> xs, ys, ss;

int read() {
  xs.resize(3);
  ys.resize(3);
  ss.resize(3);
  x = 1;
  y = 1;
  s = 1;
  for (int i = 0; i < 3; i++) {
    if (scanf("%d", &ys[i]) < 1) {
      return false;
    }
    y *= ys[i];
  }
  for (int i = 0; i < 3; i++) {
    if (scanf("%d", &xs[i]) < 1) {
      return false;
    }
    x *= xs[i];
  }
  for (int i = 0; i < 3; i++) {
    if (scanf("%d", &ss[i]) < 1) {
      return false;
    }
    s *= ss[i];
  }
  ss[0] *= 2;
  s *= 2;
  return true;
}

map<int, int> mpy, mps;

void fact(const vector<int> &v, map<int, int> &mp) {
  mp.clear();
  for (int it = 0; it < sz(v); it++) {
    int x = v[it];
    for (int d = 2; d * d <= x; d++) {
      while (!(x % d)) {
        mp[d]++;
        x /= d;
      }
    }
    if (x > 1) {
      mp[x]++;
    }
  }
}

vector< pair<int, int> > fs;

int genDiv(int pos, long long cur) {
  if (pos == sz(fs)) {
    return 1;
  }
  int res = 0;
  long long p = 1;
  for (int i = 0; i <= fs[pos].second; i++, p *= fs[pos].first) {
    if (cur * p <= y) {
      res += genDiv(pos + 1, cur * p);
    }
  }
  return res;
}

long long myPow(int x, int p) {
  long long res = 1;
  for (int i = 0; i < p; i++) {
    res *= x;
  }
  return res;
}

void solve() {
  fact(ys, mpy);
  fact(ss, mps);
  vector<long long> ps;
  for (auto it = mpy.begin(); it != mpy.end(); it++) {
    int p = it->first;
    int a = (mps.count(p) ? mps[p] : 0);
    if (a < it->second) {
      ps.push_back(myPow(p, a + 1));
    }
  }
  long long res = 0;
  for (int msk = 0; msk < (1 << sz(ps)); msk++) {
    long long cur = 1;
    int sgn = 1;
    for (int i = 0; i < sz(ps); i++) {
      if (!(msk & (1 << i))) {
        continue;
      }
      sgn = -sgn;
      if ((ld) cur * ps[i] > infll) {
        cur = infll;
      } else {
        cur *= ps[i];
      }
    }
    res += (x / cur) * sgn;
  }
  fs.clear();
  for (auto it = mps.begin(); it != mps.end(); it++) {
    fs.push_back(*it);
  }
  res += genDiv(0, 1);
  printf("%lld\n", res);
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