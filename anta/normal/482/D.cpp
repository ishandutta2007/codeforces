#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long, long long> pll; typedef vector<pair<long long, long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt(): x(0) { }
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

vector<vi> g;
vector<int> subtreesize;

int dfs(int i) {
	int r = 1;
	each(j, g[i])
		r += dfs(*j);
	return subtreesize[i] = r;
}

vector<vi> stateidx;
vi t_ord;
int nstates = 0;

void tree_getstateindices(int root) {
	int n = g.size();
	stateidx.assign(n, vi());
	t_ord.clear();
	nstates = 0;

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		stateidx[i].assign(g[i].size() + 1, -1);
		rep(j, g[i].size()) {
			int c = g[i][j];
			stk.push_back(c);
			stateidx[i][j] = nstates ++;
		}
		stateidx[i][g[i].size()] = nstates ++;
	}
}

inline int getstateindex(int i, int j) {
	int s = stateidx[i][j];
	return s != -1 ? s : stateidx[i][j+1];
}

vector<mint> memo[16];
mint rec3(int i, int j, int left, int right, bool notperm, int siz) {
	int s = stateidx[i][j];
	mint &r = memo[left * 8 + right * 4 + notperm * 2 + siz][s];
	if(r.get() != -1) return r;
	if(j == (g[i].size() + 1) / 2)
		return r = siz == 1 ? (notperm ? 2 : 1) : 0;
	r = 0;
	int c1 = g[i][j], c2 = g[i][g[i].size()-1-j];
	rep(le, 2) rep(ri, 2) rep(leb, 2) rep(rib, 2) {
		if(c1 == c2 && (le != ri || leb != rib)) continue;
		if(leb == 0 && le == 1) continue;
		if(rib == 0 && ri == 1) continue;
		mint x = 1;
		if(c1 != c2) {
			x *= rec3(i, j+1, left ^ le, right ^ ri,
				notperm || ( left != (siz ^ 1 ^ le ^ right) && leb == 1)
				        || (right != (siz ^ 1 ^ ri ^  left) && rib == 1),
				siz ^ le ^ ri);
		}else {
			x *= rec3(i, j+1, left ^ le, right ^ ri,
				notperm || ( left != (siz ^ 1 ^ le ^ right) && leb == 1),
				siz ^ le);
		}
		if(leb == 1)
			x *= rec3(c1, 0, 0, 0, false, le);
		if(rib == 1 && c1 != c2)
			x *= rec3(c2, 0, 0, 0, false, ri);
		r += x;
	}
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	g.assign(n, vi());
	reu(i, 1, n) {
		int p;
		scanf("%d", &p), -- p;
		g[p].push_back(i);
	}
	subtreesize.assign(n, 0);
	dfs(0);
	tree_getstateindices(0);
	mint initt; initt.x = -1;
	rep(k, 16)
		memo[k].assign(nstates, initt);
	mint ans = 0;
	ans += rec3(0, 0, 0, 0, false, 0);
	ans += rec3(0, 0, 0, 0, false, 1);
	printf("%d\n", ans.get());
	return 0;
}