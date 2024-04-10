/******************************************************************************
 *          How can I feel abandoned even when the world surrounds me         *
 *       How can I bite the hand that feeds the strangers all around me       *
 *             How can I know so many never really knowing anyone             *
 *               If I seem superhuman I have been misunderstood               *
 ******************************************************************************/

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

  void calc(int i, int k) {
    tree[i] = combine(tree[i<<1], tree[i<<1|1]);
    if (delta[i]) tree[i].add(delta[i], k);
  }

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

struct M {
  int color;
  M(int color) : color(color) {}
  explicit M(bool) : color(-1) {}
  explicit operator bool () const { return color != -1; }
  void add(const M& other) { color = other.color; }
};

struct F {
  ll mask;
  F(ll mask = 0) : mask(mask) {}
  void add(const M& delta, int k = 1) { mask = 1LL << delta.color; }
  friend F combine(const F& a, const F& b) { return a.mask | b.mask; }
};

const int N = 4e5+5;
SegmentTreeR<F, M> tree;
int n, m, c[N];
vi e[N];

int tin[N], tout[N], tt = 0;

void dfs(int v, int p) {
  tin[v] = tt++;
  for (int u : e[v]) if (u != p) dfs(u, v);
  tout[v] = tt;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", c+i);
  REP(i, n-1) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    e[x].pb(y);
    e[y].pb(x);
  }
  dfs(0, -1);

  tree.init(n);
  REP(i, n) tree[tin[i]].add(c[i]-1);
  tree.build();

  REP(u, m) {
    int t, v, c;
    scanf("%d%d", &t, &v);
    --v;
    if (t == 1) {
      scanf("%d", &c);
      tree.modify(tin[v], tout[v], c-1);
    } else {
      ll mask = tree.query(tin[v], tout[v]).mask;
      printf("%d\n", (int)__builtin_popcountll(mask));
    }
  }

#ifdef LocalHost
  cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}