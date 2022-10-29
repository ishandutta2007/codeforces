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
#define sz(a) static_cast<int>((a).size())
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

template <class T> struct Tmin {
  T value;
  Tmin(const T& value = numeric_limits<T>::max()) : value(value) {}
  operator T() const { return value; }
  bool operator < (const Tmin& other) { return other.value < value; }
  void add(const Tmin& other) { smin(value, other.value); }
  friend Tmin combine(const Tmin& lhs, const Tmin& rhs) {
    return min(lhs.value, rhs.value); }
};

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

template <int N>
class SuffixArray {
  int rank[N];
  bool diff[N];
  inline int trim(int i, int n) { return i < n ? i : i - n; }

public:
  int array[N];  //, lcp[N];
  SegmentTree<Tmin<int>> lcp;

  template <class C>
  void build(const C* s, int n) {
    for (int i = 0; i < n; ++i) array[i] = i;
    sort(array, array + n, [s](int x, int y) { return s[x] < s[y]; });
    for (int i = 0; i+1 < n; ++i) diff[i] = s[array[i]] != s[array[i+1]];
    diff[n-1] = true;
    for (int length = 1; length < n; length *= 2) {
      for (int i = 0, group = 0; i < n; group += diff[i], ++i)
        rank[trim(array[i] - length + n, n)] = group;
      for (int i = 0, j = 1; j <= n; ++j) if (diff[j-1]) {
        sort(array + i, array + j,
             [this](int x, int y) { return rank[x] < rank[y]; });
        i = j;
      }
      for (int i = 0; i+1 < n; ++i)
        diff[i] |= rank[array[i]] != rank[array[i+1]];
    }
    for (int i = 0, j = 1; j <= n; ++j) if (diff[j-1])
      sort(array + i, array + j), i = j;
  }

  template <class C>
  void calcLcp(const C* s, int n) {
    build(s, n);
    lcp.init(n-1);
    for (int i = 0; i < n; ++i) rank[array[i]] = i;
    int length = lcp[n-1] = 0;
    for (int i = 0; i < n; ++i) if (rank[i] > 0) {
      int u = trim(i + length, n);
      int v = trim(array[rank[i] - 1] + length, n);
      for (; length < n && s[u] == s[v]; ++length) {
        u = trim(u + 1, n);
        v = trim(v + 1, n);
      }
      lcp[rank[i] - 1] = length;
      if (length > 0) --length;
    }
    lcp.build();
  }

  int queryLcp(int i, int j) {
    i = rank[i];
    j = rank[j];
    if (i > j) swap(i, j);
    return lcp.query(i, j);
  }
};

const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (long long)x * y % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

const int N = 5005;
int n;
char s[N];
SuffixArray<N> a;

int d[N][N], sd[N][N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%s", &n, s);
  a.calcLcp(s, n+1);
  FORD(i, n-1, 0) {
    d[i][n] = sd[i][n] = s[i] == '0' ? 0 : 1;
    FORD(j, n-1, i+1) {
      int t = j - i;
      int l = a.queryLcp(i, j);
//      printf("%d %d: %d (%s,%s)\n", i, j, l, s+i, s+j);
      if (l < t && s[i+l] < s[j+l]) {
        if (j+t <= n) d[i][j] = sd[j][j+t];
      } else {
        if (j+t+1 <= n) d[i][j] = sd[j][j+t+1];
      }
      if (s[i] == '0') d[i][j] = 0;
      sd[i][j] = add(d[i][j], sd[i][j+1]);
    }
  }
  printf("%d\n", sd[0][1]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}