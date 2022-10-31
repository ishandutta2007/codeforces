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
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<vpii> identity(m);
		rep(i, n) {
			int g;
			scanf("%d", &g);
			map<int, int> cnt;
			rep(j, g) {
				int x;
				scanf("%d", &x), -- x;
				++ cnt[x];
			}
			for (auto p : cnt)
				identity[p.first].emplace_back(i, p.second);
		}
		map<vpii, int> groups;
		rep(i, m)
			++ groups[identity[i]];
		vector<mint> fact(m + 1);
		fact[0] = 1;
		rep(i, m)
			fact[i + 1] = fact[i] * (i + 1);
		mint ans = 1;
		for (auto &&p : groups)
			ans *= fact[p.second];
		printf("%d\n", ans.get());
	}
	return 0;
}