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

const int maxsize=(2<<20);

int n;
int b[maxsize];
int64 a[maxsize];
int f[maxsize],r[maxsize],l1[maxsize],l2[maxsize],r1[maxsize],r2[maxsize];

void solve1(int id,int p)
{
	f[id]=r[id]=l1[id]=l2[id]=r1[id]=r2[id]=0;
	if (a[p]!=0) f[id]=r[id]=r1[id]=r2[id]=1;
	if (a[p]>0) l2[id]=1;
	if (a[p]<0) l1[id]=1;
}
void solve2(int id,int s,int t)
{
	int m=(s+t)/2;
	int id1=id*2+1;
	int id2=id*2+2;
	int c1=m-s+1;
	int c2=t-m;
	int c=t-s+1;
	l1[id]=((l1[id1]==c1)?(c1+l1[id2]):l1[id1]);
	l2[id]=((l2[id2]==c2)?(c2+l2[id1]):l2[id2]);
	if (f[id1] && a[m]<0 && l1[id2]==c2 || f[id2] && a[m]>0 && l2[id1]==c1)
	{
		f[id]=1;
		r[id]=r1[id]=r2[id]=c;
	}
	else
	{
		f[id]=0;
		r[id]=max(r[id1],r[id2]);
		ckmax(r[id],r2[id1]+l1[id2]);
		ckmax(r[id],r1[id2]+l2[id1]);
		r1[id]=((l2[id1]==c1)?(r1[id2]+c1):r1[id1]);
		r2[id]=((l1[id2]==c2)?(r2[id1]+c2):r2[id2]);
		if (f[id1]) ckmax(r1[id],c1+l1[id2]);
		if (f[id2]) ckmax(r2[id],c2+l2[id1]);
		ckmax(r[id],l2[id1]+l1[id2]);
	}
}
void init(int id,int s,int t)
{
	if (s==t) { solve1(id,s); return; }
	int m=(s+t)/2;
	init(id*2+1,s,m);
	init(id*2+2,m+1,t);
	solve2(id,s,t);
}
void update(int id,int s,int t,int key)
{
	if (s==t) { solve1(id,s); return; }
	int m=(s+t)/2;
	if (key<=m) update(id*2+1,s,m,key);
	else update(id*2+2,m+1,t,key);
	solve2(id,s,t);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	REP(i,n) cin>>b[i];
	--n;
	REP(i,n) a[i]=b[i+1]-b[i];
	if (n>0) init(0,0,n-1);
	int m;
	for (cin>>m;m>0;m--)
	{
		int s,t,d;
		cin>>s>>t>>d; --s; --t;
		if (n==0)
		{
			printf("1\n");
			continue;
		}
		if (s>0) 
		{
			a[s-1]+=d;
			update(0,0,n-1,s-1);
		}
		if (t<n)
		{
			a[t]-=d;
			update(0,0,n-1,t);
		}
		printf("%d\n",r[0]+1);
	}
	return 0;
}