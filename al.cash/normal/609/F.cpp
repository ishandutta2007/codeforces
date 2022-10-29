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

template <class T, typename Cmp = less<T>>
struct SegmentTreeMin {
  Cmp cmp;
  int n;
  vector<int> u;
  vector<T> tree;

  int ind(int i) const { return i < n ? u[i] : i - n; }
  int cmpmin(int i, int j) const { return cmp(tree[j], tree[i]) ? j : i; }
  int cmpmini(int i, int j) const { return cmpmin(ind(i), ind(j)); }

public:
  SegmentTreeMin(const Cmp& cmp = Cmp()) : cmp(cmp), n(0) {}
  void init(int newn) {
    n = newn;
    vector<int>(n).swap(u);
    vector<T>(n).swap(tree);
  }

  int size() const { return n; }
  T& operator [] (int i) { return tree[i]; }
  const T& operator [] (int i) const { return tree[i]; }

  void build() {
    for (int i = n; --i; ) u[i] = cmpmini(i<<1, i<<1|1);
  }

  void set(int i, const T& value) {
    for (tree[i] = value, i += n; i >>= 1; ) u[i] = cmpmini(i<<1, i<<1|1);
  }

  int getpos(int l, int r) const {  // [l, r)
    int il = l, ir = r-1;
    for (l += n+1, r += n-1; l < r; l >>= 1, r >>= 1) {
      if (l&1) il = cmpmin(il, ind(l++));
      if (r&1) ir = cmpmin(ind(--r), ir);
    }
    return cmpmin(il, ir);
  }

  T get(int l, int r) { return tree[getpos(l, r)]; }
};

const int N = 2e5+5;
int n, m;
int x[N], c[N];
ll t[N];
int p[N];

SegmentTreeMin<ll, greater<ll>> tree;
multiset<pii> alive;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d%lld", x+i, t+i), p[i] = i;
  sort(p, p+n, [](int i, int j) { return x[i] < x[j]; });
  sort(x, x+n);

  tree.init(n);
  REP(i, n) tree[i] = x[i] + t[p[i]];
  tree.build();
  
  REP(i, m) {
    int y, b;
    scanf("%d%d", &y, &b);
    int f = upper_bound(x, x+n, y) - x;
    int l = 0, r = f;
    while (l != r) {
      int d = (l + r) / 2;
      if (tree.get(0, d+1) >= y) r = d;
      else l = d + 1;
    }
    if (l == f) alive.insert({y, b});
    else {
      int w = p[l];
      ++c[w];
      t[w] += b;
      auto it = alive.lower_bound({x[l], 0});
      while (it != alive.end() && x[l] + t[w] >= it->X) {
        ++c[w];
        t[w] += it->Y;
        auto tmp = it;
        ++it;
        alive.erase(tmp);
      }
      tree.set(l, x[l] + t[w]);
    }
  }
  REP(i, n) printf("%d %lld\n", c[i], t[i]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}