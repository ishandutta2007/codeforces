#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
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
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T1, class T2>
ostream& operator << (ostream& out, const pair<T1, T2>& p) {
  out << p.X << ',' << p.Y;
  return out;
}
template<class T> void outp(const vector<T>& v) {
  cout << sz(v) << ":";
  REP(i, sz(v)) cout << " " << v[i];
  cout << endl;
}
template<class T> void outp(T* v, int n) {
  cout << n << ":";
  REP(i, n) cout << " " << *v++;
  cout << endl;
}

typedef ll Tc;  // coordinate type
const Tc inf = INF_LL;
template<class T> int cmp(T x, T y) { return x == y ? 0 : x < y ? -1 : 1; }

struct P {
  Tc x, y;
  P() : x(0), y(0) {}
  P(Tc x, Tc y) : x(x), y(y) {}
};
typedef vector<P> Pset;  // Describes polygons etc.
typedef Pset::iterator Pit;

istream& operator >> (istream& is, P& a) { is >> a.x >> a.y; return is; }
ostream& operator << (ostream& os, P a) { os << a.x << ' ' << a.y; return os; }

int cmp(P a, P b) { int cx = cmp(a.x, b.x); return cx ? cx : cmp(a.y, b.y); }
#define COMP(v) bool operator v (P a, P b) { return cmp(a, b) v 0; }
COMP(==) COMP(!=) COMP(<) COMP(>) COMP(<=) COMP(>=)
#undef COMP

P operator - (P a) { return P(-a.x, -a.y); }
P operator + (P a, P b) { return P(a.x + b.x, a.y + b.y); }
P operator - (P a, P b) { return P(a.x - b.x, a.y - b.y); }

Tc operator * (P a, P b) { return a.x * b.x + a.y * b.y; }
Tc operator ^ (P a, P b) { return a.x * b.y - a.y * b.x; }
Tc abs(P a) { return a * a; }
Tc dist2(P a, P b) { return abs(a - b); }

bool cmpy(P a, P b) { return a.y < b.y; }

Tc min_dist(Pit l, Pit r) {
  if (r - l <= 3) {
    Tc d = inf;
    for (Pit i = l; i != r; ++i) for (Pit j = i+1; j != r; ++j)
      smin(d, dist2(*i, *j));
    sort(l, r, cmpy);
    return d;
  }
  Pit m = l + (r - l) / 2;
  Tc mx = m->x;
  Tc d = min(min_dist(l, m), min_dist(m, r));
  static Pset V;
  V.resize(r - l);
  merge(l, m, m, r, V.begin(), cmpy);
  copy(all(V), l);
  V.clear();
  for (m = l; m != r; ++m) if (sqr(m->x - mx) <= d) V.pb(*m);
  REP(i, sz(V)) FORD(j, i-1, 0) {
    if (sqr(V[i].y - V[j].y) >= d) break;
    smin(d, dist2(V[i], V[j]));
  }
  return d;
}

const int h = 100011;
int n;
Pset A;

int main() {
#ifdef LocalHost
  freopen("input1.txt", "r", stdin);
  //freopen("input1.txt", "w", stdout);
#endif

  scanf("%d", &n);
  int a, s = 0;
  REP(i, n) {
    scanf("%d", &a);
    s += a;
    A.pb(P(i+1, s));
  }
  //REP(i, sz(A)) cout << A[i] << endl;
  cout << min_dist(all(A)) << endl;

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}