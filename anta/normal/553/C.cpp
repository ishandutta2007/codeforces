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
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
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
	
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

int solve(const vector<vector<bool> > &mask, const vector<vector<bool> > &love) {
	int n = mask.size();
	vpii edges;
	rep(i, n) rep(j, i)
		edges.push_back(mp(j, i));
	int m = edges.size();
	bool g[6][6]={};
	int r = 0;
	rep(i, 1 << m) {
		rep(j, n) rep(k, n) g[j][k] = false;
		bool ok = true;
		rep(j, m) {
			int a = edges[j].first, b = edges[j].second;
			bool c = (i >> j & 1) != 0;
			if(mask[a][b])
				ok &= c == love[a][b];
			g[a][b] = g[b][a] = c;
		}
		if(!ok) continue;
		rep(j, n) rep(k, j) rep(l, k) {
			int t = g[j][k] + g[j][l] + g[k][l];
			ok &= t == 1 || t == 3;
		}
		r += ok;
	}
	return r;
}

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		UnionFind uf; uf.init(n);
		vpii edges;
		rep(i, m) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c), -- a, -- b;
			if(c == 1) {
				uf.unionSet(a, b);
			}else {
				edges.push_back(mp(a, b));
				edges.push_back(mp(b, a));
			}
		}
		bool ok = true;
		vector<vi> g(n);
		each(i, edges) {
			int a = uf.root(i->first), b = uf.root(i->second);
			ok &= a != b;
			g[a].push_back(b);
		}
		vector<int> col(n, -1);
		vector<bool> vis(n, false);
		vi stk;
		int ccs = 0;
		rep(s, n) if(uf.root(s) == s && col[s] == -1) {
			stk.push_back(s);
			col[s] = 0;
			while(!stk.empty()) {
				int i = stk.back(); stk.pop_back();
				if(vis[i]) continue;
				vis[i] = true;
				int t = 1 - col[i];
				each(j, g[i]) {
					if(col[*j] != -1) {
						ok &= col[*j] == t;
						continue;
					}
					col[*j] = t;
					stk.push_back(*j);
				}
			}
			++ ccs;
		}
		mint ans = 1;
		rep(i, ccs-1) ans *= 2;
		if(!ok)
			puts("0");
		else
			printf("%d\n", ans.get());
	}
	return 0;
}