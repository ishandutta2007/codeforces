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

void discrete(VI& a)
{
	set<int> w;
	for (int x:a) w.insert(x);
	VI l(ALL(w));
	unordered_map<int,int> p;
	REP(i,SIZE(l)) p[l[i]]=i;
	REP(i,SIZE(a)) a[i]=p[a[i]];
}
int64 F2(int64 n)
{
	return n*(n+1)/2;
}
void update(VI& s,int p,int d)
{
	for (;p<SIZE(s);p=(p|(p-1))+1) s[p]+=d;
}
int sum(const VI& s,int p)
{
	int r=0;
	for (;p>0;p&=(p-1)) r+=s[p];
	return r;
}
int sum(const VI& s,int p1,int p2)
{
	if (p1>p2) return 0;
	return sum(s,p2)-sum(s,p1-1);
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
		VI x(n),y(n);
		REP(i,n) cin>>x[i]>>y[i];
		discrete(x);
		discrete(y);
		int64 ret=0;
		vector<VI> g(n);
		REP(i,n) g[y[i]].push_back(x[i]+1);
		VI w(n+1);
		VI s(n+1);
		for (int k=n-1;k>=0;k--) if (!g[k].empty())
		{
			auto& a=g[k];
			sort(ALL(a));
			ret-=F2(sum(s,1,a.front()-1));
			REP(i,SIZE(a)-1) ret-=F2(sum(s,a[i]+1,a[i+1]-1));
			ret-=F2(sum(s,a.back()+1,n));
			for (int p:a) if (!w[p]) { w[p]=1; update(s,p,1); }
			ret+=F2(sum(s,1,n));
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}