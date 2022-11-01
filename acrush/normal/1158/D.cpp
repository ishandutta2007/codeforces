#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

struct Point 
{
	Point() = default;
	Point(int64 x, int64 y) : x(x), y(y) {}
	int64 x = 0;
	int64 y = 0;
};

Point operator+(const Point& a, const Point& b)
{
	return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point& a, const Point& b) 
{
	return Point(a.x - b.x, a.y - b.y);
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
int64 outer(const Point& a, const Point& b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		vector<Point> a(n);
		REP(i,n) cin>>a[i].x>>a[i].y;
		string s;
		cin>>s;
		VI ret;
		VI v(n,1);
		int k=0;
		REP(i,n) if (a[i]<a[k]) k=i;
		ret.push_back(k);
		v[k]=0;
		REP(d,n-2)
		{
			int l=-1;
			REP(i,n) if (v[i])
				if (l<0 || outer(a[i]-a[k],a[l]-a[k])*(s[d]=='L'?1:-1)>0)
					l=i;
			k=l;
			ret.push_back(k);
			v[k]=0;
		}
		REP(i,n) if (v[i]) ret.push_back(i);
		REP(i,n) printf("%d ",ret[i]+1);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}