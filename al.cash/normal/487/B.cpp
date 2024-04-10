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

  TreeOp(int n = 0) : n(n) {}
  TreeOp(const Op& op, int n = 0) : op(op), n(n) {}

  T& operator [](int p) { return t[n + p]; }

  void build() {
    for (int i = n - 1; i > 0; --i) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void upd(int p, const T& newv) {
    for (t[p += n] = newv; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
  }

  T get(int l, int r) {
    T res = t[l += n];
    for (++l, r += n; l <= r; l = (l+1) >> 1, r = (r-1) >> 1) {
      if ( l&1) res = op(res, t[l]);
      if (~r&1) res = op(res, t[r]);
    }
    return res;
  }
};

template<int N, class T>  // Op is a function where arguments are passed
struct TreeOpf {
  typedef TreeOp<N, T, T (*)(T, T)> val;                       // by value
  typedef TreeOp<N, T, const T& (*)(const T&, const T&)> ref;  // by reference
};

const int h = 100011;
int n, s, l, a[h];
int ua[h], ub[h], u[h];

priority_queue<pii> q;

TreeOpf<h, int>::ref tmin(min<int>);

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &s, &l);
  REP(i, n) scanf("%d", a+i);

  REP(i, n) {
    while (!q.empty() && a[i] > -q.top().X + s) {
      ub[q.top().Y] = i;
      q.pop();
    }
    q.push(pii(-a[i], i));
  }
  while (!q.empty()) {
    ub[q.top().Y] = n;
    q.pop();
  }

  REP(i, n) {
    while (!q.empty() && a[i] < q.top().X - s) {
      ua[q.top().Y] = i;
      q.pop();
    }
    q.push(pii(a[i], i));
  }
  while (!q.empty()) {
    ua[q.top().Y] = n;
    q.pop();
  }

  tmin.n = n + 1;
  u[n] = n;
  tmin.upd(n, 0);
  FORD(i, n-1, 0) {
    u[i] = min(ua[i], ub[i]);
    smin(u[i], u[i+1]);
    if (i + l <= u[i]) tmin.upd(i, 1 + tmin.get(i + l, u[i]));
    else tmin.upd(i, INF);
  }

  int res = tmin[0];
  printf("%d\n", res >= INF ? -1 : res);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}