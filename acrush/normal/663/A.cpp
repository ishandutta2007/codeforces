#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

int n;
int c1,c2;
int m,a[256];
int r1[256],r2[256];

void solve(int r[],int c,int s)
{
	s-=c;
	REP(i,c)
	{
		r[i]=min(n-1,s);
		s-=r[i];
		r[i]++;
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	m=c1=c2=0;
	string s;
	while (cin>>s)
		if (s=="?" || s=="+" || s=="-")
		{
			a[m++]=(s=="-"?-1:1);
			if (s!="?") cin>>s;
		}
		else
		{
			cin>>n;
			break;
		}
	REP(i,m)
		if (a[i]>0) c1++;
		else c2++;
	bool ok=false;
	vector<int> p;
	p.push_back(c1);
	p.push_back(c2+n);
	p.push_back(c1*n);
	p.push_back(c2*n+n);
	for (int s1:p)
	{
		int s2=s1-n;
		if (s1>=c1 && s1<=c1*n && s2>=c2 && s2<=c2*n)
		{
			ok=true;
			solve(r1,c1,s1);
			solve(r2,c2,s2);
			break;
		}
	}
	if (!ok)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	REP(i,m)
		if (a[i]>0)
		{
			if (i>0) printf(" + ");
			printf("%d",r1[--c1]);
		}
		else
		{
			if (i>0) printf(" - ");
			printf("%d",r2[--c2]);
		}
	printf(" = %d\n",n);
	return 0;
}