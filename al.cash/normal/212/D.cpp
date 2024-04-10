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
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 2000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int h = 1100000;
int n, m, k;
pii t[2*h];

void build() {
  t[2*n+1] = pii(INF, 0);
  FORD(i, n, 1) t[i] = min(t[2*i], t[2*i+1]);
}

pii get(int x, int y) {
  pii res(INF, 0);
  for (x += n+1, y += n; x <= y; x = x+1>>1, y = y-1>>1)
    res = min(res, min(t[x], t[y]));
  return res;
}

struct tree {
  ll t[2*h];

  void init() { CL(t, 0); }

  void inc(int v, int tl, int tr, int l, int r, ll delta) {
    if (l >= r) return;
    if (l == tl && r == tr) t[v] += delta;
    else {
      int tm = (tl + tr) / 2;
      inc(2*v, tl, tm, l, min(r, tm), delta);
      inc(2*v+1, tm, tr, max(l, tm), r, delta);
    }
  }

  ll get(int v, int tl, int tr, int p) {
    ll res = t[v];
    if (tl + 1 < tr) {
      int tm = (tl + tr) / 2;
      if (p < tm) res += get(2*v, tl, tm, p);
      else res += get(2*v+1, tm, tr, p);
    }
    return res;
  }
} T;

pii q[h];

ll sum[h];

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  int a;
  REP(i, n) {
    scanf("%d", &a);
    t[i+n+1] = pii(a, i);
  }
  build();
  T.init();
  q[0] = pii(0, n);
  for (int qa = 0, qb = 1; qa < qb; ++qa) {
    int l = q[qa].X, r = q[qa].Y;
    int d = r - l;
    pii p = get(l, r);
    int h = p.X, i = p.Y;
    //printf("%d %d (%d): %d, %d\n", l, r, d, i, h);
    T.inc(1, 0, n+2, 1, d+2, h);
    T.inc(1, 0, n+2, i-l+2, d+2, -h);
    T.inc(1, 0, n+2, d-i+l+1, d+2, -h);
    if (l < i) q[qb++] = pii(l, i);
    if (i + 1 < r) q[qb++] = pii(i + 1, r);
  }
  sum[0] = 0.0;
  FOR(i, 1, n+1) sum[i] = sum[i-1] + T.get(1, 0, n+2, i);
  scanf("%d", &m);
  REP(i, m) {
    scanf("%d", &k);
    printf("%.12lf\n", double(sum[k]) / (n - k + 1));
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}