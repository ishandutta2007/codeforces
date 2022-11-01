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

int gcd(int a,int b)
{
	while (b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}

bool is_prime(int n)
{
	if (n<2) return false;
	for (int i=2;i*i<=n;i++) if (n%i==0) return false;
	return true;
}
VI primes;
int trim(int n)
{
	for (int p:primes) for (;n%(p*p)==0;n/=p);
	if (n>1)
	{
		int m=(int)(sqrt((double)n)+0.5);
		if (n==m*m) n=m;
	}
	return n;
}
unordered_map<int,VI> pts;
int get_next(const VI& a,int s,int depth)
{
	if (!pts.count(s))
	{
		VI& w=pts[s];
		REP(i,SIZE(a)) if (s==0 || a[i]%s!=0) w.push_back(i);
	}
	const VI& b=pts[s];
	auto it=lower_bound(ALL(b),depth);
	return it==b.end()?SIZE(a):*it;
}
bool dfs(int depth,int s1,int s2,const VI& a,VI& c)
{
	if (s1==1 && s2==1)
	{
		printf("YES\n");
		REP(i,SIZE(c)) printf("%d ",c[i]+1);
		printf("\n");
		return true;
	}
	int p1=get_next(a,s1,depth);
	int p2=get_next(a,s2,depth);
	depth=min(p1,p2);
	if (depth>=SIZE(a)) return false;
	int g1=gcd(s1,a[depth]);
	int g2=gcd(s2,a[depth]);
	if (g1!=s1 && dfs(depth+1,g1,s2,a,c)) return true;
	if (g2!=s2)
	{
		c[depth]=1;
		bool ret=dfs(depth+1,s1,g2,a,c);
		c[depth]=0;
		if (ret) return true;
	}
	return false;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	FOR(i,2,1000) if (is_prime(i)) primes.push_back(i);
	int n;
	while (cin>>n)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		REP(i,n) a[i]=trim(a[i]);
		VI c(n);
		pts.clear();
		if (!dfs(0,0,0,a,c))
			printf("NO\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}