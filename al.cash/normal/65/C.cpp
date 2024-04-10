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

const double eps = 1e-12;

struct P
{
	double x,y,z;
	P(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}
	
	void inp () { scanf("%lf%lf%lf", &x, &y, &z); }
	void outp () { printf("%.9lf %.9lf %.9lf\n", x, y, z); }
};

P operator + (const P &a, const P &b)
{	return P(a.x+b.x, a.y+b.y, a.z+b.z); }

P operator - (const P &a, const P &b)
{	return P(a.x-b.x, a.y-b.y, a.z-b.z); }

P operator * (const P &a, double v)
{	return P(a.x*v, a.y*v, a.z*v); }

P operator * (double v, const P &a)
{	return P(a.x*v, a.y*v, a.z*v); }

double operator * (const P &a, const P &b)
{	return a.x*b.x + a.y*b.y + a.z*b.z; }

double mod (const P &a)
{	return sqrt(a * a); }

const int h = 11111;

P p[h], o;
double t[h];
int n, vp,vs;

bool ok (int i, double x)
{
	return t[i] + x/vs * mod(p[i+1]-p[i]) + eps > 1.0/vp * mod(p[i] - o + x * (p[i+1]-p[i]));
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d", &n);
	REP(i, n+1) p[i].inp();
	scanf("%d%d", &vp, &vs);
	o.inp();
	t[0] = 0;
	REP(i, n)
	{
		if(ok(i, 1.0))
		{
			printf("YES\n");
			double a=0, b=1, d;
			REP(it, 100)
			{
				d = (a+b)/2;
				if(ok(i, d)) b = d;
				else a = d;
			}
			printf("%.9lf\n", t[i] + b/vs * mod(p[i+1]-p[i]));
			o = p[i] + b * (p[i+1]-p[i]);
			o.outp();
			return 0;
		}
		else t[i+1] = t[i] + 1.0/vs * mod(p[i+1]-p[i]);
	}
	printf("NO\n");
	return 0;
}