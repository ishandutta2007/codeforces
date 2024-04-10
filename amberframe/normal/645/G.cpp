#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n) * (n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<double, int> mp;
typedef long long LL ;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
const double pi = acos(-1.0);

struct node {
	double x, y;
	node(double _x = 0.0, double _y = 0.0)
		{x = _x; y = _y;}
	double operator*(const node &v)
		const {return sqrt( sqr(x - v.x) + sqr(y - v.y));}
}P1, P2, p[maxn];
int n; double a, r1[maxn], r2[maxn];
vector< mp > iss;
int stk[maxn], top;
bool check(double l)
{
	iss.clear();
	repi(n) if (r1[i] + l > r2[i] && r2[i] + l > r1[i])
	{
		double arc = atan2(p[i].y - P2.y, p[i].x - P2.x);
		double shift = acos( (sqr(l) + sqr(r2[i]) - sqr(r1[i])) / (2. * l * r2[i]));
		double L = arc - shift;
		double R = arc + shift;
		if (L > R) swap(L, R);
		if (L < -pi) L += 2 * pi;
		if (R > pi) R -= 2 * pi;
		if (L > R) swap(L, R);
		
		iss.pb( mp(L, -i));
		iss.pb( mp(R, i));
	}
	sort(iss.begin(), iss.end());
	
	top = 0;
	for (auto e: iss)
	{
		if (e.second < 0)
			stk[++top] = e.second;
		else {
			if (e.second != -stk[top])
				return true;
			--top;
		}
	}
	return false;
}
int main()
{
	#ifdef FILE_TEST
		freopen("area.in", "r", stdin);
	#endif
	
	scanf("%d %lf", &n, &a);
	P1 = node(-a, 0);
	P2 = node(a, 0);
	repi(n) scanf("%lf %lf", &p[i].x, &p[i].y);
	repi(n) r1[i] = p[i] * P1;
	repi(n) r2[i] = p[i] * P2;
	
	double lb = 0, rb = 2 * a;
	while (rb - lb > eps)
	{
		double mid = (lb + rb) / 2;
		check(mid) ? rb = mid : lb = mid;
	}
	printf("%.8lf", rb);
	return 0;
}