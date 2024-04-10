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

int eval(const VI& a)
{
	int r=0;
	FOR(i,1,SIZE(a)) if (a[i]==a[i-1]+1) ++r;
	return r;
}
VI op(const VI& a,const VI& d)
{
	int n=SIZE(a);
	int m=SIZE(d);
	VI s(m+1);
	REP(i,m) s[i+1]=s[i]+d[i];
	VI b;
	b.reserve(n);
	for (int i=m-1;i>=0;i--) FOR(j,s[i],s[i+1]) b.push_back(a[j]);
	return b;
}
void one_step(VI& a,vector<VI>& ret)
{
	int target=eval(a);
	int n=SIZE(a);

	auto f=[&](const VI& d) {
		VI b=op(a,d);
		if (eval(b)<=target) return 0;
		a=b;
		ret.push_back(d);
		return 1;
	};
	for (int l1=1;l1<n;l1++) if (f({l1,n-l1})) return;
	for (int l1=1;l1<n;l1++) for (int l2=1;l1+l2<n;l2++) if (f({l1,l2,n-l1-l2})) return;
	for (int l1=1;l1<n;l1++) for (int l2=1;l1+l2<n;l2++) for (int l3=1;l1+l2+l3<n;l3++) if (f({l1,l2,l3,n-l1-l2-l3})) return;
	printf("BAD\n");
}
int solve()
{
	int n;
	if (!(cin>>n)) return -1;
	VI a(n);
	REP(i,n) cin>>a[i];
	vector<VI> ret;
	while (eval(a)<n-1) one_step(a,ret);
	printf("%d\n",SIZE(ret));
	for (const auto& a:ret)
	{
		printf("%d",SIZE(a));
		for (int x:a) printf(" %d",x);
		printf("\n");
	}
	return 1;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (1)
	{
		if (solve()<0) break;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}