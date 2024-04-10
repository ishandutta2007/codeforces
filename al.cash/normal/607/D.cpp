#include <stdexcept>
#include <iostream>
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

const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (long long)x * y % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

template <class T>
T qpow(T x, long long power) {
  T res = 1;
  for (; power; power >>= 1, x = mul(x, x))
    if (power & 1) res = mul(res, x);
  return res;
}

template <class T> T inv(T x) { return qpow(x, mod - 2); }

template <class T>
T inverse(const T& x, const T& module) {
  return x < 2 ? x : module - inverse(module % x, x) * module / x;
}


template <class T, class M = T>
class SegmentTreeR {
public:
  int n, height;
  vector<T> tree;
  vector<M> delta;

  void calc(int i, int k) {
    tree[i] = combine(tree[i<<1], tree[i<<1|1]);
    if (delta[i]) tree[i].add(delta[i], k);
  }

  void apply(int i, const M& value, int k) {
    tree[i].add(value, k);
    delta[i].add(value, k);
  }

public:
  SegmentTreeR(int newn = 0) { init(newn); }

  void init(int newn) {
    n = newn;
    height = sizeof(n) * 8 - __builtin_clz(n);
    vector<T>(2*n).swap(tree);
    vector<M>(2*n, M(false)).swap(delta);
  }

  int size() const { return n; }
  T& operator [] (int i) { return tree[i + n]; }
  const T& operator [] (int i) const { return tree[i + n]; }
  T& f(int i) { return delta[i + n]; }

  void build(int l, int r) {
    int k = 2;
    for (l += n, r += n-1; r >>= 1, l >>= 1; k <<= 1)
      for (int i = r; i >= l; --i) calc(i, k);
  }
  void build() { build(0, n); }

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
    bool cl = false, cr = false;
    int k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (cl) calc(l - 1, k);
      if (l&1) apply(l++, value, k), cl = true;
      if (cr) calc(r, k);
      if (r&1) apply(--r, value, k), cr = true;
    }
    for (--l; r; l >>= 1, r >>= 1, k <<= 1) {
      if (cl) calc(l, k);
      if (cr && (!cl || l != r)) calc(r, k);
    }
  }

  T query(int l, int r) {
    push(l, l + 1);
    push(r - 1, r);
    T resl = T(), resr = T();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, tree[l++]);
      if (r&1) resr = combine(tree[--r], resr);
    }
    return combine(resl, resr);
  }
};

struct S {
  int v;
  S(int v = 0) : v(v) {}
  operator int() const { return v; }
  explicit S(bool) : v(1) {}
  explicit operator bool () const { return v !=-1; }
  void add(const S& other, int k = 1) { v = mul(v, other.v); }
  friend S combine(const S& lhs, const S& rhs) { return ::add(lhs.v, rhs.v); }
};

const int N = 2e5+5;
int q, n;
int p[N], v[N];
int o[N], u[N];

vi g[N];
int tin[N], tout[N], ttime = 0;

void dfs(int v) {
  tin[v] = ttime++;
  for (int u : g[v]) dfs(u);
  tout[v] = ttime;
}

int k[N];
SegmentTreeR<S> tree;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", v+0, &q);
  p[0] = -1;
  n = 1;
  REP(i, q) {
    scanf("%d", o+i);
    if (o[i] == 1) {
      scanf("%d%d", p+n, v+n);
      --p[n];
      g[p[n]].pb(n);
      ++n;
    } else {
      scanf("%d", u+i);
      --u[i];
    }
  }

  dfs(0);
//  print("%d", tin, tin + n);
//  print("%d", tout, tout + n);
  tree.init(n);
  tree[0] = v[0];
  tree.build();

  CL(k, 0);
  int n0 = n;
  n = 1;
  REP(i, q) {
//    tree.push();
//    REP(i, n0) printf("%d,%d ", tree.getv(i), tree.getm(i)); printf("\n");
    if (o[i] == 1) {
      tree.push(tin[n], tin[n] + 1);
      tree[tin[n]] = mul(v[n], tree.f(tin[n]));
      tree.build(tin[n], tin[n] + 1);
      int x = p[n];
      ++k[x];
      int d = mul(k[x] + 1, inv(k[x]));
//      printf("applyin %d on [%d,%d)\n", d, tin[x], tout[x]);
      tree.modify(tin[x], tout[x], d);
      ++n;
    } else {
      int x = u[i];
      int ans = tree.query(tin[x], tout[x]);
      int d = 1;
      if (x != 0) {
        tree.push(tin[p[x]], tin[p[x]] + 1);
        d = inv(tree.f(tin[p[x]]));
      }
      printf("%d\n", mul(ans, d));
    }
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}