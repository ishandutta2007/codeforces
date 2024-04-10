#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <random>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

////////////////////////////////////////////////////////
//ModInt

inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
	unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
#ifdef __GNUC__
	asm(
		"divl %4; \n\t"
		: "=a" (d), "=d" (m)
		: "d" (xh), "a" (xl), "r" (y)
	);
#else
	__asm {
		mov edx, dword ptr[xh];
		mov eax, dword ptr[xl];
		div dword ptr[y];
		mov dword ptr[d], eax;
		mov dword ptr[m], edx;
	};
#endif
	out_d = d; out_m = m;
}

//x / y < 2^32 !
inline unsigned fasterLLMod(unsigned long long x, unsigned y) {
	unsigned dummy, r;
	fasterLLDivMod(x, y, dummy, r);
	return r;
}

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) {
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, x);
		return *this;
	}
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const {
		ModInt res;
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, res.x);
		return res;
	}
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
typedef ModInt<1000000007> mint;

////////////////////////////////////////////////////////
//Black box linear algebra

typedef unsigned long long ull;

mint dot(const mint *a, const mint *b, int n) {
	const int K = 16;
	static_assert((ull)mint::Mod * mint::Mod < ~0ULL / (K + 1), "K is too large");
	ull sum = 0;
	int i;
	for(i = 0; i + K <= n; ) {
		rep(j, K) {
			sum += (ull)a[i].x * b[i].x;
			++ i;
		}
		sum %= mint::Mod;
	}
	for(; i < n; ++ i)
		sum += (ull)a[i].x * b[i].x;
	return mint((int)(sum % mint::Mod));
}

//Berlekamp-Massey algorithm
//(\sum_{j=0}^L C[j] s[i + L - j]) = 0 for all 0 <= i < N - L
// L, C C[0] = 1 
int berlekampMessey(vector<mint> s, vector<mint> &C) {
	int N = (int)s.size();
	reverse(s.begin(), s.end());	//
	C.assign(N + 1, mint());
	vector<mint> B(N + 1, mint());
	C[0] = B[0] = 1;
	int degB = 0;
	vector<mint> T;
	int L = 0, m = 1;
	mint b = 1;
	for(int n = 0; n < N; ++ n) {
		mint d = s[N - 1 - n];
		if(L > 0) d += dot(&C[1], &s[N - 1 - n + 1], L);
		if(d == mint()) {
			++ m;
		} else {
			if(2 * L <= n)
				T.assign(C.begin(), C.begin() + (L + 1));
			mint coeff = -d * b.inverse();
			for(int i = 0; i <= degB; ++ i)
				C[m + i].x = fasterLLMod(C[m + i].x + (ull)coeff.x * B[i].x, mint::Mod);
			if(2 * L <= n) {
				L = n + 1 - L;
				B.swap(T);
				degB = (int)B.size() - 1;
				b = d;
				m = 1;
			} else {
				++ m;
			}
		}
	}
	C.resize(L + 1);
	return L;
}


//minimum polynomial
//(\sum_{j=0}^d phi[j] s[i + j]) = 0 for all i
void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
	int n2 = (int)a.size(), n = n2 / 2;
	assert(n2 % 2 == 0);
	int L = berlekampMessey(a, phi);
	reverse(phi.begin(), phi.begin() + (L + 1));
}

struct RandomModInt {
	default_random_engine re;
	uniform_int_distribution<int> dist;
#ifndef _DEBUG
	RandomModInt() : re(random_device{}()), dist(1, mint::Mod - 1) {}
#else
	RandomModInt() : re(), dist(1, mint::Mod - 1) {}
#endif
	mint operator()() {
		mint r;
		r.x = dist(re);
		return r;
	}
} randomModInt;

void randomModIntVector(vector<mint> &v) {
	int n = (int)v.size();
	for(int i = 0; i < n; ++ i)
		v[i] = randomModInt();
}

mint computeDeterminant(int N, const vector<mint> &diag, const vector<pair<int, int> > &validEdges) {
	int n = N - 1;
	if(n == 0)
		return 1;
	vector<mint> D(n);
	vector<mint> m;
	randomModIntVector(D);
	vector<mint> u(n), b(n);
	vector<ull> tmp(n);
	randomModIntVector(u);
	randomModIntVector(b);

	vector<mint> uTAib(n * 2);
	uTAib[0] = dot(&u[0], &b[0], n);

	vector<pair<short, short> > edges(validEdges.begin(), validEdges.end());

	for(int k = 1; k < n * 2; ++ k) {
		tmp.assign(n, 0);

		rep(i, n)
			b[i] *= D[i];

		for(auto e : edges)
			tmp[e.first] += b[e.second].x;

		rep(i, n)
			b[i].x = fasterLLMod(tmp[i] + (ull)diag[i].x * b[i].x, mint::Mod);

		uTAib[k] = dot(&u[0], &b[0], n);
	}

	computeMinimumPolynomialForLinearlyRecurrentSequence(uTAib, m);
	//
	//m = char(AD)
	if(m.empty() || m[0] == mint())
		return mint();
	if(m.size() != n + 1 || m.back() != mint(1))
		return computeDeterminant(N, diag, validEdges);
	mint detD = 1;
	for(int i = 0; i < n; ++ i)
		detD *= D[i];
	mint invdetD = detD.inverse();
	mint detA = m[0] * invdetD;
	if(n % 2 == 1)
		detA = mint() - detA;
	return detA;
}

mint countSpanningTrees(int N, const vector<pair<int, int> > &edges) {
	assert(N > 0);

	vector<int> deg(N, 0);

	for(auto e : edges) {
		++ deg[e.first];
		++ deg[e.second];
	}

	vector<pair<int, int> > validEdges;
	for(auto e : edges) if(e.first < N - 1 && e.second < N - 1 && e.first != e.second) {
		validEdges.push_back(e);
		validEdges.push_back(make_pair(e.second, e.first));
	}

	sort(validEdges.begin(), validEdges.end());

	vector<mint> diag(N - 1);
	rep(i, N - 1)
		diag[i] = -deg[i];

	mint res = computeDeterminant(N, diag, validEdges);
	if((N - 1) % 2 != 0)
		res = -res;
	return res;
}

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<pii> edges;
		rep(i, k) reu(j, i + 1, k)
			edges.emplace_back(i, j);
		for(int i = k; i < n; ++ i) {
			rep(j, k) {
				int a;
				scanf("%d", &a), -- a;
//				a = rand() % i;
				edges.emplace_back(a, i);
			}
		}
		mint ans = countSpanningTrees(n, edges);
		printf("%d\n", ans.get());
	}
	return 0;
}