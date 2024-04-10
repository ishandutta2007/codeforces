#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

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
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

pair<mint, mint> memo[33][2][2][2];
int X, Y;
int K;
pair<mint,mint> rec(int i, bool xlt, bool ylt, bool klt) {
	pair<mint,mint> &r = memo[i+1][xlt][ylt][klt];
	if (r.first.x != -1) return r;
	if (i == -1)
		return r = make_pair(xlt && ylt && klt ? 1 : 0, 0);
	int rx = X >> i & 1;
	int ry = Y >> i & 1;
	int rk = K >> i & 1;
	r = { 0,0 };
	rep(x, 2) rep(y, 2) {
		int k = x ^ y;
		if (!xlt&&rx < x)continue;
		if (!ylt&&ry < y)continue;
		if (!klt&&rk < k)continue;
		auto p = rec(i - 1, xlt || x < rx, ylt || y < ry, klt || k < rk);
		r.first += p.first;
		r.second += p.second + p.first * ((ll)k << i);
	}
	return r;
}

int main() {
	int Q;
	while (~scanf("%d", &Q)) {
		rep(ii, Q) {
			int xL; int yL; int xR; int yR;
			scanf("%d%d%d%d", &xL, &yL, &xR, &yR);
			-- xL, -- yL;
			scanf("%d", &K);
			mint ans;
			rep(x, 2) rep(y, 2) {
				memset(memo, -1, sizeof(memo));
				X = x == 0 ? xR : xL;
				Y = y == 0 ? yR : yL;
				auto p = rec(31, false, false, false);
				ans += (p.second + p.first) * ((x + y) % 2 == 1 ? -1 : 1);
			}
			printf("%d\n", ans.get());
		}
	}
	return 0;
}