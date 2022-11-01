#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VS=vector<string>;
using VVI=vector<VI>;

using Int = int64;

struct Point 
{
	Point() = default;
	Point(Int x, Int y) : x(x), y(y) {}
	Int x = 0;
	Int y = 0;

	Int length_sqr() const { return x * x + y * y; }
};

Point operator-(const Point& a, const Point& b);
Int distance_sqr(const Point& a, const Point& b)
{
	return (a - b).length_sqr();
}
Point operator+(const Point& a, const Point& b)
{
	return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point& a, const Point& b) 
{
	return Point(a.x - b.x, a.y - b.y);
}
Point operator*(const Point& a, Int b)
{
	return Point(a.x * b, a.y * b);
}
Point operator/(const Point& a, Int b)
{
	return Point(a.x / b, a.y / b);
}
Int inner(const Point& a, const Point& b)
{
	return a.x * b.x + a.y * b.y;
}
Int inner_sign(const Point& a, const Point& b)
{
	Int t = inner(a, b);
	return (t == 0 ? 0 : (t < 0) ? -1 : 1);
}
Int inner(const Point& a, const Point& b, const Point& c)
{
	return inner(b - a, c - a);
}
Int inner_sign(const Point& a, const Point& b, const Point& c)
{
	Int t = inner(a, b, c);
	return (t == 0 ? 0 : (t < 0) ? -1 : 1);
}
Int outer(const Point& a, const Point& b)
{
	return a.x * b.y - a.y * b.x;
}
int outer_sign(const Point& a, const Point& b)
{
	Int t = outer(a, b);
	return (t == 0 ? 0 : (t < 0) ? -1 : 1);
}
Int outer(const Point& a, const Point& b, const Point& c)
{
	return outer(b - a, c - a);
}
int outer_sign(const Point& a, const Point& b, const Point& c)
{
	Int t = outer(a, b, c);
	return (t == 0 ? 0 : (t < 0) ? -1 : 1);
}

bool operator<(const Point& a, const Point& b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool operator>(const Point& a, const Point& b)
{
	return a.x > b.x || a.x == b.x && a.y > b.y;
}
bool operator<=(const Point& a, const Point& b)
{
	return a.x < b.x || a.x == b.x && a.y <= b.y;
}
bool operator>=(const Point& a, const Point& b)
{
	return a.x > b.x || a.x == b.x && a.y >= b.y;
}
bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x && a.y == b.y;
}
bool operator!=(const Point& a, const Point& b)
{
	return a.x != b.x || a.y != b.y;
}

VI sf(const vector<Point>& a)
{
	int n=SIZE(a);
	VI r(n);
	while (1)
	{
		int x=rand()%n;
		int y=rand()%n;
		if (a[x]==a[y]) continue;
		int c=0;
		int p=-1;
		REP(i,n) if (outer_sign(a[i],a[x],a[y])!=0) ++c,p=i;
		if (c>1) continue;
		while (p<0 || p==x || p==y) p=rand()%n;
		vector<pair<int64,int>> b;
		REP(i,n) if (i!=p) b.push_back({(a[i]-a[x]).length_sqr()-(a[i]-a[y]).length_sqr(),i});
		sort(ALL(b));
		r[p]=n-1;
		REP(i,n-1) r[b[i].second]=i;
		return r;
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,src;
	cin>>n>>src; --src;
	vector<Point> a(n);
	REP(i,n) cin>>a[i].x>>a[i].y;
	VI p=sf(a);
	vector<Point> b(n);
	REP(i,n) b[p[i]]=a[i];
	a.swap(b);
	src=p[src];

	auto d=[&](int x,int y) {
		return sqrt((double)(a[x]-a[y]).length_sqr());
	};
	auto f=[&](int s,int t) {
		if (s==src) ++s;
		if (t==src) --t;
		if (s>t) return 0.0;
		return min(d(n-1,s),d(n-1,t))+d(s,t);
	};
	double ret=1e100;
	if (src==n-1)
		ret=f(0,n-2);
	else
	{
		ret=d(src,n-1)+f(0,n-2);
		for (int i=0;i<=n-2;i++)
		{
			ckmin(ret,d(src,0)+d(0,i)+d(i,n-1)+f(i+1,n-2));
			ckmin(ret,d(src,i)+d(i,0)+d(0,n-1)+f(i+1,n-2));
			ckmin(ret,d(src,n-2)+d(n-2,i)+d(i,n-1)+f(0,i-1));
			ckmin(ret,d(src,i)+d(i,n-2)+d(n-2,n-1)+f(0,i-1));
		}
	}
	printf("%.12lf\n",ret);
	return 0;
}