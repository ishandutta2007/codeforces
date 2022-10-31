#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

typedef complex<double> P;
typedef vector<P> G;
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}

#define EQ(x, y) (abs((x) - (y)) < EPS)
#define LE(x, y) ((x) <= (y) + EPS)
bool intersect_1pt(const P& a, const P& b,
                   const P& c, const P& d, P &r) {
  double D =  cross(b - a, d - c);
  if (EQ(D, 0)) return false;
  double t =  cross(c - a, d - c) / D;
  double s = -cross(a - c, b - a) / D;
  r = a + t * (b - a);
  return LE(0, t) && LE(t, 1) && LE(0, s) && LE(s, 1);
}

enum { OUT, ON, IN };
int convex_contains(const G &O, const P &p) {
    const int n = O.size();
    P g = (O[0] + O[n/3] + O[2*n/3]) / 3.0; // inner-point
    int a = 0, b = n;
    while (a+1 < b) { // invariant: c is in fan g-P[a]-P[b]
        int c = (a + b) / 2;
        if (cross(O[a]-g, O[c]-g) > 0) { // angle < 180 deg
            if (cross(O[a]-g, p-g) > 0 && cross(O[c]-g, p-g) < 0) b = c;
            else                                                  a = c;
        } else {
            if (cross(O[a]-g, p-g) < 0 && cross(O[c]-g, p-g) > 0) a = c;
            else                                                  b = c;
        }
    }
    b %= n;
    if (cross(O[a] - p, O[b] - p) < 0) return OUT;
    if (cross(O[a] - p, O[b] - p) > 0) return IN;
    return ON;
}

G convex_intersect(const G &O, const G &Q) {
    const int n = O.size(), m = Q.size();
    int a = 0, b = 0, aa = 0, ba = 0;
    enum { Pin, Qin, Unknown } in = Unknown;
    G R;
    do {
        int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
        double C = cross(O[a] - O[a1], Q[b] - Q[b1]);
        double A = cross(O[a1] - Q[b], O[a] - Q[b]);
        double B = cross(Q[b1] - O[a], Q[b] - O[a]);
        P r;
        if (intersect_1pt(O[a1], O[a], Q[b1], Q[b], r)) {
            if (in == Unknown) aa = ba = 0;
            R.push_back( r );
            in = B > 0 ? Pin : A > 0 ? Qin : in;
        }
        if (C == 0 && B == 0 && A == 0) {
            if (in == Pin) { b = (b + 1) % m; ++ba; }
            else                     { a = (a + 1) % m; ++aa; }
        } else if (C >= 0) {
            if (A > 0) { if (in == Pin) R.push_back(O[a]); a = (a+1)%n; ++aa; }
            else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
        } else {
            if (B > 0) { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
            else       { if (in == Pin) R.push_back(O[a]); a = (a+1)%n; ++aa; }
        }
    } while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );
    if (in == Unknown) {
        if (convex_contains(Q, O[0])) return O;
        if (convex_contains(O, Q[0])) return Q;
    }
    return R;
}

double area(const G& o) {
  double A = 0;
  for (int i = 0; i < o.size(); ++i) 
    A += cross(o[i], o[(i+1)%o.size()]);
  return abs(A) / 2;
}

const double pi = acos(-1.);
P rotate(P x, double s) {
    return x * P(cos(s), sin(s));
}

int main() {
    double w, h, a;
    cin >> w >> h >> a;
    w /= 2, h /= 2;
    a = a / 180. * pi;
    G rect(4);
    rect[0] = P(-w,  h);
    rect[1] = P(-w, -h);
    rect[2] = P( w, -h);
    rect[3] = P( w,  h);
    G rotated(4);
    rep(i, 4) rotated[i] = rotate(rect[i], a);
    G intersection = convex_intersect(rect, rotated);
    printf("%.10f\n", area(intersection));
    return 0;
}