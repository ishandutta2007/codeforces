#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

inline long long mulmodll(long long a, long long b, long long m) {
	long long quot = (long long)((long double)a * b / m + 0.5);
	long long res = a * b - m * quot;
	res = a * b - m * quot;
	if (res < 0) res += m;
	return res;
}

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

template<long long MOD>
struct ModIntLL {
	static const long long Mod = MOD;
	unsigned long long x;
	ModIntLL() : x(0) { }
	ModIntLL(signed long long sig) { long long sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	long long get() const { return (long long)x; }

	ModIntLL &operator+=(ModIntLL that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModIntLL &operator-=(ModIntLL that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModIntLL &operator*=(ModIntLL that) { x = mulmodll(x, that.x, MOD); return *this; }

	ModIntLL operator+(ModIntLL that) const { return ModIntLL(*this) += that; }
	ModIntLL operator-(ModIntLL that) const { return ModIntLL(*this) -= that; }
	ModIntLL operator*(ModIntLL that) const { return ModIntLL(*this) *= that; }
};

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) {
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, x);
		return *this;
	}
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};

template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1000000007> mint;
typedef ModIntLL<(ll)mint::Mod * (mint::Mod - 1)> qmint;

struct Val {
	mint val;
	mint ten;
	Val() : val(), ten(1) {}
	Val(mint val, mint ten) : val(val), ten(ten) {}
};
const mint Ten = 10;

Val concat(Val x, Val y) {
	return Val(x.val * y.ten + y.val, x.ten * y.ten);
}

typedef const char *Pos;

void expect(bool b) { assert(b); }
bool p_expr(Pos &p, Val &res);

__declspec(noinline) Val calcDP(const vector<int> &digitsL, const vector<int> &digitsR, int len) {
	assert(digitsL.size() <= digitsR.size());
	int nDigits = (int)digitsR.size();
	mint tenCurLen = Ten ^ len;
	vector<Val> dp((nDigits + 1) * 4);
	mint inv = (mint(1) - tenCurLen).inverse(), shift = 1;
	rep(gtL, 2) rep(ltR, 2)
		dp[0 * 4 + gtL * 2 + ltR] = Val(0, tenCurLen);
	rep(i, nDigits) {
		int dL = i >= (int)digitsL.size() ? 0 : digitsL[i], dR = digitsR[i];
		rep(gtL, 2) rep(ltR, 2) {
			Val r;
			rep(d, 10) {
				if (!gtL && d < dL) continue;
				if (!ltR && dR < d) continue;
				Val x = dp[i * 4 + (gtL || dL < d) * 2 + (ltR || d < dR)];
				mint pattern = (mint(1) - x.ten) * inv * shift;
				r = concat(r, Val(x.val + pattern * d, x.ten));
			}
			dp[(i + 1) * 4 + gtL * 2 + ltR] = r;
		}
		shift *= Ten;
	}
	return dp[nDigits * 4 + 0 * 2 + 0];
}

//[L, R]
Val calcDP(int L, int R, int len) {
	vector<int> digitsL, digitsR;
	for (int x = L; x > 0; x /= 10) digitsL.push_back(x % 10);
	for (int x = R; x > 0; x /= 10) digitsR.push_back(x % 10);
	return calcDP(digitsL, digitsR, len);
}

Val calc(qmint count, mint offset, int len) {
	mint tenLen = Ten ^ len;
	int quot = (int)(count.get() / mint::Mod), rem = count.get() % mint::Mod;
	mint tenCycles = tenLen ^ quot;
	mint cyclePattern = (mint(1) - tenCycles) / (mint(1) - tenLen);
	Val cycleVal = calcDP(offset.get(), offset.get() + mint::Mod - 1, len);
	Val res(cycleVal.val * cyclePattern, tenCycles);
	Val remVal = calcDP(offset.get(), offset.get() + rem - 1, len);
	res = concat(res, remVal);
	return res;
}

bool p_term(Pos &p, Val &res) {
	if (!isdigit(*p)) return false;
	Pos Lbegin = p;
	do ++ p; while (isdigit(*p));
	Pos Lend = p;
	if (*p == '-') {
		++ p;
		Pos Rbegin = p;
		assert(isdigit(*p));
		do ++ p; while (isdigit(*p));
		Pos Rend = p;
		int lenL = (int)(Lend - Lbegin), lenR = (int)(Rend - Rbegin);
		qmint count = 9;
		mint offset = 1;
		rep(i, lenL - 1) {
			count *= 10;
			offset *= 10;
		}
		for (int len = lenL; len <= lenR; ++ len) {
			if (len == lenL || len == lenR) {
				vector<int> digitsL, digitsR;
				digitsL.reserve(lenL);
				digitsR.reserve(lenR);
				if (len == lenL) {
					for (auto it = Lend; it != Lbegin; -- it)
						digitsL.push_back(*(it - 1) - '0');
				} else {
					rep(i, len - 1)
						digitsL.push_back(0);
					digitsL.push_back(1);
				}
				if (len == lenR) {
					for (auto it = Rend; it != Rbegin; -- it)
						digitsR.push_back(*(it - 1) - '0');
				} else {
					rep(i, len)
						digitsR.push_back(9);
				}
				res = concat(res, calcDP(digitsL, digitsR, len));
			} else {
				res = concat(res, calc(count, offset, len));
			}
			count *= 10;
			offset *= 10;
		}
	} else if (*p == '(') {
		++ p;
		Val val;
		expect(p_expr(p, val));
		assert(*p == ')');
		++ p;

		Val pow = val;
		res = Val();
		for (auto it = Lend; it != Lbegin; -- it) {
			int num = *(it - 1) - '0';
			rep(j, num)
				res = concat(res, pow);
			Val npow;
			rep(j, 10)
				npow = concat(npow, pow);
			pow = npow;
		}
	} else {
		res = Val();
		for (auto it = Lbegin; it != Lend; ++ it) {
			res.val = res.val * Ten + (*it - '0');
			res.ten *= Ten;
		}
	}
	return true;
}

bool p_expr(Pos &p, Val &res) {
	if (!p_term(p, res)) return false;
	while (*p == '+') {
		++ p;
		Val val;
		expect(p_term(p, val));
		res = concat(res, val);
	}
	return true;
}

int main() {
	char S[100001];
	while (~scanf("%s", S)) {
		Pos pos = S;
		Val ans;
		p_expr(pos, ans);
		printf("%d\n", ans.val.get());
	}
	return 0;
}