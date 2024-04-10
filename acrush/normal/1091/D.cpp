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

using Int = IntMod<int,998244353>;

const int maxsize=(1<<20);

Int permutation[maxsize];
Int permutation_inv[maxsize];

Int choose(int n,int m)
{
	if (m<0 || m>n) return 0;
	return permutation[n]*permutation_inv[m]*permutation_inv[n-m];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	permutation[0]=permutation_inv[0]=1;
	FOR(i,1,maxsize) permutation[i]=permutation[i-1]*i,permutation_inv[i]=permutation_inv[i-1]/i;
	int n;
	while (cin>>n)
	{
		Int ret=permutation[n];
		FOR(k,2,n+1)
		{
			ret+=choose(n,k)*(k-1)*permutation[n-k]*(n-k);
		}
		printf("%d\n",ret.n);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}