#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

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
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
};
typedef ModInt<1000000007> mint;

vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	int n; int M;
	while (~scanf("%d%d", &n, &M)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int K; int X;
		scanf("%d%d", &K, &X), -- K;
		tree_getorder(g, 0);
		mint uninit; uninit.x = -1;
		vector<mint> memo(n * (X + 1) * 4, uninit);
		auto rec = [&](auto rec, int i, int j, int x, int type) -> mint {
			if (j == g[i].size())
				return type != 2 && x == (type == 1 ? 1 : 0) ? (type == 0 ? M - 1 : type == 1 ? 1 : K) : 0;
			int c = g[i][j];
			if (c == t_parent[i])
				return rec(rec, i, j + 1, x, type);
			mint &r = memo[(c * (X + 1) + x) * 4 + type];
			if (r.x != -1) return r;
			r = mint();
			rep(ct, 3) {
				if (type == 1 && ct < 2) continue;
				if (ct == 1 && type < 2) continue;
				rer(xL, 0, x) {
					r +=
						rec(rec, c, 0, xL, ct + (ct == 2 && type == 1)) *
						rec(rec, i, j + 1, x - xL, type + (type == 2 && ct == 1));
				}
			}
			return r;
		};
		mint ans;
		rer(x, 0, X) {
			rep(type, 3)
				ans += rec(rec, 0, 0, x, type);
		}
		printf("%d\n", ans.get());
	}
	return 0;
}