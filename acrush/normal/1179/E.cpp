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

const int MAXN=2048;
const int64 SIZE=1000000000LL*1000000000LL;

int n;
int64 L;
pair<int64,int64> ret[MAXN];
map<int64,int64> cache[MAXN];

#ifdef _MSC_VER
int num_queries=0;
#endif

int64 real_query(int idx,int64 pos)
{
#ifdef _MSC_VER
	++num_queries;
	return min(pos,L*n);
#endif
	printf("? %d %lld\n",idx+1,pos);
	fflush(stdout);
	int64 val;
	scanf("%lld",&val);
	return val;
}
int64 query(int idx,int64 pos)
{
	auto it=cache[idx].find(pos);
	if (it!=cache[idx].end()) return it->second;
	return cache[idx][pos]=real_query(idx,pos);
}
bool is_greator_or_equal(int idx,int64 pos,int64 limit)
{
	auto& w=cache[idx];
	if (!w.count(pos))
	{
		auto it=w.lower_bound(pos);
		if (it!=w.end())
		{
			if (it->second<limit) return false;
			if (it->second-abs(pos-it->first)>=limit) return true;
		}
		if (it!=w.begin()) 
		{
			--it;
			if (it->second>=limit) return true;
			if (it->second+abs(pos-it->first)<limit) return false;
		}
	}
	return query(idx,pos)>=limit;
}

void solve(int64 sx,int64 tx,int64 sL,int64 tL,VI a)
{
	assert(tL-sL==SIZE(a));
	if (tL-sL==1)
	{
		ret[a[0]]=MP(sx,tx);
		return;
	}
	int64 mL=(sL+tL)/2;
	int64 low=sx-1,high=tx;
	for (;low+1<high;)
	{
		int64 mid=(low+high)/2;
		int cnt=0;
		int left_cnt=SIZE(a);
		for (int idx:a) 
		{
			if (is_greator_or_equal(idx,mid,L*mL)) ++cnt;
			--left_cnt;
			if (cnt>=SIZE(a)/2) break;
			if (cnt+left_cnt<SIZE(a)/2) break;
		}
		// for (int idx:a) if (query(idx,mid)>=L*mL) ++cnt;
		if (cnt>=SIZE(a)/2)
			high=mid;
		else
			low=mid;
	}
	int64 mx=high;
	sort(ALL(a),[&](int idx1,int idx2) { return query(idx1,mx)>query(idx2,mx); });

	VI b,c;
	REP(i,SIZE(a)) 
		if (i<mL-sL) b.push_back(a[i]);
		else c.push_back(a[i]);
	solve(sx,mx,sL,mL,b);
	solve(mx,tx,mL,tL,c);
}
int main()
{
#ifdef _MSC_VER
	n=1000;
	L=SIZE;
#else
	scanf("%d%lld",&n,&L);
#endif
	L/=n;
	VI a;
	REP(i,n) a.push_back(i);
	solve(0,SIZE,0,n,a);
	random_shuffle(ALL(a));
	printf("!\n");
	REP(i,n) printf("%lld %lld\n",ret[i].first,ret[i].second);
	fflush(stdout);
#ifdef _MSC_VER
	printf("num_queries = %d\n",num_queries);
#endif
	return 0;
}