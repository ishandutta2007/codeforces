#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

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
	int N;
	while (~scanf("%d", &N)) {
		vector<pair<int, int> > edges(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d%d", &edges[i].first, &edges[i].second), -- edges[i].first, -- edges[i].second;
		UnionFind uf; uf.init(N * 2);
		for (auto e : edges)
			uf.unionSet(e.first, e.second);
		vector<vpii> ccs(N * 2);
		for (auto e : edges)
			ccs[uf.root(e.first)].push_back(e);
		bool ok = true;
		rep(i, N * 2)
			ok &= (int)ccs[i].size() <= uf.size(i);
		if (!ok) {
			puts("0");
			continue;
		}
		mint ans = 1;
		for (const auto &cc : ccs) if(!cc.empty()) {
			int n = uf.size(cc[0].first);
			if (cc.size() == n - 1) {
				ans *= n;
			} else {
				bool loop = false;
				for (auto e : cc)
					loop |= e.first == e.second;
				ans *= loop ? 1 : 2;
			}
		}
		printf("%d\n", ans.get());
	}
	return 0;
}