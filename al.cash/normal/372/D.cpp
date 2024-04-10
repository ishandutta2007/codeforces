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
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
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
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}


template<class T, typename Op>
class SegmentTree {
 public:
  SegmentTree(int n_ = 0) { init(n_); }
  SegmentTree(const Op& op, int n_ = 0) : op(op) { init(n_); }

  void init(int n_) { n = n_; t = vector<T>(2*n); }

  T& operator [](int p) { return t[p + n]; }
  const T& operator [](int p) const { return t[p + n]; }

  void build() {
    for (int i = n-1; i > 0; --i) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void set(int p, const T& newv) {
    for (t[p += n] = newv; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
  }

  void inc(int p, const T& delta) {  // Use only when applicable.
    for (p += n; p; p >>= 1) t[p] = op(t[p], delta);
  }

  T query(int l, int r) const {  // [l, r)
    T res = t[l += n];
    for (++l, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (r&1) res = op(res, t[--r]);
    }
    return res;
  }

 private:
  Op op;
  int n;
  vector<T> t;
};


struct amin {
  int* a;
  amin(int* a) : a(a) {}
  int operator () (int x, int y) const { return a[x] > a[y] ? y : x; }
};

template<int N>
struct LCA {
  int n;
  vi E[N];

  LCA(int n_ = 0) : tree(amin(lev)) { init(n_); }

  void init(int n_) {
    REP(i, n) vi().swap(E[i]);
    n = n_;
  }

  void add(int a, int b) {
    E[a].pb(b);
    E[b].pb(a);
  }

  int k, pos[N], lev[N];
  SegmentTree<int, amin> tree;

  void dfs(int v, int l) {
    pos[v] = k;
    lev[v] = l;
    tree[k++] = v;
    REP(i, sz(E[v])) {
      int u = E[v][i];
      if (pos[u] == -1) {
        dfs(u, l + 1);
        tree[k++] = v;
      }
    }
  }

  void build(int root = 0) {
    k = 0;
    fill_n(pos, n, -1);
    tree.init(2*n-1);
    dfs(root, 0);
    tree.build();
  }

  pii lca(int a, int b) {
    if (pos[a] > pos[b]) swap(a, b);
    int res = tree.query(pos[a], pos[b]+1);
    return pii(lev[res], res);
  }
};

const int h = 100011;
LCA<h> lca;

int n, k;

set<pii> s;
typedef set<pii>::iterator sit;
sit u[h];

int f(sit x) {
  int v = x->Y;
  int lev = lca.lev[v];
  sit a = x == s.begin() ? s.end() : x;
  sit b = x;
  --a;
  ++b;
  if (b == s.end()) b = s.begin();
  pii ai = lca.lca(v, a->Y);
  pii bi = lca.lca(v, b->Y);
  if (ai.Y == bi.Y) {
    pii ab = lca.lca(a->Y, b->Y);
    return abs(ai.X - ab.X) + abs(ai.X - lev);
  }
  return lev - max(ai.X, bi.X);
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  lca.init(n);
  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    lca.add(a-1, b-1);
  }
  lca.build();

  int ans = 1;
  u[0] = s.insert(pii(lca.pos[0], 0)).X;
  int l = 0, cur = 1;
  FOR(i, 1, n) {
    cur += f(u[i] = s.insert(pii(lca.pos[i], i)).X);
    while (cur > k) {
      cur -= f(u[l]);
      s.erase(u[l]);
      ++l;
    }
    smax(ans, i - l + 1);
  }
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}