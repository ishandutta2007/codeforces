#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
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

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

template <class T, bool COMMUTATIVE = true>
class SegmentTree {
  int n;
  vector<T> tree;

public:
  SegmentTree(int newn = 0) { init(newn); }
  void init(int newn) { n = newn; vector<T>(2*n).swap(tree); }

  int size() const { return n; }
  T& operator [] (int i) { return tree[i + n]; }
  const T& operator [] (int i) const { return tree[i + n]; }

  void build() {
    for (int i = n; --i; ) tree[i] = combine(tree[i<<1], tree[i<<1|1]);
  }

  void set(int i, const T& value) {
    for (tree[i += n] = value; i >>= 1; )
      tree[i] = combine(tree[i<<1], tree[i<<1|1]);
  }

  void add(int i, const T& delta) {
    assert(COMMUTATIVE);
    for (i += n; i; i >>= 1) tree[i].add(delta);
  }

  T query(int l, int r) const {  // [l, r)
    T resl = T(), resr = T();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
      if (COMMUTATIVE) {
        if (l&1) resl.add(tree[l++]);
        if (r&1) resr.add(tree[--r]);
      } else {
        if (l&1) resl = combine(resl, tree[l++]);
        if (r&1) resr = combine(tree[--r], resr);
      }
    return combine(resl, resr);
  }
};

template <class T> struct Tsum {
  T value;
  Tsum(const T& value = 0) : value(value) {}
  operator T() const { return value; }
  void add(const Tsum& other) { value += other.value; }
  friend Tsum combine(const Tsum& lhs, const Tsum& rhs) {
    return lhs.value + rhs.value; }
};

struct S {
  bool ex;
  int a, b, c;

  void inp() {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
      ex = true;
      a = y1; b = y2;
      c = x1;
    } else {
      ex = false;
      a = x1; b = x2;
      c = y1;
    }
    if (a > b) swap(a, b);
  }
};

bool ccmp(const S& a, const S& b) {
  return tie(a.c, a.a) < tie(b.c, b.a);
}

vector<S> x, y;
map<int, int> my;
vector<pii> e;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  int n;
  S t;
  scanf("%d", &n);
  REP(i, n) {
    t.inp();
    if (t.ex) {
      x.pb(t);
      my[t.a] = my[t.b+1] = 0;
    } else {
      y.pb(t);
      my[t.c] = 0;
    }
  }

  int k = 0;
  for (auto& p : my) p.Y = k++;
//  for (auto p : my) printf("%d %d\n", p.X, p.Y);

  ll ans = 0;
  sort(all(x), ccmp);
  sort(all(y), ccmp);

  int r = 0;
  REP(i, sz(y)) {
    int a = y[i].a;
    if (i == 0 || y[i-1].c != y[i].c) r = -2*INF;
    smax(a, r+1);
    smax(r, y[i].b);
    if (a <= y[i].b) {
      ans += y[i].b + 1 - a;
      e.eb(a, i);
      e.eb(y[i].b+1, -i-1);
    }
  }
  sort(all(e));

  SegmentTree<Tsum<int>> tree(k);
  int u = 0;
  REP(i, sz(x)) {
    while (u < sz(e) && e[u].X <= x[i].c) {
//      printf("%d: %d %d\n", u, e[u].X, e[u].Y);
      if (e[u].Y >= 0) tree.add(my[y[e[u].Y].c], 1);
      else tree.add(my[y[-e[u].Y-1].c], -1);
      ++u;
    }
    int a = x[i].a;
    if (i == 0 || x[i-1].c != x[i].c) r = -2*INF;
    smax(a, r+1);
    smax(r, x[i].b);
    if (a <= x[i].b) {
      ans += x[i].b + 1 - a;
      ans -= tree.query(my[a], my[x[i].b+1]);
//      printf("%d %d: %d\n", a, x[i].b, tree.query(my[a], my[x[i].b]+1));
    }
  }
  cout << ans << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}