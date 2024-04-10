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


template<int N, class T, typename Op>
struct TreeOp {
  Op op;
  int n;
  T t[2*N];

  TreeOp(int n = 0) : op(), n(n) {}
  TreeOp(const Op& op, int n = 0) : op(op), n(n) {}

  T& operator [](int p) { return t[n+p]; }

  void build() {
    FORD(i, n-1, 1) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void upd(int p, T newv) {
    for (t[p += n] = newv; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
  }

  T get(int l, int r) {
    T res = t[l += n];
    for (r += n; l <= r; l = (l+1) >> 1, r = (r-1) >> 1) {
      if ( l&1) res = op(res, t[l]);
      if (~r&1) res = op(res, t[r]);
    }
    return res;
  }
};


const int h = 100011;
int n, d;
ll a[h];

typedef pair<ll, int> pli;
pli o[h];
int u[h], p[h];

template<class T> struct max_s {
  T operator () (T a, T b) { return max(a, b); }
};
TreeOp<h, pii, max_s<pii> > tree;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &d);
  REP(i, n) {
    scanf("%I64d", a+i);
    o[i] = pli(a[i], i);
  }
  sort(o, o+n);
  REP(i, n) u[o[i].Y] = i;

  tree.n = n;
  REP(i, n) {
    int r = upper_bound(o, o+n, pli(a[i] - d, INF)) - o - 1;
    int l = lower_bound(o, o+n, pli(a[i] + d, -INF)) - o;
    pii res(0, 0);
    if (r >= 0) smax(res, tree.get(0, r));
    if (l < n) smax(res, tree.get(l, n-1));
    p[i] = res.Y;
    tree.upd(u[i], pii(res.X + 1, i));
  }

  pii ans = tree.get(0, n-1);
  printf("%d\n", ans.X);
  int v = ans.Y;
  vi s;
  REP(i, ans.X) {
    s.pb(v+1);
    v = p[v];
  }
  reverse(all(s));
  print("%d", all(s));

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}