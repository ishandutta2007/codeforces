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

template<typename Sum, typename Combine, typename Calc>
void freeTreeDP(const vector<int> &t_ord, const vector<int> &t_parent, vector<Sum> &downsum, vector<Sum> &upsum, Sum identity, Combine combine, Calc calc) {
	int n = (int)t_ord.size();
	vector<int> children(n, 0), childid(n, -1);
	for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		childid[i] = children[p] ++;
	}
	vector<vector<Sum>> prefix(n), suffix(n);
	for (int i = 0; i < n; ++ i) {
		prefix[i].assign(children[i] + 1, identity);
		suffix[i].assign(children[i] + 1, identity);
	}
	downsum.assign(n, identity);
	upsum.assign(n, identity);
	for (int ix = (int)t_ord.size() - 1; ix >= 0; -- ix) {
		int i = t_ord[ix], p = t_parent[i];
		for (int j = 0; j < children[i]; ++ j)
			prefix[i][j + 1] = combine(prefix[i][j], prefix[i][j + 1]);
		for (int j = children[i]; j > 0; -- j)
			suffix[i][j - 1] = combine(suffix[i][j - 1], suffix[i][j]);
		if (p != -1) {
			downsum[i] = calc(p, i, suffix[i][0]);
			prefix[p][childid[i] + 1] = downsum[i];
			suffix[p][childid[i]] = downsum[i];
		}
	}
	downsum[t_ord[0]] = suffix[t_ord[0]][0];
	for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		Sum sum = suffix[p][childid[i] + 1];
		sum = combine(sum, upsum[p]);
		sum = combine(sum, prefix[p][childid[i]]);
		upsum[i] = calc(i, p, sum);
	}
}

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
	int N;
	while (~scanf("%d", &N)) {
		vector<vector<int> > g(N);
		for (int i = 0; i < N - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (N == 1) {
			puts("1");
			continue;
		}
		tree_getorder(g, 0);
		struct Sum { mint x0, x1; };
		auto mult = [](Sum a, Sum b) {return Sum{ a.x0*b.x0,a.x1*b.x1 }; };
		vector<Sum> downsum, upsum;
		freeTreeDP(t_ord, t_parent, downsum, upsum, Sum{1,1},
			mult,
			[&g](int from, int to, Sum sum) {
			if (g[to].size() == 1)
				return Sum{1,1};
			return Sum{ sum.x0+sum.x1,sum.x0+sum.x1 };
		});
		mint ans;
		rep(i, N) {
			Sum sum = upsum[i];
			for (int j : g[i]) if (j != t_parent[i])
				sum = mult(sum, downsum[j]);
			mint total = sum.x0;
			total += sum.x1;
			ans += total;
		}
		printf("%d\n", ans.get());
	}
	return 0;
}