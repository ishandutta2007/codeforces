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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

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
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
	
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

vector<vi> g;
vector<int> parent;
vector<vi> stateidx;
vi t_ord;
int nstates = 0;

void tree_getstateindices(int root) {
	int n = g.size();
	parent.assign(n, -1);
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
			if(parent[c] == -1 && c != root) {
				stk.push_back(c);
				stateidx[i][j] = nstates ++;
			}else {
				stateidx[i][j] = -1;
				parent[i] = c;
			}
		}
		stateidx[i][g[i].size()] = nstates ++;
	}
}

inline int getstateindex(int i, int j) {
	int s = stateidx[i][j];
	return s != -1 ? s : stateidx[i][j+1];
}

vector<int> x;
vector<bool> xsub;
vector<mint> memo;

mint rec(int i, int j, bool b) {
	int s = stateidx[i][j];
	if(s == -1) return rec(i, j+1, b);
	mint &r = memo[s * 2 + b];
	if(r.get() != -1) return r;

	if(j == g[i].size())
		return r = !b ? 1 : 0;
	r = 0;
	int c = g[i][j];
	if(xsub[c]) {
		//
		r += rec(c, 0, x[c] == 0) * rec(i, j+1, b);
		if(b) {
			// & 
			r += rec(c, 0, x[c] == 0) * rec(i, j+1, false);
		}
		// & 
		if(x[c] == 0)
			r += rec(c, 0, false) * rec(i, j+1, b);
	}else {
		//
		r += rec(i, j+1, b);
	}
	return r;
}

bool dfs(int i, int p) {
	bool b = x[i] != 0;
	each(j, g[i]) if(*j != p)
		b |= dfs(*j, i);
	return xsub[i] = b;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> p(n, -1);
	rep(i, n-1)
		scanf("%d", &p[i+1]);
	x.assign(n, -1);
	rep(i, n)
		scanf("%d", &x[i]);
	g.assign(n, vi());
	reu(i, 1, n)
		g[p[i]].push_back(i);
	xsub.assign(n, false);
	dfs(0, -1);
	tree_getstateindices(0);
	memo.resize(nstates * 2);
	memset(&memo[0], -1, sizeof(memo[0]) * memo.size());
	mint ans = 0;
	if(count(all(x), 1) == 0) {
		ans = 1;
	}else {
		ans += rec(0, 0, x[0] == 0);
	}
	printf("%d\n", ans.get());
	return 0;
}