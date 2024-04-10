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
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

typedef double Tc;  // coordinate type

struct P {
  Tc x, y;
  P() : x(0), y(0) {}
  P(const Tc& x, const Tc& y) : x(x), y(y) {}

  //  bool inp() { return scanf("%d%d", &x, &y) == 2; }
  //  void outp() const { printf("%d %d\n", x, y); }
  bool inp() { return scanf("%lf%lf", &x, &y) == 2; }
  void outp() const { printf("%.6lf %.6lf\n", x, y); }
};
typedef vector<P> Pset;  // Describes polygons etc.
typedef Pset::iterator Pit;

istream& operator >> (istream& is, P& a) { return is >> a.x >> a.y; }
ostream& operator << (ostream& os, const P& a) {
  return os << a.x << ' ' << a.y; }

bool operator == (const P& a, const P& b) { return a.x == b.x && a.y == b.y; }
bool operator != (const P& a, const P& b) { return !(a == b); }

template <class T> int cmp(const T& a, const T& b) {
  return a < b ? -1 : a > b ? 1 : 0;
}

#define CMP(v) bool operator v (const P& a, const P& b) { \
return a.x v b.x || (a.x == b.x && a.y v b.y); \
}
CMP(<) CMP(>) CMP(<=) CMP(>=)
#undef CMP

P operator - (const P& a) { return P(-a.x, -a.y); }
P operator + (const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
P operator - (const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
P operator * (const Tc& c, const P& a) { return P(c * a.x, c * a.y); }
P operator * (const P& a, const Tc& c) { return P(a.x * c, a.y * c); }
P operator / (const P& a, const Tc& c) { return P(a.x / c, a.y / c); }

Tc operator * (const P& a, const P& b) { return a.x * b.x + a.y * b.y; }
Tc operator ^ (const P& a, const P& b) { return a.x * b.y - a.y * b.x; }
Tc abs(const P& a) { return a * a; }
Tc len(const P& a) { return sqrt(abs(a)); }
// 1 if b <- a counter-clockwise
int ccw(const P& a, const P& b) { return cmp(a ^ b, (Tc)0); }
int ccw(const P& o, const P& a, const P& b) { return ccw(a - o, b - o); }
P perp(const P& a) { return P(-a.y, a.x); }

P closest(const P& a, const P& b, const P& x) {
  P ab = b - a;
  if ((x - a) * ab < (Tc)0 || a == b) return a;
  if ((x - b) * ab > (Tc)0) return b;
  return a + ab * ((x - a) ^ perp(ab)) / abs(ab);
}

const int N = 1e5+5;
int n;
P p, a[N];
double ra, rb;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  p.inp();
  REP(i, n) a[i].inp();
  ra = 1e100;
  rb = 0;
  REP(i, n) {
    P c = closest(a[i], a[(i+1)%n], p);
//    c.outp();
    double d = abs(p - c);
    smin(ra, d);
    smax(rb, abs(p - a[i]));
  }
  printf("%.9lf\n", pi * (rb - ra));

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}