#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

template <typename Iterator>
void print(const char* fmt, Iterator first, Iterator last,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; first != last; ++first != last ? printf("%s", delimiter) : 0)
    printf(fmt, *first);
  printf("%s", closing);
}

template <class T, class M = T>
class SegmentTreeR {
  int n, height;
  vector<T> tree;
  vector<M> delta;

  void apply(int i, const M& value, int k) {
    tree[i].add(value, k);
    if (i < n) delta[i].add(value);
  }

public:
  SegmentTreeR(int newn = 0) { init(newn); }

  void init(int newn) {
    n = newn;
    height = sizeof(n) * 8 - __builtin_clz(n);
    vector<T>(2*n).swap(tree);
    vector<M>(n, M(false)).swap(delta);
  }

  int size() const { return n; }
  T& operator [] (int i) { return tree[i + n]; }
  const T& operator [] (int i) const { return tree[i + n]; }

  void push(int l, int r) {
    int h = height, k = 1 << (h-1);
    for (l += n, r += n-1; h; --h, k >>= 1)
      for (int i = l >> h; i <= r >> h; ++i) if (delta[i]) {
        apply(i<<1, delta[i], k);
        apply(i<<1|1, delta[i], k);
        delta[i] = M(false);
      }
  }
  void push() { push(0, n); }

  void modify(int l, int r, const M& value) {
    if (!value) return;
    push(l, l + 1);
    push(r - 1, r);
    int k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (l&1) apply(l++, value, k);
      if (r&1) apply(--r, value, k);
    }
  }
};

struct P {
  double x[2];
  P() { x[0] = x[1] = 0.0; }
  void outp() { printf("%.9lf %.9lf\n", x[0], x[1]); }
  double abs() { return sqrt(sqr(x[0]) + sqr(x[1])); }
  void operator *= (double c) { REP(i, 2) x[i] *= c; }
};

struct Mat {
  double m[2][2];
  Mat(double d = 0.0) {
    REP(i, 2) REP(j, 2) m[i][j] = i == j ? d : 0.0;
  }
  void outp() { REP(i, 2) { REP(j, 2) printf("%.6lf ", m[i][j]); printf("\n"); } }
};

P operator + (const P& a, const P& b) {
  P res;
  REP(i, 2) res.x[i] = a.x[i] + b.x[i];
  return res;
}

P operator - (const P& a, const P& b) {
  P res;
  REP(i, 2) res.x[i] = a.x[i] - b.x[i];
  return res;
}

P operator * (const Mat& R, const P& p) {
  P res;
  REP(i, 2) REP(j, 2) res.x[i] += R.m[i][j] * p.x[j];
  return res;
}

Mat operator * (const Mat& A, const Mat& B) {
  Mat res;
  REP(i, 2) REP(j, 2) REP(k, 2) {
    res.m[i][j] += A.m[i][k] * B.m[k][j];
  }
  return res;
}

struct M {
  Mat R;
  P t;

  explicit M(bool) : R(1) {}
  explicit operator bool () const { return true; }

  void add(const M& other) {
    R = other.R * R;
    t = other.R * t + other.t;
  }
};

struct F {
  P p;

  void add(const M& delta, int k = 1) {
    p = delta.R * p + delta.t;
  }
};

const int N = 3e5+5;
int n, m;
SegmentTreeR<F, M> tree;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  tree.init(n + 1);
  REP(i, n+1) {
    tree[i].p.x[0] = i;
    tree[i].p.x[1] = 0;
  }
  REP(q, m) {
    int t, i, l;
    scanf("%d%d%d", &t, &i, &l);
    --i;
    tree.push(i, min(i + 2, n + 1));
    M rt(false);
    if (t == 1) {
      P v = tree[i+1].p - tree[i].p;
      v *= 1 / v.abs();
      v *= l;
      rt.t = v;
    } else {
      double sn = sin(l * pi / 180);
      double cs = cos(l * pi / 180);
      rt.R.m[0][0] = cs;
      rt.R.m[0][1] = sn;
      rt.R.m[1][0] = -sn;
      rt.R.m[1][1] = cs;
      P t1 = rt.R * tree[i].p;
      rt.t = tree[i].p - t1;
    }
//    printf("%d: %d..\n", q, i + 1);
//    rt.R.outp();
//    rt.t.outp();
    tree.modify(i + 1, n + 1, rt);
    tree.push(n, n + 1);
    tree[n].p.outp();
  }

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}