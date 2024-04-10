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

struct Edge {
	int id;
	int to;
	int mask;
};

vector<mint> memo;
vector<int> unary;
vector<Edge> pathg;
mint rec(int i, int s, int sb, int b, int result) {
	mint &r = memo[i * 8 + sb * 4 + b * 2 + result];
	if(r.x != -1) return r;
	if(i == s) {
		if(result != 0 || sb != b)
			return r = mint();
		else
			return r = 1;
	}
	r = mint();
	Edge e = pathg[i];
	assert(e.id != -1);
	int j = e.to, mask = e.mask;
	rep(nb, 2) {
		int sum = mask >> (b * 2 + nb) & 1;
		sum ^= unary[e.to] >> nb & 1;
		r += rec(e.to, s, sb, nb, result ^ sum);
	}
	return r;
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &m, &n)) {
		vector<vector<Edge>> g(n);
		unary.assign(n, 0);
		rep(i, m) {
			int k;
			scanf("%d", &k);
			int a[2];
			rep(j, k)
				scanf("%d", &a[j]);
			if(k == 2 && abs(a[0]) == abs(a[1])) {
				if(a[0] != a[1]) {
					unary[abs(a[0]) - 1] ^= 3;
					continue;
				} else {
					-- k;
				}
			}
			if(k == 1) {
				unary[abs(a[0]) - 1] ^= 1 << (a[0] > 0 ? 1 : 0);
			} else {
				rep(p, 2) {
					int mask = 15 - (1 << ((a[p] > 0 ? 0 : 1) * 2 + (a[1 - p] > 0 ? 0 : 1)));
					g[abs(a[p]) - 1].push_back(Edge{ i, abs(a[1 - p]) - 1, mask });
				}
			}
		}
		mint undef; undef.x = -1;
		memo.assign(n * 16, undef);
		vector<bool> vis(n);
		pathg.assign(n, Edge{ -1, -1, -1 });
		mint ans[2] = { 1, 0 };
		rep(iscycle, 2) {
			rep(i, n) if(!vis[i] && (iscycle == 1 || (int)g[i].size() <= 1)) {
				int j = i;
				while(1) {
					vis[j] = true;
					int sj = j;
					for(auto e : g[j]) if(!vis[e.to]) {
						pathg[j] = e;
						j = e.to;
						break;
					}
					if(j == sj)
						break;
				}
				Edge cycle{ -1 };
				if(iscycle == 1) {
					for(auto e : g[j]) if(e.to == i && e.id != pathg[i].id)
						cycle = e;
					assert(cycle.id != -1);
				}
				mint cnt[2] = {};
				rep(bi, 2) rep(bj, 2) {
					int sum = 0;
					if(iscycle == 1)
						sum ^= cycle.mask >> (bj * 2 + bi) & 1;
					sum ^= unary[i] >> bi & 1;
					rep(result, 2)
						cnt[result] += rec(i, j, bj, bi, result ^ sum);
				}
				mint nans0 = ans[0] * cnt[0] + ans[1] * cnt[1];
				mint nans1 = ans[0] * cnt[1] + ans[1] * cnt[0];
				ans[0] = nans0, ans[1] = nans1;
			}
		}
		printf("%d\n", ans[1].get());
	}
	return 0;
}