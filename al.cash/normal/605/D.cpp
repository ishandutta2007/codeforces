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

template <class T> struct Tmin {
  T value;
  int index;
  Tmin(const T& value = numeric_limits<T>::max(), int i = -1)
      : value(value), index(i) {}
  void add(const Tmin& other) { if (value > other.value) *this = other; }
  friend Tmin combine(const Tmin& lhs, const Tmin& rhs) {
    return lhs.value > rhs.value ? rhs : lhs; }
};

const int N = 1e5+5;

struct Card {
  int a, b, c, d;
  void inp() { scanf("%d%d%d%d", &a, &b, &c, &d); }
} c[N];

pii e[2*N];
int g[N], q[N];
int pr[N];

SegmentTree<Tmin<int>> tree;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  ++n;
  REP(i, n) {
    if (i == 0) c[i] = {0, 0, 0, 0};
    else c[i].inp();
    e[i] = {c[i].a, i};
    e[i+n] = {c[i].c, i+n};
  }
  tree.init(n);

  sort(e, e+2*n);
  int k = 0;
  REP(i, 2*n) {
    int u = e[i].Y;
    if (u < n) {
      g[u] = k;
      if (u) tree[k] = {c[u].b, u};
//      printf("%d: %d %d\n", k, tree[k].value, tree[k].index);
      ++k;
    } else {
      c[u-n].c = k;
    }
  }
  tree.build();

  CL(pr, -1);
  q[0] = 0;
  for (int *head = q, *tail = q + 1; head != tail; ++head) {
    int i = *head;
//    printf("%d (%d):\n", i, c[i].c);
    while (true) {
      auto p = tree.query(0, c[i].c);
//      printf("%d %d\n", p.value, p.index);
      if (p.value > c[i].d) break;
      int j = p.index;
      pr[*tail++ = j] = i;
      tree.set(g[j], Tmin<int>());
    }
  }

  if (pr[n-1] == -1) printf("-1\n");
  else {
    vi ans;
    for (int v = n-1; v; v = pr[v]) ans.pb(v);
    printf("%d\n", sz(ans));
    print("%d", ans.rbegin(), ans.rend());
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}