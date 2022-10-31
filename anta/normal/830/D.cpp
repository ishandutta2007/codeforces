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
		//jlevel i()
		vector<vector<mint>> dp(n + 1, vector<mint>(n + 5));
		dp[0][0] = 1;
		rep(i, n) {
			rer(l, 0, n + 4) rer(r, 0, n + 4) if(l + r <= n + 3) {
				mint x = dp[i][l] * dp[i][r];
				/*
				//1
				dp[i + 1][l + r] += x;
				//10
				dp[i + 1][l + r + 1] += x;
				//11
				if(1 <= l)
					dp[i + 1][l + r] += x * l * 2;
				if(1 <= r)
					dp[i + 1][l + r] += x * r * 2;
				//12
				if (2 <= l)
					dp[i + 1][l + r - 1] += x * (l * (l - 1));
				if (2 <= r)
					dp[i + 1][l + r - 1] += x * (r * (r - 1));
				//12
				if(1 <= l && 1 <= r)
					dp[i + 1][l + r - 1] += x * (l * r) * 2;
				*/
				dp[i + 1][l + r] += x * (1 + (l + r) * 2);
				dp[i + 1][l + r + 1] += x;
				if (l + r > 0)
					dp[i + 1][l + r - 1] += x * (l * (l - 1) + r * (r - 1) + (l * r) * 2);
			}
		}
		mint ans = dp[n][1];
		printf("%d\n", ans.get());
	}
	return 0;
}