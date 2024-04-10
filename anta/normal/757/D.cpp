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

int main() {
	int n;
	while (~scanf("%d", &n)) {
		char b[76];
		scanf("%s", b);
		const int K = 20;
		vector<vector<mint>> dp(n + 1, vector<mint>(1 << K));
		rep(i, n)
			dp[i][0] = 1;
		mint ans;
		rep(i, n) {
			int start = i + 1;
			for (; start <= n && b[start - 1] == '0'; ++ start);
			rep(S, 1 << K) {
				mint x = dp[i][S];
				if (x.x == 0) continue;
				int val = 0;
				for (int j = start; j <= n; ++ j) {
					val = val * 2 + (b[j - 1] - '0');
					if (val > K) break;
					assert(val != 0);
					int nS = S | 1 << (val - 1);
					if ((nS & (nS + 1)) == 0)
						ans += x;
					dp[j][nS] += x;
				}
			}
		}
		printf("%d\n", ans.get());
	}
	return 0;
}