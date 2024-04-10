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
	int n;
	while(~scanf("%d", &n)) {
		vector<string> table(n);
		rep(i, n)
			cin >> table[i];
		const long double two = log(2.L), three = log(3.L);
		vector<vi> hori[4], vert[4], mdiag[4], sdiag[4];
		rep(d, 4) {
			vector<vector<bool>> v(n + 1, vector<bool>(n + 1));
			rep(i, n) rep(j, n)
				v[i][j] = table[i][j] == '0' + d;
			hori[d].assign(n, vi(n + 1));
			rep(i, n) rep(j, n)
				hori[d][i][j + 1] = hori[d][i][j] + v[i][j];
			vert[d].assign(n + 1, vi(n));
			rep(i, n) rep(j, n)
				vert[d][i + 1][j] = vert[d][i][j] + v[i][j];
			mdiag[d].assign(n + 1, vi(n + 1));
			rep(i, n) rep(j, n)
				mdiag[d][i + 1][j + 1] = mdiag[d][i][j] + v[i][j];
			sdiag[d].assign(n + 1, vi(n + 1));
			rep(i, n) rer(j, 1, n)
				sdiag[d][i + 1][j - 1] = sdiag[d][i][j] + v[i][j - 1];
		}

		auto get1 = [&](int d, int i, int j, int k) -> int {
			int r = 0;
			r += hori[d][i][j + k] - hori[d][i][j + 1 - k];
			r += vert[d][i + k][j] - vert[d][i + 1 - k][j];
			r -= table[i][j] == '0' + d;
			return r;
		};

		auto get2 = [&](int d, int i, int j, int k) -> int {
			int r = 0;
			r += mdiag[d][i + k][j + k] - mdiag[d][i + 1 - k][j + 1 - k];
			r += sdiag[d][i + k][j +1 - k] - sdiag[d][i + 1 - k][j + k];
			r -= table[i][j] == '0' + d;
			return r;
		};

		pair<long double, pair<int, int>> ans(-1, make_pair(0, 0));
		rep(i, n) rep(j, n) if(table[i][j] != '0') {
			{
				int l = 1, u = min({ i + 1, j + 1, n - i, n - j });
				while(u - l > 0) {
					int k = (l + u + 1) / 2;
					bool ok = get1(0, i, j, k) == 0;
					if(ok)
						l = k;
					else
						u = k - 1;
				}
				int k = l;
				int cnt2 = get1(2, i, j, k), cnt3 = get1(3, i, j, k);
				amax(ans, make_pair(two * cnt2 + three * cnt3, make_pair(cnt2, cnt3)));
			}
			{
				int l = 1, u = min({ i + 1, j + 1, n - i, n - j });
				while(u - l > 0) {
					int k = (l + u + 1) / 2;
					bool ok = get2(0, i, j, k) == 0;
					if(ok)
						l = k;
					else
						u = k - 1;
				}
				int k = l;
				int cnt2 = get2(2, i, j, k), cnt3 = get2(3, i, j, k);
				amax(ans, make_pair(two * cnt2 + three * cnt3, make_pair(cnt2, cnt3)));
			}
		}
		mint prod;
		if(ans.first != -1) {
			prod = 1;
			rep(i, ans.second.first)
				prod *= 2;
			rep(i, ans.second.second)
				prod *= 3;
		}
		printf("%d\n", prod.get());
	}
	return 0;
}