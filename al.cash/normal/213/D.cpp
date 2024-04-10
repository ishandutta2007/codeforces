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

const int INF = 1000000000;
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
typedef double Tc;  // coordinate type

struct P {
  Tc x, y;
  P(Tc x = 0, Tc y = 0) : x(x), y(y) {}
};

void outp(const P& a) { printf("%.15lf %.15lf\n", a.x, a.y); }

P operator - (P a) { return P(-a.x, -a.y); }
P operator + (P a, P b) { return P(a.x + b.x, a.y + b.y); }
P operator - (P a, P b) { return P(a.x - b.x, a.y - b.y); }
P operator * (Tc c, P a) { return P(c * a.x, c * a.y); }
P operator * (P a, Tc c) { return P(a.x * c, a.y * c); }
P operator / (P a, Tc c) { return P(a.x / c, a.y / c); }

P rot(P a, Tc _sin, Tc _cos) {  // rotate ccw
  return P(_cos * a.x - _sin * a.y, _sin * a.x + _cos * a.y); }
P rot(P a, Tc angle) { return rot(a, sin(angle), cos(angle)); }

int n;

const double r = 5 / sin(pi/5);
P a[4];

int main() {
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  a[3] = P(0, r);
  FOR(i, 1, 4) a[i-1] = rot(a[3], 2*i*pi/5);
  //REP(i, 4) printf("%lf\n", sqrt(a[i].x*a[i].x + a[i].y*a[i].y));
  printf("%d\n", 4*n+1);
  REP(i, n) REP(j, 4) outp(P(a[j].x - 2*i*a[0].x, a[j].y));
  outp(P(a[0].x - 2*n*a[0].x, a[0].y));
  REP(i, n) {
    REP(j, 3) printf("%d ", i*4 + j+1);
    printf("%d %d\n", i*4+5, i*4+4);
  }
  REP(i, n+1) printf("%d ", 4*i+1);
  FORD(i, n-1, 0) printf("%d %d %d %d%c", 4*i+2, 4*i+4, 4*i+3, 4*i+1,
                         i ? ' ' : '\n');

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}