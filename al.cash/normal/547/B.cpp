#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
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

template<class T, bool commutative = true>
class SegmentTree {
 public:
  void init(int n_, const T& v = T()) { n = n_; t = vector<T>(2*n, v); }

  T& operator [] (int p) { return t[p + n]; }
  const T& operator [] (int p) const { return t[p + n]; }

  void build() {
    for (int i = n-1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void set(int p, const T& value) {
    for (t[p += n] = value; p > 1; )
      if (commutative) t[p>>1] = combine(t[p], t[p^1]), p >>= 1;
      else p >>= 1, t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  void add(int p, const T& delta) {  // Use only when applicable.
    for (p += n; p > 0; p >>= 1) t[p].add(delta);
  }

  T query(int l, int r) const {  // [l, r)
    T resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
      if (commutative) {
        if (l&1) resl.add(t[l++]);
        if (r&1) resr.add(t[--r]);
      } else {
        if (l&1) resl = combine(resl, t[l++]);
        if (r&1) resr = combine(t[--r], resr);
      }
    return combine(resl, resr);
  }

 private:
  int n;
  vector<T> t;
};

struct S {
  int s, l, r, m;
  S(int s = 0, int l = 0, int r = 0, int m = 0) : s(s), l(l), r(r), m(m) {}
  void add(const S& b);
  friend S combine(const S& a, const S& b) {
    S res;
    res.s = a.s + b.s;
    res.l = a.l == a.s ? a.s + b.l : a.l;
    res.r = b.r == b.s ? b.s + a.r : b.r;
    res.m = max(max(a.m, b.m), a.r + b.l);
    return res;
  }
};

SegmentTree<S, false> t;

const int N = 200002;
int n;
pii a[N];
int ans[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i].X), a[i].Y = i;
  sort(a, a+n);
  t.init(n, S(1, 1, 1, 1));
  t.build();
//  REP(i, n) printf("%d %d %d %d\n", t.t[i].s, t.t[i].l, t.t[i].r, t.t[i].m);
  int m = n;
  REP(i, n) {
    int cur = t.query(0, n).m;
//    printf("%d: %d(%d), %d\n", i, a[i].X, a[i].Y, cur);
    while (m > cur) ans[--m] = a[i-1].X;
    t.set(a[i].Y, S(1, 0, 0, 0));
  }
  ans[0] = a[n-1].X;

  print("%d", ans, ans + n);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}