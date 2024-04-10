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
using VI=vector<int>;

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

#define MOD (998244353)
using Int=IntMod<int,MOD>;

template<class T> class Polynomial
{
public:
	explicit Polynomial(vector<T> a = {0}) : data(std::move(a)) 
	{
		while (SIZE(data) > 1 && data.back() == 0) data.pop_back();
		if (data.empty()) data.push_back(0);
	}

	int degree() const { return static_cast<int>(SIZE(data)) - 1; }
	int size() const { return static_cast<int>(SIZE(data)); }

	Polynomial operator-() const 
	{
		int n = size();
		vector<T> a(n);
		REP(i, n) a[i] = -data[i];
		return Polynomial(a);
	}
	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2) 
	{
		const auto* a = &p1.data;
		const auto* b = &p2.data;
		if (a->size() < b->size()) swap(a, b);
		vector<T> c = *a;
		int m = b->size();
		for (int i = 0; i < m; ++i) c[i] += (*b)[i];
		return Polynomial(c);
	}
	friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2) 
	{
		int n = p1.size();
		int m = p2.size();
		vector<T> c(max(n, m) + 1);
		for (int i = 0; i < n; ++i) c[i] = p1.data[i];
		for (int i = 0; i < m; ++i) c[i] -= p2.data[i];
		return Polynomial(c);
	}
	friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2) 
	{
		const auto* a = &p1.data;
		const auto* b = &p2.data;
		if (a->size() > b->size()) swap(a, b);
		int n = static_cast<int>(a->size());
		int m = static_cast<int>(b->size());
		vector<T> c(n + m - 1);
		for (int i = 0; i < n; ++i) if ((*a)[i] != 0) for (int j = 0; j < m; ++j) c[i + j] += (*a)[i] * (*b)[j];
		return Polynomial(c);
	}
	vector<T> data;
};
using Poly = Polynomial<Int>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int m,n;
	while (cin>>m>>n)
	{
		VI a(m);
		REP(i,m) cin>>a[i];
		VI w(m);
		REP(i,m) cin>>w[i];
		int s0=0,s1=0;
		REP(i,m) if (a[i]) s0+=w[i]; else s1+=w[i];
		vector<Int> f(1);
		f[0]=1;
		REP(c,n)
		{
			vector<Int> g(c+2);
			REP(c0,c+1) if (f[c0].n)
			{
				int c1=c-c0;
				Int p0=Int(s0+c0)/Int(s0+s1+c0-c1);
				Int p1=1-p0;
				if (p0.n) g[c0+1]+=f[c0]*p0;
				if (p1.n) g[c0]+=f[c0]*p1;
			}
			f=std::move(g);
		}
		vector<Int> h(n+1);
		h[0]=1;
		vector<Int> ret(m);
		REP(c0,n+1) if (f[c0].n)
		{
			for (int i=c0;i>0;i--) h[i]+=h[i-1]*(s0+c0);
			REP(key,m)
				if (a[key]==1)
				{
					vector<Int> z(1);
					z[0]=f[c0];
					REP(step,c0)
					{
						vector<Int> z2(step+2);
						REP(i,step+1) if (z[i].n)
						{
							z2[i]+=z[i]*(s0-w[key]+(step-i));
							z2[i+1]+=z[i]*(w[key]+i);
						}
						z=std::move(z2);
						REP(i,SIZE(z)) z[i]/=(s0+step);
					}
					REP(i,c0+1) ret[key]+=(w[key]+i)*z[i];
				}
				else
				{
					vector<Int> z(1);
					z[0]=f[c0];
					REP(step,n-c0)
					{
						vector<Int> z2(step+2);
						REP(i,step+1) if (z[i].n)
						{
							z2[i]+=z[i]*(s1-w[key]-(step-i));
							z2[i+1]+=z[i]*(w[key]-i);
						}
						z=std::move(z2);
						REP(i,SIZE(z)) z[i]/=(s1-step);
					}
					REP(i,n-c0+1) ret[key]+=(w[key]-i)*z[i];
				}
		}
		REP(i,m) printf("%d\n",ret[i].n);
#ifndef _MSC_VER
		break;
#else
		printf("\n");
#endif
	}
	return 0;
}