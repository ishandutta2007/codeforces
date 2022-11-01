#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

template<typename base_type, base_type _MOD>
class IntMod
{
public:
	static const int INVERSE_CACHE_SIZE = (1 << 20);
	static base_type MOD;
	static void set_mod(base_type new_mod) { MOD = new_mod; }

	base_type n;

	IntMod(base_type d = 0) { n = (d >= 0 ? d % MOD : (d % MOD + MOD) % MOD); }
	virtual ~IntMod() = default;

	IntMod operator-() const { return Build(n == 0 ? 0 : MOD - n); }
	IntMod& operator+=(IntMod a) { n = (n >= MOD - a.n ? n - MOD + a.n : n + a.n); return *this; }
	IntMod& operator-=(IntMod a) { n = (n >= a.n) ? n - a.n : n - a.n + MOD; return *this; }
	IntMod& operator*=(IntMod a) { *this = *this * a; return *this; }
	IntMod& operator/=(IntMod a) { *this = *this / a; return *this; }

	static IntMod build(base_type n) { IntMod r; r.n = n; return r; }

	static base_type inverse_cache[INVERSE_CACHE_SIZE];
	static bool inverse_cache_ready;
	friend IntMod inverse(IntMod n) { return build(inverse_internal(n.n)); }
	static base_type inverse_internal(base_type n)
	{
		if (!inverse_cache_ready) 
		{
			inverse_cache_ready=true;
			inverse_cache[0] = 0;
			inverse_cache[1] = 1;
			for (int n = 2; n < INVERSE_CACHE_SIZE; ++n) inverse_cache[n] = (MOD - (base_type)((long long)inverse_cache[MOD % n] * (MOD / n) % MOD));
		}
		return n < INVERSE_CACHE_SIZE ? inverse_cache[n] : MOD - (base_type)((long long)inverse_internal(MOD % n) * (MOD / n) % MOD);
	}

	friend bool operator==(IntMod a, IntMod b) { return a.n == b.n; }
	friend bool operator!=(IntMod a, IntMod b) { return a.n != b.n; }
	friend IntMod operator+(IntMod a, IntMod b) { return build(a.n >= MOD - b.n ? a.n - MOD + b.n : a.n + b.n); }
	friend IntMod operator-(IntMod a, IntMod b) { return build(a.n >= b.n ? a.n - b.n : a.n - b.n + MOD); }
	friend IntMod operator*(IntMod a, IntMod b) { return build(static_cast<base_type>(static_cast<long long>(a.n) * b.n % MOD)); }
	friend IntMod operator/(IntMod a, IntMod b) { return a * inverse(b); }
	friend IntMod pow(IntMod p, long long e)
	{
		if (e <= 0) return IntMod(1);
		IntMod r = IntMod(1);
		while (1) { if (e & 1) r *= p; e /= 2; if (e) p = p * p; else break; }
		return r;
	}
};
template<typename base_type, base_type _MOD> base_type IntMod<base_type, _MOD>::inverse_cache[INVERSE_CACHE_SIZE];
template<typename base_type, base_type _MOD> bool IntMod<base_type, _MOD>::inverse_cache_ready;
template<typename base_type, base_type _MOD> base_type IntMod<base_type, _MOD>::MOD = _MOD;

using Int = IntMod<int, 1000000007>;

const int maxsize=(1<<20);

int n;
int c[maxsize];
int length;
int n1,n2;
ipair a1[maxsize],a2[maxsize];
Int f1[maxsize],f2[maxsize];
int next1[maxsize],next2[maxsize];

void readin()
{
	cin>>length>>n1>>n2;
	REP(i,n1) { cin>>a1[i].first>>a1[i].second; --a1[i].first; }
	REP(i,n2) { cin>>a2[i].first>>a2[i].second; --a2[i].first; }
}
void prepare(int& n,ipair a[])
{
	sort(a,a+n,[](ipair a,ipair b) { return a.second<b.second || a.second==b.second && a.first>b.first; });
	int m=0;
	REP(i,n) if (m==0 || a[i].first>a[m-1].first) a[m++]=a[i];
	n=m;
}
void preprocess()
{
	set<int> pts;
	pts.insert(0);
	pts.insert(length);
	REP(i,n1) { pts.insert(a1[i].first); pts.insert(a1[i].second); }
	REP(i,n2) { pts.insert(a2[i].first); pts.insert(a2[i].second); }
	vector<int> lst(ALL(pts));
	n=SIZE(lst)-1;
	REP(i,n) c[i]=lst[i+1]-lst[i];
	map<int,int> mp;
	REP(i,n+1) mp[lst[i]]=i;
	REP(i,n1) a1[i].first=mp[a1[i].first],a1[i].second=mp[a1[i].second]-1;
	REP(i,n2) a2[i].first=mp[a2[i].first],a2[i].second=mp[a2[i].second]-1;
	for (int k=0,i=0;i<=n;i++)
	{
		for (;k<n1 && i>a1[k].first;++k);
		next1[i]=k;
	}
	for (int k=0,i=0;i<=n;i++)
	{
		for (;k<n2 && i>a2[k].first;++k);
		next2[i]=k;
	}
}
int solve()
{
	REP(i,n2+1) f1[i]=0;
	REP(i,n1+1) f2[i]=0;
	f1[0]=1;
	Int sf1=1;
	Int sf2=0;
	int p1=0,p2=0;
	REP(k,n)
	{
		Int c_both=pow(Int(2),c[k])-2;
		Int h1=0;
		Int h2=0;
		if (next1[k]==n1 || a1[next1[k]].second>k) h1=sf1;
		Int w1=sf1*c_both;
		if (next2[k]==n2 || a2[next2[k]].second>k) h2=sf2;
		Int w2=sf2*c_both;
		for (;p1<n1 && a1[p1].second<=k;++p1) sf2-=f2[p1],f2[p1]=0;
		for (;p2<n2 && a2[p2].second<=k;++p2) sf1-=f1[p2],f1[p2]=0;
		sf2+=h1;
		f2[next1[k]]+=h1;
		sf1+=h2;
		f1[next2[k]]+=h2;
		sf1+=w1;
		f1[next2[k+1]]+=w1;
		sf2+=w2;
		f2[next1[k+1]]+=w2;
	}
	Int ret=f1[n2]+f2[n1];
	return ret.n;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	readin();
	prepare(n1,a1);
	prepare(n2,a2);
	preprocess();
	int ret=solve();
	printf("%d\n",ret);
	return 0;
}