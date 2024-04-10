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
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
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
};
typedef ModInt<998244353> mint;

vector<mint> fact, factinv;
void nCr_computeFactinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	rer(i, 1, N) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for(int i = N; i >= 1; i --) factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if(n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) * nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> p(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &p[i]), -- p[i];
		vector<int> q(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &q[i]), -- q[i];
		vector<int> next(n * 2, -1);
		rep(i, n) if(p[i] != -1)
			next[i] = n + p[i];
		rep(i, n) if(q[i] != -1)
			next[n + q[i]] = i;
		int chains[1 << 2] = {};
		int cycles = 0;
		{
			vector<bool> in(n * 2);
			rep(i, n * 2) if(next[i] != -1)
				in[next[i]] = true;
			vector<bool> vis(n * 2);
			rep(phase, 2) {
				rep(i, n * 2) if(!vis[i] && (phase == 1 || !in[i])) {
					int j = i;
					while(1) {
						vis[j] = true;
						if(next[j] == -1 || vis[next[j]]) break;
						j = next[j];
					}
					if(phase == 0)
						++ chains[(i / n) * 2 + (j / n)];
					else
						++ cycles;
				}
			}
		}
		nCr_computeFactinv(n * 2);
		vector<vector<mint>> stirling(n + 1, vector<mint>(n + 1));
		stirling[0][0] = 1;
		rer(i, 1, n) rer(j, 1, i)
			stirling[i][j] = stirling[i - 1][j - 1] + stirling[i - 1][j] * (i - 1);
		int cnt0 = chains[0];
		vector<mint> g(n + 1);
		if(cnt0 == 0) {
			g[0] = 1;
		} else {
			rer(i, 0, n)
				g[i] = fact[i] * fact[cnt0] * nCr(i + cnt0 - 1, cnt0 - 1);
		}
		vector<mint> G(n + 1);
		int cnt1 = chains[1], cnt2 = chains[2];
		rer(t, 0, n) {
			rer(k, 0, cnt2)
				G[t] += g[k] * stirling[cnt2 - k][t] * nCr(cnt2, k);
		}
		vector<mint> ans(n + 1);
		rer(i, 0, n - cycles) rer(t, 0, i)
			ans[i + cycles] += stirling[cnt1 + cnt0][i - t] * G[t];
		rer(i, 1, n) {
			if(i != 1) putchar(' ');
			printf("%d", ans[n - i + 1].get());
		}
		puts("");
	}
	return 0;
}