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

#define MOD (1000000007)

using ModType = int;
struct ModWrapper {
	static ModType value;
};
ModType ModWrapper::value = MOD;
ModType& mod_value = ModWrapper::value;

using Int = Modular<ModWrapper>;

const int maxsize=3000000+16;

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

	Polynomial mod_x_power_of_n(int n) const
	{
		if (size() <= n) return *this;
		return Polynomial(vector<T>(data.begin(), data.begin() + n));
	}

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
		const auto& a = p1.data;
		const auto& b = p2.data;
		int n = SIZE(a);
		int m = SIZE(b);
		vector<T> c(n + m - 1);
		for (int i = 0; i < n; ++i) if (a[i] != T(0)) for (int j = 0; j < m; ++j) c[i + j] += a[i] * b[j];
		return c;
	}
	static pair<Polynomial, Polynomial> div_and_mod(const Polynomial& pa, const Polynomial& pb)
	{
		int n = pa.degree();
		int m = pb.degree();
		if (n < m) return MP(Polynomial({T(0)}), pa);
		vector<T> a = pa.data;
		const vector<T>& b = pb.data;
		vector<T> div(n - m + 1);
		for (int k = n; k >= m; --k) if (a[k] != 0)
		{
			T e = a[k] / b[m];
			div[k - m] = e;
			for (int i = 0; i <= m; ++i) a[k - m + i] -= b[i] * e;
		}
		return make_pair(Polynomial(div), Polynomial(a));
	}
	friend Polynomial operator/(const Polynomial& p1, const Polynomial& p2) 
	{
		return div_and_mod(p1, p2).first;
	}
	friend Polynomial operator%(const Polynomial& p1, const Polynomial& p2)
	{
		return div_and_mod(p1, p2).second;
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
	prepare();
	int n,m;
	while (cin>>n>>m)
	{
		auto f=[&](int n) {
			vector<Int> a(n+1);
			REP(i,n+1) a[i]=choose(n,i);
			return Poly(a);
		};
		Poly r=(f(3)-f(3*(n+1)))/(f(0)-f(3));
		REP(cl,m)
		{
			int d;
			cin>>d;
			printf("%d\n",r.data[d].n);
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}