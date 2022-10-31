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

vector<int> t_parent;
vi t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<bool> isleaf(n);
		rep(i, n)
			isleaf[i] = g[i].size() == 1;
		vi subtleafs(n);
		rep(i, n)
			subtleafs[i] = isleaf[i];
		for(int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtleafs[p] += subtleafs[i];
		}
		function<vector<int>(int)> rec;
		rec = [&](int i) -> vector<int> {
			int im = isleaf[i] ? 1 : 0;
			vi dp, ndp;
			ndp.assign((im+1) * 2, INF);
			ndp[0 * 2 + 0] = 0;
			ndp[(isleaf[i] ? 1 : 0) * 2 + 1] = 0;
			int n = im;
			each(j, g[i]) if(*j != t_parent[i]) {
				dp.swap(ndp);
				int m = subtleafs[*j];
				vi v = rec(*j);
				assert(v.size() == (m + 1) * 2);
				ndp.assign((n+m+1) * 2, INF);
				rer(a, 0, n) rer(b, 0, m) rep(x, 2) rep(y, 2)
					amin(ndp[(a + b) * 2 + x], dp[a * 2 + x] + v[b * 2 + y] + (x != y));
				n += m;
			}
			return ndp;
		};
		vi ansv = rec(0);
		int a = subtleafs[0] / 2;
		int ans = min(ansv[a * 2 + 0], ansv[a * 2 + 1]);
		printf("%d\n", ans);
	}
	return 0;
}