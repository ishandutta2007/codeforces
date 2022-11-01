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

int64 countbit(int64 n)
{
	return (n==0?0:countbit(n&(n-1))+1);
}
int64 brute_force(vector<int64> a)
{
	int n=SIZE(a);
	sort(ALL(a));
	int64 r=n*100;
	for (int64 m=a[n-1];m<=a[n-1]*4;m++)
	{
		int64 s=0;
		for (int64 p:a) s+=countbit(m-p);
		ckmin(r,s);
	}
	return r;
}

int eval(const vector<int64>& a,int64 now,int64 w)
{
	int cost=0;
	if (now>=w)
	{
		cost+=upper_bound(ALL(a),now-w)-a.begin();
	}
	{
		auto it=upper_bound(ALL(a),now);
		auto it2=upper_bound(ALL(a),now+w);
		cost+=it2-it;
	}
	return cost;
}
int64 solve(vector<int64> a)
{
	VI f;
	vector<int64> d;
	f.push_back(0);
	d.push_back(0);
	d.push_back(1);
	int64 mask=1;
	int n=SIZE(a);
	REP(bits,62)
	{
		int64 w=twoL(bits);
		mask|=w;
		vector<int64> new_d;
		new_d.reserve(n+2);
		new_d.push_back(0);
		new_d.push_back(mask+1);
		REP(i,n) new_d.push_back(a[i]&mask);
		sort(ALL(new_d));
		new_d.resize(unique(ALL(new_d))-new_d.begin());
		int m=SIZE(new_d)-1;
		VI new_f(m,1000000000);
		vector<int64> sorted_masks(n);
		REP(i,n) sorted_masks[i]=(a[i]&mask);
		sort(ALL(sorted_masks));
		REP(i,SIZE(f)) REP(b,2)
		{
			int64 now=d[i];
			if (b) now+=twoL(bits);
			int cost=f[i];
			cost+=eval(sorted_masks,now,w);
			ckmin(new_f[upper_bound(ALL(new_d),now)-new_d.begin()-1],cost);
		}
		f=std::move(new_f);
		d=std::move(new_d);
	}
	return f.back();
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
		vector<int64> a(n);
		REP(i,n) cin>>a[i];
		cout<<solve(a)<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}