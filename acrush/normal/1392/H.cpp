#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

template<typename ModWrapper>
class Modular
{
public:
	using base_type = typename decay<decltype(ModWrapper::value)>::type;

	base_type n;

	Modular(long long d = 0) { n = (d >= 0 ? d % mod() : (d % mod() + mod()) % mod()); }

	static base_type mod() { return ModWrapper::value; }
	base_type val() const { return n; }

	Modular operator-() const { return build(n == 0 ? 0 : mod() - n); }
	Modular& operator+=(Modular a) { n = (n >= mod() - a.n ? n - mod() + a.n : n + a.n); return *this; }
	Modular& operator-=(Modular a) { n = (n >= a.n) ? n - a.n : n - a.n + mod(); return *this; }
	Modular& operator*=(Modular a) { *this = *this * a; return *this; }
	Modular& operator/=(Modular a) { *this = *this / a; return *this; }

	static Modular build(base_type n) { Modular r; r.n = n; return r; }

	friend Modular inverse(Modular n) { return build(inverse_internal(n.n)); }
	friend bool operator==(Modular a, Modular b) { return a.n == b.n; }
	friend bool operator!=(Modular a, Modular b) { return a.n != b.n; }
	friend Modular operator+(Modular a, Modular b) { return build(a.n >= mod() - b.n ? a.n - mod() + b.n : a.n + b.n); }
	friend Modular operator-(Modular a, Modular b) { return build(a.n >= b.n ? a.n - b.n : a.n - b.n + mod()); }
	friend Modular operator*(Modular a, Modular b) { return build(static_cast<base_type>(static_cast<long long>(a.n)* b.n% mod())); }
	friend Modular operator/(Modular a, Modular b) { return a * inverse(b); }
	friend Modular pow(Modular p, long long e)
	{
		if (e <= 0) return Modular(1);
		Modular r = Modular(1);
		while (1) { if (e & 1) r *= p; e /= 2; if (e) p = p * p; else break; }
		return r;
	}

	friend istream& operator>>(istream& stream, Modular& a) { stream >> a.n; return stream; }
	friend ostream& operator<<(ostream& stream, const Modular& a) { stream << a.n; return stream; }

private:
	static constexpr int INVERSE_CACHE_SIZE = (1 << 20);
	static base_type inverse_cache[INVERSE_CACHE_SIZE];
	static base_type inverse_cache_mod_value;
	static base_type inverse_internal(base_type n)
	{
		if (inverse_cache_mod_value != mod())
		{
			inverse_cache_mod_value = mod();
			inverse_cache[0] = 0;
			inverse_cache[1] = 1;
			for (int n = 2; n < INVERSE_CACHE_SIZE; ++n) inverse_cache[n] = (mod() - (base_type)((long long)inverse_cache[mod() % n] * (mod() / n) % mod()));
		}
		return n < INVERSE_CACHE_SIZE ? inverse_cache[n] : inverse_internal_large(n);
	}
	static base_type inverse_internal_large(base_type n)
	{
		return n < INVERSE_CACHE_SIZE ? inverse_cache[n] : mod() - (base_type)((long long)inverse_internal_large(mod() % n) * (mod() / n) % mod());
	}
};
template<typename ModWrapper> typename decay<decltype(ModWrapper::value)>::type Modular<ModWrapper>::inverse_cache[INVERSE_CACHE_SIZE];
template<typename ModWrapper> typename decay<decltype(ModWrapper::value)>::type Modular<ModWrapper>::inverse_cache_mod_value = -1;

#define MOD (998244353)

using ModType = int;
struct ModWrapper {
	static ModType value;
};
ModType ModWrapper::value = MOD;
ModType& mod_value = ModWrapper::value;

using Int = Modular<ModWrapper>;

const int maxsize=5000000;

Int permutation[maxsize];
Int permutation_inv[maxsize];

Int choose(int n,int m)
{
	return (m<0 || m>n?0:permutation[n]*permutation_inv[m]*permutation_inv[n-m]);
}
void prepare()
{
	permutation[0]=permutation_inv[0]=1;
	FOR(i,1,maxsize)
	{
		permutation[i]=permutation[i-1]*i;
		permutation_inv[i]=permutation_inv[i-1]/i;
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	prepare();
	int n,m;
	while (cin>>n>>m)
	{
		Int s=0;
		Int ps=0;
		FOR(k,1,n+1)
		{
			s=ps*choose(n+m,k+m)+choose(m+k+1,m+1)*choose(n+m+1,m+k+1)*permutation[m-1];
			s*=permutation[k]*permutation[n-k]*Int(m)*permutation_inv[n+m]*Int(m+k)/Int(k);
			ps+=permutation[m+k-1]*s*permutation_inv[k];			
		}
		printf("%d\n",s.n);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}