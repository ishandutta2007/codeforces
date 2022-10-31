#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

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
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

int main() {
	int w;
	while(~scanf("%d", &w)) {
		const int h = 3;
		char table[h][10001];
		int si = -1, sj = -1;
		rep(i, h) {
			scanf("%s", table[i]);
			rep(j, w) if(table[i][j] == 'O')
				si = i, sj = j;
		}
		vector<vector<mint>> dp(w + 1, vector<mint>((1 << h) * 2));
		dp[0][0] = 1;
		rep(j, w) {
			int mask = 0;
			rep(i, h) if(table[i][j] == '.')
				mask |= 1 << i;
			rep(s, 1 << h) rep(ok, 2) {
				mint x = dp[j][s * 2 + ok];
				if(x.x == 0) continue;
				rep(vert, 3) {
					int t = s;
					if(vert != 2) {
						if((t & (3 << vert)) != 0) continue;
						t |= 3 << vert;
					}
					if((t & ~mask) != 0) continue;
					int hori = mask & ~t;
					int nok = ok;
					if(j + 2 == sj)
						nok |= hori >> si & 1;
					if(j - 1 == sj)
						nok |= hori >> si & 1;
					if(j == sj)
						nok |= vert != 2 ? 1 : 0;
					dp[j + 1][hori * 2 + nok] += x;
				}
			}
		}
		mint ans = dp[w][0 * 2 + 1];
		printf("%d\n", ans.get());
	}
	return 0;
}