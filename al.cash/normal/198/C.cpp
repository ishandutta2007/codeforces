#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
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
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000;
const double pi = 2 * acos(0.0);
const double eps = 1e-12;

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> void gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

double xp,yp, vp, x,y, v,r;

double r2(double x, double y) {
  return x*x + y*y;
}

double dist(double xt, double yt) {
  double a = r2(x, y), at = r2(xt, yt);
  if(a<at) swap(a, at);
  double ad = r2(x-xt, y-yt);
  double s = fabs(x*yt - y*xt);
  if (s/sqrt(ad) + eps < r && a + eps < at + ad) {
    //printf("Bad: %lf %lf %lf %lf\n", s/sqrt(ad), sqrt(a), sqrt(at), sqrt(ad));
    double f = acos((a+at-ad)/2/sqrt(a)/sqrt(at))
               - acos(r/sqrt(a)) - acos(r/sqrt(at));
    //printf("f = %lf (%lf)\n", f, acos((a+at-ad)/2/sqrt(a)/sqrt(at)));
    return sqrt(a-r*r) + sqrt(at-r*r) + r * f;
  } else {
    return sqrt(ad);
  }
}

double R, fi0;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%lf%lf%lf", &xp, &yp, &vp);
  scanf("%lf%lf%lf%lf", &x, &y, &v, &r);
  R = sqrt(r2(xp, yp));
  fi0 = atan2(yp, xp);

  double a = 0.0, b = 1e6;
  REP(it, 100) {
    double t = (a+b) / 2;
    double fi = fi0 + (t * vp / R);
    double xt = R*cos(fi), yt = R*sin(fi);
    double d = dist(xt, yt);
    //printf("%lf: %lf %lf, %lf (%lf)\n", t, xt, yt, d, v*t);
    if (d < v*t + eps) b = t;
    else a = t;
  }
  printf("%.9lf\n", b);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}