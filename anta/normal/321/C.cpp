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

vector<vector<int> > g;
vector<bool> blocked;
vi ord, par, subtsize;
string ans;

void rec(int root, int level) {
	ord.push_back(root);
	par[root] = -1;
	for(int h = 0; h != ord.size(); ++ h) {
		int i = ord[h];
		each(j, g[i]) if(!blocked[*j] && par[*j] == -2) {
			par[*j] = i;
			ord.push_back(*j);
		}
	}

	each(i, ord)
		subtsize[*i] = 1;
	int size = ord.size();
	for(int ix = size - 1; ix > 0; -- ix) {
		int i = ord[ix], p = par[i];
		subtsize[p] += subtsize[i];
	}

	int centroid = -1;
	rep(ix, size) {
		int i = ord[ix];
		bool ok = true;
		each(j, g[i]) if(par[*j] == i)
			ok &= subtsize[*j] * 2 <= size;
		ok &= (size - subtsize[i]) * 2 <= size;
		if(ok) {
			centroid = i;
			break;
		}
	}

	each(i, ord)
		par[*i] = -2;
	ord.clear();

	ans[centroid] = 'A' + level;

	blocked[centroid] = true;
	each(j, g[centroid]) if(!blocked[*j])
		rec(*j, level + 1);
	blocked[centroid] = false;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		g.assign(n, vi());
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ord.clear();
		par.assign(n, -2);
		blocked.assign(n, false);
		subtsize.assign(n, -2);
		ans.assign(n, '?');
		rec(0, 0);
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%c", ans[i]);
		}
		puts("");
	}
	return 0;
}