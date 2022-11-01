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

const int maxn=(1<<20);
const int MOD=1000000007;

template<typename base_type, base_type _MOD>
class IntMod
{
public:
	static const int INVERSE_CACHE_SIZE = (1 << 20);
	static base_type MOD;
	static void set_mod(base_type new_mod) { MOD = new_mod; }

	base_type n;

	IntMod(long long d = 0) { n = (d >= 0 ? d % MOD : (d % MOD + MOD) % MOD); }
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

	friend istream& operator>>(istream &stream, IntMod &a) { stream >> a.n; return stream; }
	friend ostream& operator<<(ostream &stream, const IntMod &a) { stream << a.n; return stream; }
};
template<typename base_type, base_type _MOD> base_type IntMod<base_type, _MOD>::inverse_cache[INVERSE_CACHE_SIZE];
template<typename base_type, base_type _MOD> bool IntMod<base_type, _MOD>::inverse_cache_ready;
template<typename base_type, base_type _MOD> base_type IntMod<base_type, _MOD>::MOD = _MOD;

using Int = IntMod<int, MOD>;

int n;
int a[maxn],w[maxn];
Int sw[maxn],swa[maxn];
int64 sw2[maxn];

void update_sa(Int s[],int p,Int delta)
{
	for (++p;p<=n;p=(p|(p-1))+1) s[p]+=delta;
}
Int get_sa(Int s[],int p)
{
	Int r=0;
	for (;p>0;p&=(p-1)) r+=s[p];
	return r;
}
Int calc(Int s[],int a,int b)
{
	if (a>b) return 0;
	return get_sa(s,b+1)-get_sa(s,a);
}
void update_sa2(int64 s[],int p,int64 delta)
{
	for (++p;p<=n;p=(p|(p-1))+1) s[p]+=delta;
}
int64 get_sa2(int64 s[],int p)
{
	int64 r=0;
	for (;p>0;p&=(p-1)) r+=s[p];
	return r;
}
int64 calc2(int64 s[],int a,int b)
{
	if (a>b) return 0;
	return get_sa2(s,b+1)-get_sa2(s,a);
}
void update_weight(int id,int new_w)
{
	Int delta=new_w-w[id];
	update_sa(sw,id,delta);
	update_sa(swa,id,delta*a[id]);
	update_sa2(sw2,id,new_w-w[id]);
	w[id]=new_w;
}
int query(int s,int t)
{
	int low=s,high=t,m;
	while (1)
	{
		m=(low+high)/2;
		int64 s1=calc2(sw2,s,m-1);
		int64 s2=calc2(sw2,m+1,t);
		if (s1+w[m]<s2) { low=m+1; continue; }
		if (s2+w[m]<s1) { high=m-1; continue; }
		break;
	}
	Int ret=0;
	ret+=calc(sw,s,m)*a[m];
	ret-=calc(swa,s,m);
	ret+=calc(swa,m+1,t);
	ret-=calc(sw,m+1,t)*a[m];
	return ret.n;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int nq;
	while (cin>>n>>nq)
	{
		REP(i,n) cin>>a[i];
		REP(i,n) cin>>w[i];
		REP(i,n) a[i]-=i;
		REP(i,n+1) sw[i]=swa[i]=0;
		REP(i,n+1) sw2[i]=0;
		REP(i,n) update_sa(sw,i,w[i]);
		REP(i,n) update_sa(swa,i,(int64)w[i]*a[i]%MOD);
		REP(i,n) update_sa2(sw2,i,w[i]);
		REP(cl,nq)
		{
			int x,y;
			cin>>x>>y;
			if (x<0)
				update_weight(-x-1,y);
			else
			{
				int r=query(x-1,y-1);
				printf("%d\n",r);
			}
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}