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

	friend istream& operator>>(istream &stream, IntMod &a) { stream >> a.n; return stream; }
	friend ostream& operator<<(ostream &stream, const IntMod &a) { stream << a.n; return stream; }
};
template<typename base_type, base_type _MOD> base_type IntMod<base_type, _MOD>::inverse_cache[INVERSE_CACHE_SIZE];
template<typename base_type, base_type _MOD> bool IntMod<base_type, _MOD>::inverse_cache_ready;
template<typename base_type, base_type _MOD> base_type IntMod<base_type, _MOD>::MOD = _MOD;

#define MOD (998244353)

using Int = IntMod<int, MOD>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		VI a(n);
		REP(i,n) { cin>>a[i]; --a[i]; }
		if (m<=8)
		{
			vector<vector<Int>> f(n+1,vector<Int>(two(m)));
			f[0][0]=1;
			REP(k,n)
			{
				int key=a[k];
				for (int i=k+1;i>=0;i--) 
				{
					for (int set=two(m)-2;set>=0;set--) if (contain(set,key)) { f[i][set]+=f[i][set]+f[i][set-two(key)]; }
					if (i>0) f[i][0]+=f[i-1][two(m)-1-two(key)];
				}
			}
			vector<Int> ret(n+1);
			REP(i,n+1) REP(set,two(m)) ret[i]+=f[i][set];
			ret[0]-=1;
			REP(i,n+1) printf("%d ",ret[i].n);
			printf("\n");
			continue;
		}
		vector<Int> p2(n+1);
		p2[0]=1;
		FOR(i,1,n+1) p2[i]=p2[i-1]*2;
		vector<vector<Int>> g(n+1,vector<Int>(n+1));
		vector<Int> h(n+1);
		REP(i,n+1)
		{
			VI c(m);
			int e=0;
			Int w=1;
			FOR(j,i,n)
			{
				int k=a[j];
				if (c[k]==0)
					++c[k],++e;
				else
					w/=p2[c[k]]-1,++c[k],w*=p2[c[k]]-1;
				if (e==m) g[i][j+1]+=w/(p2[c[k]]-1);
			}
			h[i]+=(p2[n-i]-(e==m?w:0));
		}
		vector<vector<Int>> f(n+1,vector<Int>(n+1));
		f[0][0]=1;
		REP(i,n)
		{
			int d=n;
			for (;d>=0 && f[i][d]==0;--d);
			FOR(j,i+1,n+1) if (g[i][j].n) REP(k,d+1) f[j][k+1]+=f[i][k]*g[i][j];
		}
		vector<Int> ret(n+1);
		REP(i,n+1) REP(j,n+1) ret[j]+=f[i][j]*h[i];
		ret[0]-=1;
		REP(i,n+1) printf("%d ",ret[i].n);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}