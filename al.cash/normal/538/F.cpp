#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
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
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T gcd(T a, T b) {
  if (a < 0) a = -a; if (b < 0) b = -b;
  while (a && b) { if (a >= b) a %= b; else b %= a; } return a + b; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator> void print(const char* fmt,
    Iterator begin, Iterator end, const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf("%s", separator);
    printf(fmt, *it);
  }
  printf("\n");
}

template<class T, bool commutative = true>
class SegmentTree {
 public:
  void init(int n_, const T& v = T()) { n = n_; t = vector<T>(2*n, v); }

  T& operator [] (int p) { return t[p + n]; }
  const T& operator [] (int p) const { return t[p + n]; }

  void build() {
    for (int i = n-1; i > 0; --i) t[i] = sum(t[i<<1], t[i<<1|1]);
  }

  void set(int p, const T& value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = sum(t[p], t[p^1]);
  }

  void inc(int p, const T& delta) {  // Use only when applicable.
    for (p += n; p > 0; p >>= 1) t[p].inc(delta);
  }

  T query(int l, int r) const {  // [l, r)
    T resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
      if (commutative) {
        if (l&1) resl.inc(t[l++]);
        if (r&1) resr.inc(t[--r]);
      } else {
        if (l&1) resl = sum(resl, t[l++]);
        if (r&1) resr = sum(t[--r], resr);
      }
    return sum(resl, resr);
  }

 private:
  int n;
  vector<T> t;
};

struct V {
  int v;
  V(int v = 0) : v(v) {}  // Insert proper 0 value here.
  void inc(const V& b) { v += b.v; }
  friend V sum(const V& a, const V& b) { return a.v + b.v; }
};



const int N = 200022;
int n, a[N];
pii p[N];
SegmentTree<V, true> t;
int ans[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) p[i] = pii(a[i], i);
  sort(p, p+n);
  t.init(n, 0);
  REP(u, n) {
    int v = u;
    while (v < n && p[v].X == p[u].X) ++v;
    FOR(j, u, v) {
      int i = p[j].Y;
      for (int k = 1; k < n && k*i+1 < n; ++k)
        ans[k-1] += t.query(k*i+1, min(k*i+k+1, n)).v;
    }
    FOR(j, u, v) t.inc(p[j].Y, 1);
    u = v - 1;
  }
  print("%d", ans, ans+n-1);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}