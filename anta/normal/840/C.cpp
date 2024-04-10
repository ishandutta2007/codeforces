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
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		map<int, int> counts;
		rep(i, n) {
			int x = a[i];
			for (int j = 2; ; ++ j) {
				int jj = j * j;
				if (jj > x) break;
				while (x % jj == 0)
					x /= jj;
			}
			++ counts[x];
		}
		vector<vector<mint>> C(n + 1, vector<mint>(n + 1));
		for (int i = 0; i <= n; i ++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j ++)
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
		vector<mint> dp, ndp(n + 1);
		ndp[0] = 1;
		int sum = 0;
		for (auto pp : counts) {
			int w = pp.second;
			if (w == 0) continue;
			dp.swap(ndp);
			ndp.assign(n + 1, mint());
			rep(i, n + 1) {
				mint x = dp[i];
				if (x.x == 0) continue;
				rer(j, 0, i) {
					for (int k = 0; k <= sum + 1 - i && j + k <= w; ++ k) {
						if (j == 0 && k == 0) continue;
						int l = w - j - k;
						mint cnt = x;
						cnt *= C[i][j];
						cnt *= C[sum + 1 - i][k];
						cnt *= C[l + j + k - 1][j + k - 1];
						ndp[i - j + l] += cnt;
					}
				}
			}
			sum += w;
		}
		mint ans = ndp[0];
		for (auto pp : counts) rep(i, pp.second)
			ans *= i + 1;
		printf("%d\n", ans.get());
	}
	return 0;
}