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

const int maxn=(1<<20);
const int MOD=1000000007;

#define MUL(a,b) ((int)((int64)(a)*(int64)(b)%MOD))

int n;
int m;
int a[maxn];
vector<int> g[maxn];
int v0[maxn],v1[maxn],v2[maxn],v3[maxn];
int sizeq;
int q[maxn],s[maxn],t[maxn];
int w[maxn];
int mul[maxn*4];
int sum[maxn*4];

void dfs(int p)
{
	s[p]=sizeq;
	q[sizeq++]=p;
	REP(i,SIZE(g[p])) dfs(g[p][i]);
	t[p]=sizeq-1;
}
void push(int id)
{
	if (mul[id]==1) return;
	int x=mul[id];
	mul[id]=1;
	mul[id*2+1]=MUL(mul[id*2+1],x);
	mul[id*2+2]=MUL(mul[id*2+2],x);
	sum[id*2+1]=MUL(sum[id*2+1],x);
	sum[id*2+2]=MUL(sum[id*2+2],x);
}
void pop(int id)
{
	sum[id]=MUL(mul[id],sum[id*2+1]+sum[id*2+2]);
}
void add_one(int id,int s,int t,int key)
{
	if (s==t) { sum[id]=MUL(mul[id],a[s]); return; }
	push(id);
	int m=(s+t)/2;
	if (key<=m) add_one(id*2+1,s,m,key);
	else add_one(id*2+2,m+1,t,key);
	pop(id);
}
int inverse(int x)
{
	int e=MOD-2;
	int r=1;
	for (;e>0;e/=2)
	{
		if (e&1) r=MUL(r,x);
		x=MUL(x,x);
	}
	return r;
}
void init(int id,int s,int t)
{
	if (s==t)
	{
		mul[id]=1;
		sum[id]=MUL(mul[id],a[q[s]]);
		return;
	}
	mul[id]=1;
	int m=(s+t)/2;
	init(id*2+1,s,m);
	init(id*2+2,m+1,t);
	pop(id);
}
void update(int id,int s,int t,int l,int r,int d)
{
	if (s>=l && t<=r)
	{
		mul[id]=MUL(mul[id],d);
		sum[id]=MUL(sum[id],d);
		return;
	}
	push(id);
	int m=(s+t)/2;
	if (l<=m)
		update(id*2+1,s,m,l,r,d);
	if (m<r)
		update(id*2+2,m+1,t,l,r,d);
	pop(id);
}
int get_one(int id,int s,int t,int key)
{
	if (s==t) return mul[id];
	push(id);
	int m=(s+t)/2;
	return (key<=m)?get_one(id*2+1,s,m,key):get_one(id*2+2,m+1,t,key);
}
int get_sum(int id,int s,int t,int l,int r)
{
	if (s>=l && t<=r) return sum[id];
	push(id);
	int m=(s+t)/2;
	int ret=0;
	if (l<=m)
		ret+=get_sum(id*2+1,s,m,l,r);
	if (m<r)
		ret+=get_sum(id*2+2,m+1,t,l,r);
	if (ret>=MOD) ret-=MOD;
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	n=1;
	cin>>a[0]>>m;
	REP(i,m) 
	{
		cin>>v0[i]>>v1[i];
		if (v0[i]==1) cin>>v2[i];
	}
	REP(i,m)
		if (v0[i]==1)
		{
			--v1[i];
			g[v1[i]].push_back(n);
			v3[i]=n;
			a[n]=v2[i];
			n++;
		}
		else
		{
			--v1[i];
		}
	sizeq=0;
	dfs(0);
	REP(i,n) w[i]=SIZE(g[i])+1;
	init(0,0,n-1);
	REP(i,n)
		update(0,0,n-1,s[i],t[i],w[i]);
	for (int i=m-1;i>=0;i--)
		if (v0[i]==1)
		{
			int key=v1[i];
			update(0,0,n-1,s[key],t[key],MUL(inverse(w[key]),(w[key]-1)));
			w[key]--;
			key=v3[i];
			update(0,0,n-1,s[key],t[key],MUL(inverse(w[key]),(w[key]-1)));
			w[key]--;
		}
		else
		{
			int key=v1[i];
			int val=get_one(0,0,n-1,s[key]);
			int ret=get_sum(0,0,n-1,s[key],t[key]);
			v2[i]=MUL(inverse(val),MUL(w[key],ret));
		}
	REP(i,m) if (v0[i]==2) printf("%d\n",v2[i]);
	return 0;
}