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
#include <unordered_map>
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

bool topologicalSortForCC(const vector<vi> &g, const vi &cc, vi &ord, vi &deg) {
	each(i, cc) deg[*i] = 0;
	each(i, cc) each(j, g[*i]) deg[*j] ++;
	ord.clear();
	int t = 0;
	each(i, cc) if(deg[*i] == 0) ord.push_back(*i);
	for(int h = 0; h < (int)ord.size(); h ++) {
		int v = ord[h];
		each(j, g[v])
			if(-- deg[*j] == 0)
				ord.push_back(*j);
	}
	return ord.size() == cc.size();
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	UnionFind uf; uf.init(n);
	vector<vi> g(n);
	rep(i, m) {
		int a, b;
		scanf("%d%d", &a, &b), -- a, -- b;
		uf.unionSet(a, b);
		g[a].push_back(b);
	}
	vector<vi> ccs(n);
	rep(i, n)
		ccs[uf.root(i)].push_back(i);
	int ans = 0;
	{	vi ord, deg(n);
		rep(i, n) if(uf.root(i) == i) {
			bool ok = topologicalSortForCC(g, ccs[i], ord, deg);
			ans += (int)ccs[i].size() - ok;
		}
	}
	printf("%d\n", ans);
	return 0;
}