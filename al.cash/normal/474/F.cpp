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


template<int N, class T>
struct TreeOp {
  T (*op)(T, T);
  int n;
  T t[2*N];

  TreeOp(T (*op)(T, T), int n = 0) : op(op), n(n) {}

  T& operator [](int p) { return t[n+p]; }

  void build() {
    FORD(i, n-1, 1) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void upd(int p, T newv) {
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

pii mincnt(pii a, pii b) {
  if (a.X < b.X) return a;
  if (b.X < a.X) return b;
  return pii(a.X, a.Y + b.Y);
}

const int h = 100011;
TreeOp<h, int> tgcd(gcd<int>);
TreeOp<h, pii> tmin(mincnt);
int n;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  tgcd.n = tmin.n = n;
  REP(i, n) {
    scanf("%d", &tgcd[i]);
    tmin[i] = pii(tgcd[i], 1);
  }
  tgcd.build();
  tmin.build();

  int t, l, r;
  scanf("%d", &t);
  REP(i, t) {
    scanf("%d%d", &l, &r);
    --l; --r;
    int ans = r - l + 1;
    pii m = tmin.get(l, r);
    if (m.X == tgcd.get(l, r)) ans -= m.Y;
    printf("%d\n", ans);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}