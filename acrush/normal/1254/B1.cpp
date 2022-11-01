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

template<class T> inline vector<pair<T,int> > factorize(T n)
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}

int64 solve(const VI& a,int64 m)
{
	int n=SIZE(a);
	int64 ret=0;

	int64 c1=0,s1=0;
	int64 c2=0,s2=0,key=-1;
	auto add=[&](int64 p,int64 c) {
		if (c==0) return;

		c1+=c;
		s1+=p*c;

		if (key<0)
			if (c2+c<=m/2)
				c2+=c,s2+=p*c;
			else
				key=p;

		if (c1==m)
		{
			ret+=key*c2-s2;
			ret+=(s1-s2)-key*(c1-c2);
			c1=s1=c2=s2=0;
			key=-1;
		}
	};
	REP(k,n)
	{
		int64 left=a[k]%m;
		int64 d=m-c1;
		if (left>=d) { left-=d; add(k,d); }
		add(k,left);
	}
	return ret;
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
		VI a(n);
		REP(i,n) cin>>a[i];
		int64 s=0;
		REP(i,n) s+=a[i];
		if (s<=1)
			cout<<-1<<endl;
		else
		{
			auto w=factorize(s);
			int64 ret=(1LL<<60);
			for (auto pw:w) ckmin(ret,solve(a,pw.first));
			cout<<ret<<endl;
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}