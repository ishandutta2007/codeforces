#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct GModInt {
	static int Mod;
	unsigned x;
	GModInt() : x(0) { }
	GModInt(signed sig) { int sigt = sig % Mod; if (sigt < 0) sigt += Mod; x = sigt; }
	GModInt(signed long long sig) { int sigt = sig % Mod; if (sigt < 0) sigt += Mod; x = sigt; }
	int get() const { return (int)x; }

	GModInt &operator+=(GModInt that) { if ((x += that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator-=(GModInt that) { if ((x += Mod - that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }
	GModInt &operator/=(GModInt that) { return *this *= that.inverse(); }

	GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
	GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
	GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
	GModInt operator/(GModInt that) const { return GModInt(*this) /= that; }

	//Mod
	GModInt inverse() const {
		signed a = x, b = Mod, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		GModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(GModInt that) const { return x == that.x; }
	bool operator!=(GModInt that) const { return x != that.x; }
	GModInt operator-() const { GModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
int GModInt::Mod = 0;


typedef GModInt mint;
mint operator^(mint a, unsigned long long k) {
	mint r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
	if ((int)isprime.size() >= n + 1) return;
	isprime.assign(n + 1, true);
	isprime[0] = isprime[1] = false;
	int sqrtn = (int)(sqrt(n * 1.) + .5);
	for (int i = 2; i <= sqrtn; i ++) if (isprime[i]) {
		for (int j = i * i; j <= n; j += i)
			isprime[j] = false;
	}
	primes.clear();
	for (int i = 2; i <= n; i ++) if (isprime[i])
		primes.push_back(i);
}

typedef int FactorsInt;
typedef vector<pair<FactorsInt, int> > Factors;
void primeFactors(FactorsInt x, Factors &out_v) {
	out_v.clear();
	int sqrtx = (int)(sqrt(x*1.) + 10.5);
	sieve(sqrtx);
	for (vector<int>::const_iterator p = primes.begin(); p != primes.end(); ++ p) {
		if (*p > sqrtx) break;
		if (x % *p == 0) {
			int t = 1;
			x /= *p;
			while (x % *p == 0) {
				t ++;
				x /= *p;
			}
			out_v.push_back(make_pair(*p, t));
		}
	}
	if (x != 1) out_v.push_back(make_pair(x, 1));
}

int multiplicativeOrder(mint a, const vector<pair<int, int> > &data, int phi) {
	int order = 1;
	for (int i = 0; i < (int)data.size(); ++ i) {
		int p = data[i].first, t = data[i].second;
		for (int u = 1; ; u *= p) {
			mint x = a ^ (t * u);
			if (x.get() == 1) {
				order *= u;
				break;
			} else if (x.get() == 0 || t * u == phi)
				return 0;	//a \notin Z_m^*
		}
	}
	return order;
}

vector<mint> fact, factinv;
void nCr_computeFactinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	rer(i, 1, N) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i --) factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if (n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) * nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}
mint nHr(int n, int r) { return r == 0 ? 1 : nCr(n + r - 1, r); }

int main() {
	int N; int M; int a; int Q;
	while (~scanf("%d%d%d%d", &N, &M, &a, &Q)) {
		Factors fsQ;
		primeFactors(Q, fsQ);
		int phi = Q;
		for (auto f : fsQ)
			phi -= phi / f.first;
		Factors fsPhi;
		primeFactors(phi, fsPhi);
		vector<pair<int, int>> data;
		for (auto f : fsPhi) {
			int p = f.first, e = f.second;
			int q = 1;
			rep(k, e) q *= p;
			data.emplace_back(p, phi / q);
		}
		mint::Mod = Q;
		int order = multiplicativeOrder(a, data, phi);
		mint::Mod = order;
		nCr_computeFactinv(N + M);
		vector<int> ans(N);
		int num = 0;
		for (int i = N - 1; i >= 0; -- i) {
			mint::Mod = order;
			num += nCr(M, N - i - 1).get();
			num %= order;
			mint::Mod = Q;
			ans[i] = (mint(a) ^ (order + num)).get();
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}