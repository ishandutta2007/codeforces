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
const ld eps = 1e-12;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
long long t;
int a[maxn], b[maxn];
ld p[maxn];

int read() {
  if (scanf("%d%lld", &n, &t) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    double pp;
    scanf("%d%d%lf", &a[i], &b[i], &pp);
    p[i] = pp;
  }
  return true;
}

struct Mat {
  static const int n = 3;
  ld a[n][n];

  Mat() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
  }

  void mul(ld v[n], ld res[n]) {
    for (int i = 0; i < n; i++) {
      res[i] = 0;
      for (int j = 0; j < n; j++) {
        res[i] += a[i][j] * v[j];
      }
    }
  }

  Mat operator * (const Mat &b) const {
    Mat res;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res.a[i][j] = 0;
        for (int k = 0; k < n; k++) {
          res.a[i][j] += a[i][k] * b.a[k][j];
        }
      }
    }
    return res;
  }
};

ld best;

struct line {
  ld a, b;

  line() {}
  
  line(ld _a, ld _b): a(_a), b(_b) {}

  bool operator < (const line &l) const {
    return a < l.a - eps || (a < l.a + eps && b < l.b - eps);
  }

  ld eval(ld x) {
    return a * x + b;
  }
};

bool bad(const line &l0, const line &l1, const line &l2) {
  return (l0.b - l1.b) / (l1.a - l0.a) > (l1.b - l2.b) / (l2.a - l1.a) - eps;
}

vector<line> st;

void solve() {
  best = 0;
  for (int i = 0; i < n; i++) {
    best = max(best, b[i] * p[i]);
  }
  st.clear();
  for (int i = 0; i < n; i++) {
    st.push_back(line(p[i], p[i] * a[i]));
  }
  sort(st.begin(), st.end());
  {
    int k = 0;
    for (int i = 0; i < sz(st); i++) {
      while (k >= 1 && abs(st[k - 1].a - st[i].a) < eps) {
        k--;
      }
      while (k >= 2 && bad(st[k - 2], st[k - 1], st[i])) {
        k--;
      }
      st[k++] = st[i];
    }
    st.resize(k);
  }
  long long curt = 0;
  ld dp = 0;
  for (int i = 0; i < sz(st) && curt < t; i++) {
    ld x = best * curt - dp;
    if (i + 1 < sz(st) && st[i + 1].eval(x) > st[i].eval(x) - eps) {
      continue;
    }
    vector<Mat> as;
    as.push_back(Mat());
    as[0].a[0][0] = 1 - st[i].a;
    as[0].a[0][1] = st[i].a * best;
    as[0].a[0][2] = st[i].b;
    as[0].a[1][1] = 1;
    as[0].a[1][2] = 1;
    as[0].a[2][2] = 1;
    ld v0[3] = {dp, (ld) curt, (ld) 1};
    ld v[3];
    while (true) {
      if (curt + (1ll << (sz(as) - 1)) > t) {
        as.pop_back();
        break;
      }
      as.back().mul(v0, v);
      ld nx = best * v[1] - v[0];
      if (i + 1 < sz(st) && st[i + 1].eval(nx) > st[i].eval(nx) - eps) {
        as.pop_back();
        break;
      }
      Mat nxt = as.back() * as.back();
      as.push_back(nxt);
    }
    while (!as.empty()) {
      if (curt + (1ll << (sz(as) - 1)) > t) {
        as.pop_back();
        continue;
      }
      as.back().mul(v0, v);
      ld nx = best * v[1] - v[0];
      if (i + 1 < sz(st) && st[i + 1].eval(nx) > st[i].eval(nx) - eps) {
        as.pop_back();
        continue;
      }
      curt += (1ll << (sz(as) - 1));
      for (int j = 0; j < 3; j++) {
        v0[j] = v[j];
      }
      dp = v0[0];
      as.pop_back();
    }
    if (curt >= t) {
      break;
    }
    as.push_back(Mat());
    as[0].a[0][0] = 1 - st[i].a;
    as[0].a[0][1] = st[i].a * best;
    as[0].a[0][2] = st[i].b;
    as[0].a[1][1] = 1;
    as[0].a[1][2] = 1;
    as[0].a[2][2] = 1;
    as[0].mul(v0, v);
    curt++;
    dp = v[0];
  }
  printf("%.12f\n", (double) dp);
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