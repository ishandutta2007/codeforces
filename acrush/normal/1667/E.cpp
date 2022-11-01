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

	constexpr Modular() : n(0) {}

	template<typename U>
	Modular(U m) { 
		if (m >= 0 && m < mod()) { n = static_cast<base_type>(m);
		} else { n = static_cast<base_type>(m % mod()); if (n < 0) n += mod(); }
	}

	constexpr static base_type mod() { return ModWrapper::value; }
	base_type val() const { return n; }

	Modular operator-() const { return build(n == 0 ? 0 : mod() - n); }
	Modular& operator+=(Modular a) { n = (n >= mod() - a.n ? n - mod() + a.n : n + a.n); return *this; }
	Modular& operator-=(Modular a) { n = (n >= a.n) ? n - a.n : n - a.n + mod(); return *this; }
	Modular& operator*=(Modular a) { *this = *this * a; return *this; }
	Modular& operator/=(Modular a) { *this = *this / a; return *this; }
	Modular& operator++() { return *this += 1; }
	Modular& operator--() { return *this -= 1; }
	Modular operator++(int) { Modular result(*this); *this += 1; return result; }
	Modular operator--(int) { Modular result(*this); *this -= 1; return result; }

	static Modular build(base_type n) { Modular r; r.n = n; return r; }

	friend Modular inverse(Modular n) { return build(inverse_internal(n.n)); }
	friend bool operator==(Modular a, Modular b) { return a.n == b.n; }
	friend bool operator!=(Modular a, Modular b) { return !(a.n == b.n); }
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
	static constexpr int INVERSE_CACHE_SIZE = (1 << 18);
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

const int maxsize=2000000;

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

struct Params
{
	int mod;  // mod is prime and mod = (2^e * x) + 1
	int e;
	int g;  // g^(2^e) = 1
	int g_inv;
};

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

int mod_inv(int m, int x)
{
	return (x <= 1) ? x : (m - (int64_t)(m / x) * mod_inv(m, m % x) % m);
}

Params get_params(int mod)
{
	int e = 0;
	for (int x = mod - 1; x % 2 == 0; x /= 2) ++e;
	int g = 2;
	for (;; ++g)
	{
		bool ok = false;
		int w = g;
		for (int i = 1; i <= e; ++i) { w = ((int64_t)w * w) % mod; if (w == 1) { ok = (i == e); break; } }
		if (ok) break;
	}
	int g_inv = mod_inv(mod, g);
	return { mod, e, g, g_inv };
}

pair<int64_t, int64_t> mod_equation(int64_t m1, int64_t x1, int64_t m2, int64_t x2)
{
	int64_t g = gcd(m1, m2);
	if (x1 % g != x2 % g) return make_pair(-1, -1);
	int64_t tmp = x1 % g;
	m1 /= g; x1 /= g; m2 /= g; x2 /= g;
	return make_pair(m1 * m2 * g, ((m2 == 1) ? x1 : ((x2 - x1 % m2 + m2) % m2 * mod_inv(m2, m1 % m2) % m2 * m1 + x1)) * g + tmp);
}

void DFT(vector<int>& a, int mod, int g, int w)
{
	int gg[64];
	gg[w] = g;
	for (int i = w - 1; i >= 0; i--) gg[i] = (int64_t)gg[i + 1] * gg[i + 1] % mod;
	int n = a.size();
	int e = 0;
	for (; n != (1 << e); e++);
	vector<int> bitrev(n);
	bitrev[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (e - 1));
		if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	}
	for (int logt = 0, t = 1; t < n; ++logt, t *= 2)
	{
		for (int p = gg[logt + 1], i = 0; i < n; i += 2 * t)
		{
			int power = 1;
			int* l = &a[i];
			int* r = &a[i + t];
			for (int j = 0; j < t; ++j)
			{
				int z = (int64_t)*r * power % mod;
				*r = (*l >= z ? *l - z : *l - z + mod);
				*l = (*l >= mod - z ? *l - mod + z : *l + z);
				++l;
				++r;
				power = (int64_t)power * p % mod;
			}
		}
	}
}

vector<int64_t> convolution_brute_force(vector<int64_t> a, vector<int64_t> b, int mod)
{
	int n = a.size();
	for (int i = 0; i < n; ++i) { a[i] %= mod; if (a[i] < 0) a[i] += mod; }
	int m = b.size();
	for (int i = 0; i < m; ++i) { b[i] %= mod; if (b[i] < 0) b[i] += mod; }
	vector<int64_t> c(n + m - 1);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) { c[i + j] += a[i] * b[j]; c[i + j] %= mod; }
	return c;
}

vector<int64_t> convolution_with_params(const vector<int64_t>& x, const vector<int64_t>& y, const Params& params)
{
	if (x.empty() || y.empty()) return {};
	if (x.size() <= 32 && y.size() <= 32) return convolution_brute_force(x, y, params.mod);
	const int64_t mod = params.mod;
	int m = x.size() + y.size() - 1;
	int n = m;
	for (; n & (n - 1); ++n);
	vector<int> a(n);
	for (int i = 0; i < x.size(); ++i) a[i] = (x[i] % mod + mod) % mod;
	DFT(a, mod, params.g, params.e);
	if (x == y)
	{
		for (int i = 0; i < n; ++i) a[i] = (int64_t)a[i] * a[i] % mod;
	}
	else
	{
		vector<int> b(n);
		for (int i = 0; i < y.size(); ++i) b[i] = (y[i] % mod + mod) % mod;
		DFT(b, mod, params.g, params.e);
		for (int i = 0; i < n; ++i) a[i] = (int64_t)a[i] * b[i] % mod;
	}
	DFT(a, mod, params.g_inv, params.e);
	int64_t n_inv = 0;
	for (int64_t tmp = 1;; tmp += mod) if (tmp % n == 0) { n_inv = tmp / n; break; }
	vector<int64_t> z(m);
	for (int i = 0; i < z.size(); ++i) z[i] = (int64_t)a[i] * n_inv % mod;
	return z;
}

vector<Int> convolution(const vector<Int>& x, const vector<Int>& y)
{
	Params params = get_params(MOD);
	vector<int64_t> a, b;
	REP(i,SIZE(x)) a.push_back(x[i].n);
	REP(i,SIZE(y)) b.push_back(y[i].n);
	auto c = convolution_with_params(a, b, params);
	vector<Int> z(SIZE(c));
	REP(i,SIZE(c)) z[i]=c[i];
	return z;
}

void solve(int n)
{
	vector<Int> g(n+1);
	FOR(i,1,n+1) g[i]=permutation[i-1];
	vector<Int> r(n);
	int m=(n-1)/2;
	vector<Int> f1(n);
	vector<Int> f2(n);

	REP(c,n) f1[c]=permutation_inv[c];
	REP(c,n-m-1) f2[c]=g[n-1-c];
	vector<Int> f3=convolution(f1,f2);

	vector<Int> f4(n);
	FOR(c,m+1,n) f4[c]=permutation_inv[c]*g[c]*g[n-c];
	vector<Int> f5(n);
	REP(i,n) f5[i]=permutation_inv[i];
	vector<Int> f6=convolution(f4,f5);

	REP(k,m+1)
	{
		Int& ret=r[k];
		ret=g[n];
		if (k>0) ret-=f3[n-k-1]*permutation[n-k-1]*k;
		if (m+1<n-k) ret-=f6[n-k-1]*permutation[n-k-1];
	}
	REP(i,n) printf("%d ",r[i].n); printf("\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	prepare();
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		solve(n);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}