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

	IntMod(long long d = 0) { n = (d >= 0 ? d % MOD : (d % MOD + MOD) % MOD); }
	virtual ~IntMod() = default;

	IntMod operator-() const { return build(n == 0 ? 0 : MOD - n); }
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

const int MOD=1000000007;

using Int = IntMod<int,MOD>;

const int maxn=200000+16;

int n,m;
vector<int> g[maxn];
int s[maxn];
vector<Int> f[maxn];
Int pow2[maxn];
Int permutation[maxn],permutation_inv[maxn];
vector<Int> sum;

Int choose(int n,int m)
{
	if (m<0 || m>n) return 0;
	return permutation[n]*permutation_inv[m]*permutation_inv[n-m];
}
void dfs(int p,int prev)
{
	vector<int> c;
	for (int x:g[p]) if (x!=prev) { c.push_back(x); dfs(x,p); }
	sort(ALL(c),[](int a,int b) { return s[a]>s[b]; });
	s[p]=1;
	for (int x:c) s[p]+=s[x];
	Int f0=1;
	int size=min(m,s[p])+1;
	vector<Int> f1(size);
	vector<Int> f2(size);
	for (int x:c)
	{
		Int new_f0=f0*pow2[s[x]];
		vector<Int> new_f1(size);
		vector<Int> new_f2(size);
		const vector<Int>& h=f[x];
		REP(i,SIZE(new_f1)) new_f1[i]+=f1[i]*pow2[s[x]];
		FOR(i,1,SIZE(h)) if (h[i].n) new_f1[i]+=f0*h[i];
		REP(i,SIZE(new_f2)) new_f2[i]+=f2[i]*pow2[s[x]];

		vector<int> a(SIZE(h));
		vector<int> b(size);
		REP(i,SIZE(h)) a[i]=h[i].n;
		REP(i,size) b[i]=(f1[i]+f2[i]).n;
		for (;SIZE(a)>0 && a.back()==0;a.pop_back());
		for (;SIZE(b)>0 && b.back()==0;b.pop_back());
		int n1=SIZE(a),n2=SIZE(b);
		REP(i,size)
		{
			int m1=max(0,i-(n2-1));
			int m2=min(n1-1,i);
			int64 s=0;
			for (int j=m1;j<=m2;j++) 
			{
				s+=(int64)a[j]*b[i-j];
				if (j%8==0) s%=MOD;
			}
			new_f2[i]+=s;
		}
		// FOR(i,1,SIZE(h)) if (h[i].n) REP(j,size-i) new_f2[i+j]+=(f1[j]+f2[j])*h[i];
		f0=new_f0;
		f1.swap(new_f1);
		f2.swap(new_f2);
	}
	if (prev>=0)
	{
		sum[1]+=(pow2[n-s[p]]-1)*(pow2[s[p]]-1);
		for (int x:c) 
		{
			const vector<Int>& h=f[x];
			FOR(i,1,SIZE(h)) if (i+1<=m && h[i].n)
				sum[i+1]+=h[i]*(pow2[n-s[p]]-1)*pow2[s[p]-s[x]];
		}
		FOR(i,1,size) if (i+1<=m && f2[i].n)
			sum[i+1]+=f2[i]*(pow2[n-s[p]]-1)*2;
	}
	FOR(i,1,size) if (f2[i].n)
		sum[i]+=f2[i]*pow2[n-s[p]+1];
	f[p].clear();
	f[p].resize(size);
	REP(i,size) f[p][i]+=(f1[i]+f2[i])*2;
	if (prev>=0)
	{
		f[p][1]+=pow2[s[p]]-1;
		FOR(i,1,size-1) f[p][i+1]+=(f1[i]+f2[i])*2;
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	pow2[0]=permutation[0]=permutation_inv[0]=1;
	FOR(i,1,maxn)
	{
		pow2[i]=pow2[i-1]*2;
		permutation[i]=permutation[i-1]*i;
		permutation_inv[i]=permutation_inv[i-1]/i;
	}
	while (cin>>n>>m)
	{
		REP(i,n) g[i].clear();
		REP(i,n) f[i].clear();
		REP(i,n-1)
		{
			int a,b;
			cin>>a>>b; --a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		sum=vector<Int>(m+1);
		dfs(0,-1);
		Int ret=0;
		vector<Int> cnt(m+1);
		cnt[0]=1;
		FOR(k,1,m+1)
		{
			vector<Int> cnt2(m+1);
			REP(i,m+1) FOR(j,1,m-i+1) cnt2[i+j]+=cnt[i]*permutation_inv[j];
			cnt.swap(cnt2);
			ret+=sum[k]*cnt[m];
		}
		ret*=permutation[m];
		printf("%d\n",ret.n);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}