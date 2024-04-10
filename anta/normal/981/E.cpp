#include "bits/stdc++.h"
using namespace std;

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

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }

	ModInt &operator*=(ModInt that) {
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, x);
		return *this;
	}
	ModInt operator*(ModInt that) const {
		ModInt res;
		unsigned dummy;
		fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, res.x);
		return res;
	}
};
typedef ModInt<1000000007> mint;

int main() {
	mt19937 re((unsigned)chrono::high_resolution_clock{}.now().time_since_epoch().count());
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<pair<pair<int, int>, int>> queries(q);
		for (int qi = 0; qi < q; ++ qi) {
			int l; int r; int x;
			scanf("%d%d%d", &l, &r, &x), -- l;
			queries[qi] = { {l, r}, x };
		}
		vector<bool> total(n + 1);
		for (int iter = 0; iter < 2; ++ iter) {
			vector<vector<pair<int, mint>>> mul(n + 1), div(n + 1);
			for (auto qp : queries) {
				int l, r; tie(l, r) = qp.first; int x = qp.second;
				mint w = uniform_int_distribution<int>(0, mint::Mod - 1)(re);
				mul[l].emplace_back(x, w);
				div[r].emplace_back(x, w);
			}
			vector<mint> cur(n + 1);
			cur[0] = 1;
			for (int i = 0; i <= n; ++ i) {
				for (auto p : div[i]) {
					int x; mint w; tie(x, w) = p;
					for (int j = 0; j <= n - x; ++ j)
						cur[j + x] -= w * cur[j];
				}
				for (auto p : mul[i]) {
					int x; mint w; tie(x, w) = p;
					for (int j = n - x; j >= 0; -- j)
						cur[j + x] += w * cur[j];
				}
				for (int j = 0; j <= n; ++ j) if (cur[j].x != 0)
					total[j] = true;
			}
			assert(cur[0].x == 1);
			for (int j = 1; j <= n; ++ j) assert(cur[j].x == 0);
		}
		vector<int> ans;
		for (int i = 1; i <= n; ++ i) if(total[i])
			ans.push_back(i);
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
}