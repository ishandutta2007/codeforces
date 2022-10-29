#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const double eps = 1e-9;

bool eq (double x, double y) { return fabs(x-y) < eps; }

struct P {
	double x,y;
	P () : x(0), y(0) {}
	P (double x, double y) : x(x), y(y) {}

	bool inp () { return (scanf("%lf%lf", &x, &y)==2); }
	void outp () { printf("%lf %lf\n", x, y); }
};

bool operator == (const P &a, const P &b)
{	return eq(a.x, b.x) && eq(a.y, b.y); }

const P operator + (const P &a, const P &b)
	{ return P(a.x+b.x, a.y+b.y); }
const P operator - (const P &a, const P &b)
	{ return P(a.x-b.x, a.y-b.y); }
const P operator * (double a, const P &b)
	{ return P(a*b.x, a*b.y); }
const P operator * (const P &a, double b)
	{ return P(a.x*b, a.y*b); }
const P operator / (const P &a, double b)
	{ return P(a.x/b, a.y/b); }

const double operator * (const P &a, const P &b)
	{ return a.x*b.x + a.y*b.y; }
const double operator ^ (const P &a, const P &b)
	{ return a.x*b.y - a.y*b.x; }
const double mod (const P &a)
	{ return a.x*a.x + a.y*a.y; }
const double len (const P &a)
	{ return sqrt( mod(a) ); }

bool cross (const P &a, const P &ab, const P &c, const P &cd, P &res)
{
	double d = ab ^ cd;
	if(fabs(d) < eps) return 0;
	double di = (c-a) ^ cd, dj = (c-a) ^ ab;
	if(d<0) d = -d, di = -di, dj = -dj;
	res = a + di*ab/d;
	return (-eps<di && -eps<dj && di<d+eps && dj<d+eps);
}

bool acomp (const P &a, const P &b) 
{	return ((a ^ b) > eps); }

typedef vector<P> Pset;

double S2 (const Pset &A)
{
	if(A.empty()) return 0;
	double res = A[sz(A)-1]^A[0];
	REP(i, sz(A)-1) res += A[i]^A[i+1];
	return fabs(res);
}

double S2abs (const Pset &A, const P &b)
{
	if(A.empty()) return 0;
	double res = fabs((A[sz(A)-1]-b) ^ (A[0]-b));
	REP(i, sz(A)-1) res += fabs((A[i]-b) ^ (A[i+1]-b));
	return res;
}

//intersection of two convex polygons
const Pset intersec (const Pset &A, const Pset &B)
{
	Pset C;
	int i,j, na=sz(A), nb=sz(B);
	double sA = S2(A), sB = S2(B);
	REP(i, na) if(eq(S2abs(B, A[i]), sB)) C.pb(A[i]);
	REP(j, nb) if(eq(S2abs(A, B[j]), sA)) C.pb(B[j]);
	P v;
	REP(i, na) REP(j, nb)
		if(cross(A[i], A[i+1==na ? 0 : i+1]-A[i], B[j], B[j+1==nb ? 0 : j+1]-B[j], v))
			C.pb(v);
	for(int i=sz(C)-1; i>=0; --i) C[i] = C[i]-C[0];
	j=1; v=P();
	FOR(i, 1, sz(C)) if(C[i]==v) swap(C[i], C[j]), ++j;
	if(!C.empty()) sort(C.begin()+j, C.end(), acomp);
	return C;
}

const int N = 555;

int n,h,f;
int l[N],r[N];

Pset A[N], B[N];

double xl (double x)
{
	return x * (1 + 2.0*h/double(f-h));
}

double xu (double x)
{
	return x * (1 + 2.0*h/double(f-h));
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &h, &f);
	REP(i, n) scanf("%d%d", l+i, r+i);
	REP(i, n)
	{
		A[i].clear();
		A[i].pb( P(r[i], h) );
		A[i].pb( P(l[i], h) );
		A[i].pb( P(xl(l[i]), -h) );
		A[i].pb( P(xl(r[i]), -h) );

		B[i].clear();
		B[i].pb( P(r[i], -h) );
		B[i].pb( P(l[i], -h) );
		B[i].pb( P(xu(l[i]), h) );
		B[i].pb( P(xu(r[i]), h) );
	}
	double ans = 0;
	REP(i, n)
		ans += S2(A[i]) - S2(intersec(A[i], B[i])) / 2;
	REP(i, n) FOR(j, i+1, n)
		ans -= S2(intersec(A[i], B[j]));
	printf("%.9lf\n", ans);
	return 0;
}