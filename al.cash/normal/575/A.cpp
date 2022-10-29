#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
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

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}

template<class T>
class SegmentTree {
 public:
  int n;
  vector<T> t;

  SegmentTree(int n_ = 0) { init(n_); }
  void init(int n_) { n = n_; vector<T>(2*n).swap(t); }

  T& operator [] (int p) { return t[p + n]; }
  const T& operator [] (int p) const { return t[p + n]; }

  void build() {
    for (int i = n - 1; i; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void set(int p, const T& value) {
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  T query(int l, int r) const {  // [l, r)
    T resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

int mod;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

template<class T> T qpow(T a, ll p) {
  T res = 1;
  for (; p; p >>= 1, a = combine(a, a))
    if (p & 1) res = combine(res, a);
  return res;
}

const int h = 2;
struct Mat {
  int m[h][h];
  Mat(int v = 1) { REP(i, h) REP(j, h) m[i][j] = i == j ? v : 0; }

  friend Mat combine(const Mat& a, const Mat& b) {
    Mat c(0);
    REP(i, h) REP(j, h) REP(k, h) inc(c.m[i][j], mul(b.m[i][k], a.m[k][j]));
    return c;
  }

  void apply(int v[h]) {
    int r[h] = {0};
    REP(i, h) REP(j, h) inc(r[i], mul(m[i][j], v[j]));
    REP(i, h) v[i] = r[i];
  }

  void outp() {
    REP(i, h) print("%d", m[i], m[i]+h);
    printf("\n");
  }
};

const int N = 5e4+4;
ll k;
int n, m;
int s[N];
pair<ll, int> d[N];
int f[2] = {1, 0};
ll c;

SegmentTree<Mat> tree;

void upd(int fn) {
  f[1] = f[0];
  f[0] = fn;
  ++c;
//  printf("%lld: %d %d (by upd)\n", c, f[0], f[1]);
  if (c == k) {
    printf("%d\n", fn);
    exit(0);
  }
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%I64d%d%d", &k, &mod, &n);
  if (k == 0 || mod == 1) {
    printf("0\n");
    return 0;
  }
  REP(i, n) scanf("%d", s+i), s[i] %= mod;
  s[n] = s[0];
  tree.init(n);
  REP(i, n) {
    tree[i].m[0][0] = s[i+1];
    tree[i].m[0][1] = s[i];
    tree[i].m[1][0] = 1;
    tree[i].m[1][1] = 0;
  }
  tree.build();
  Mat a = tree.query(0, n);
//  a.outp();

  scanf("%d", &m);
  REP(i, m) scanf("%I64d%d", &d[i].X, &d[i].Y), d[i].Y %= mod;
  sort(d, d+m);

//  FOR(i, n, k) s[i] = s[i%n];
//  REP(i, m) s[d[i].X] = d[i].Y;
//  c = 1;
//  FOR(i, 2, k+1) upd(add(mul(s[i-1], f[0]), mul(s[i-2], f[1])));
//  return 0;

  c = min((ll)n, k);
  Mat t = tree.query(0, (int)c-1);
//  t.outp();
  t.apply(f);
//  printf("%lld: %d %d\n", c, f[0], f[1]);
  if (c != k) REP(i, m+1) {
    if (i != 0 && i != m && d[i-1].X + 1 == d[i].X) {
      upd(add(mul(d[i].Y, f[0]), mul(d[i-1].Y, f[1])));
    } else {
      ll p = c;
      c = k;
      if (i != m) smin(c, d[i].X);
      if (p != c) {
        ll pow = (c-1) / n - (p-1) / n - 1;
        if (pow == -1) {
          t = tree.query((p-1)%n, (c-1)%n);
          t.apply(f);
        } else {
          t = tree.query((p-1)%n, n);
          t.apply(f);
          t = qpow(a, pow);
          t.apply(f);
          t = tree.query(0, (c-1)%n);
          t.apply(f);
        }
//        printf("%lld: %d %d\n", c, f[0], f[1]);
        if (c == k) break;
      }
      upd(add(mul(d[i].Y, f[0]), mul(s[(c-1)%n], f[1])));
    }

    if (i+1 == m || d[i].X + 1 != d[i+1].X)
      upd(add(mul(s[c%n], f[0]), mul(d[i].Y, f[1])));
  }
  printf("%d\n", f[0]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}