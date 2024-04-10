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

const int maxsize=(1<<20);
const int MOD=1000000007;

#define MUL(a,b) ((int)(((int64)(a)*(int64)(b)%(MOD))))

int n,k,q;
int firstp[maxsize];
int cnt,lst[maxsize];
int w[maxsize];
int c[maxsize],e[maxsize];
int sum;
int mxt[maxsize];
int inv[maxsize];

void add(int p)
{
	sum-=e[p];
	if (sum<0) sum+=MOD;

	c[p]++;
	if (c[p]==k)
		e[p]=w[p];
	else
		e[p]=MUL(e[p],MUL(c[p],inv[c[p]-k]));

	sum+=e[p];
	if (sum>=MOD) sum-=MOD;
}
int getall(int n)
{
	cnt=1;
	lst[0]=1;
	for (;n>1;)
	{
		int p=firstp[n];
		int e=0;
		for (;n%p==0;n/=p) e++;
		int new_cnt=cnt*(e+1);
		FOR(i,cnt,new_cnt) lst[i]=lst[i-cnt]*p;
		cnt=new_cnt;
	}
	return cnt;
}
void preprocess()
{
	inv[1]=1;
	FOR(i,2,maxsize) inv[i]=(MOD-MUL(inv[MOD%i],MOD/i))%MOD;
	REP(i,maxsize) firstp[i]=i;
	FOR(i,2,maxsize) if (firstp[i]==i)
		for (int j=i+i;j<maxsize;j+=i)
			firstp[j]=i;
	mxt[1]=1;
	FOR(i,2,maxsize)
	{
		int p=firstp[i];
		int j=i/p;
		if (j%p==0) mxt[i]=0;
		else mxt[i]=-mxt[j];
	}
	memset(w,0,sizeof(w));
	FOR(i,1,maxsize) for (int d=i,j=1;d<maxsize;j++,d+=i)
		if (mxt[j]==1)
		{
			w[d]+=i;
			if (w[d]>=MOD) w[d]-=MOD;
		}
		else if (mxt[j]==-1)
		{
			w[d]-=i;
			if (w[d]<0) w[d]+=MOD;
		}
}
int main()
{
#ifdef _MSC_VER
	freopen("f.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	preprocess();
	cin>>n>>k>>q;
	memset(c,0,sizeof(c));
	memset(e,0,sizeof(e));
	sum=0;
	REP(step,n) 
	{
		int d;
		cin>>d;
		getall(d);
		REP(i,cnt) add(lst[i]);
	}
	REP(step,q)
	{
		int d;
		cin>>d;
		getall(d);
		REP(i,cnt) add(lst[i]);
		printf("%d\n",sum);
	}
	return 0;
}