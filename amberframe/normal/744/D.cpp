#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n)*(n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<double, int> mp;
typedef long long LL ;
const int maxn = 2e5 + 5;
const int mod = 998244353;
const int inf = 1 << 20;
const double dinf = 1e12;
const double eps = 1e-7;
const double pi = acos(-1.0);

int n, m;
vector< mp > iss;

struct node {double x, y;} p[maxn];
double dis(node &a, node &b)
	{return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));}
bool judge(int o, double r)
{
	iss.clear();
	if (o <= n) iss.pb( mp(-pi, 1)), iss.pb( mp(pi, -1));
	repi(n + m) if (i != o)
	{
		double d = dis(p[o], p[i]);
		if (d > 2 * r) continue;
		double arc = atan2(p[i].y - p[o].y, p[i].x - p[o].x);
		double shift = acos(d / 2 / r);
		double arc1 = arc - shift;
		double arc2 = arc + shift;
		if (arc1 <= -pi) arc1 += pi * 2;
		if (arc2 > pi) arc2 -= pi * 2;
		
		if (arc1 <= arc2)
			iss.pb( mp(arc1, i <= n ? 1 : -inf) ),
			iss.pb( mp(arc2, i <= n ? -1 : inf) );
		else
			iss.pb( mp(-pi, i <= n ? 1 : -inf) ),
			iss.pb( mp(arc2, i <= n ? -1 : inf) ),
			iss.pb( mp(arc1, i <= n ? 1 : -inf) ),
			iss.pb( mp(pi, i <= n ? -1 : inf) );
	}
	
	sort(iss.begin(), iss.end());
	
	int cnt = 0;
	for (auto i: iss)
	{
		cnt += i.second;
		if (cnt > 0) return true;
	}
	return false;
}
int main()
{
	#ifdef FILE_TESTn
		freopen("circle.in", "r", stdin);
	#endif
	
	scanf("%d %d", &n, &m);
	repi(n + m) scanf("%lf %lf", &p[i].x, &p[i].y);
	
	double ans = 0;
	for (int i = 1; i <= n + m ; i++)
	if (judge(i, ans))
	{
		if (judge(i, dinf))
			{printf("-1"); return 0;}
		double lb = ans, rb = dinf;
		while (rb - lb > eps)
		{
			double mid = (lb + rb) / 2.0;
			judge(i, mid) ? lb = mid : rb = mid;
		}
		ans = lb; 
	}
	printf("%lf", ans);
	return 0;
}