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

int64 gcd(int64 a,int64 b)
{
	return b?gcd(b,a%b):a;
}
void solve(vector<int64> a)
{
	int n=SIZE(a);
	sort(ALL(a));
	if (a[0]==0 && a[n-1]==0) { printf("0\n"); return; }
	int64 px=0;
	FOR(i,1,n) px+=a[0]+a[i];
	if (px>0) { printf("INF\n"); return; }
	int64 py=0;
	REP(i,n-1) py+=a[n-1]+a[i];
	if (py<0) { printf("INF\n"); return; }
	int64 ret=-2e18;
	if (px==0) 
	{
		int64 sx=0;
		FOR(i,1,n) sx+=a[0]*a[i];
		ckmax(ret,sx);
	}
	if (py==0)
	{
		int64 sy=0;
		REP(i,n-1) sy+=a[n-1]*a[i];
		ckmax(ret,sy);
	}
	vector<int64> sa(n+1);
	REP(i,n) sa[i+1]=sa[i]+a[i];
	REP(k,n-1)
	{
		int64 min_t=-2e18;
		int64 max_t=2e18;
		int64 s=a[0]*a[n-1];
		int64 w=a[0]+a[n-1];
		s+=a[n-1]*(sa[k+1]-sa[1]);
		w+=a[n-1]*k+(sa[k+1]-sa[1]);
		s+=a[0]*(sa[n-1]-sa[k+1]);
		w+=a[0]*(n-2-k)+(sa[n-1]-sa[k+1]);
		if (k>=1) ckmin(max_t,a[k]*a[0]-a[k]*a[n-1]);
		if (k+1<=n-2) ckmax(min_t,a[k+1]*a[0]-a[k+1]*a[n-1]);
		if (w!=0)
		{
			int64 c=a[n-1]-a[0];
			int64 d=gcd(w,c);
			if (w>=0)
				s+=(max_t/(c/d))*(w/d);
			else
				s+=(min_t/(c/d))*(w/d);
		}
		ckmax(ret,s);
	}
	printf("%lld\n",ret);
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
		int n;
		cin>>n;
		vector<int64> a(n);
		REP(i,n) cin>>a[i];
		solve(a);
	}
	return 0;
}