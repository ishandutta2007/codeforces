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

int64 gcd(int64 a,int64 b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n,m;
		cin>>n>>m;
		vector<int64> a(n);
		REP(i,n) cin>>a[i];
		vector<VI> g(n);
		REP(i,m)
		{
			int a,b;
			cin>>a>>b;
			--a;
			--b;
			g[b].push_back(a);
		}
		REP(i,n) sort(ALL(g[i]));
		VI p;
		REP(i,n) if (!g[i].empty()) p.push_back(i);
		sort(ALL(p),[&](int a,int b) { return SIZE(g[a])<SIZE(g[b]) || SIZE(g[a])==SIZE(g[b]) && g[a]<g[b]; });
		int64 ret=0;
		REP(i,SIZE(p))
		{
			int64 s=0;
			int k=i;
			for (;k<SIZE(p) && g[p[i]]==g[p[k]];k++) s+=a[p[k]];
			ret=gcd(ret,s);
			i=k-1;
		}
		cout<<ret<<endl;
	}
	return 0;
}