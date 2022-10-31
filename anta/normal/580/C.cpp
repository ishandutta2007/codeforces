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
		for(int j = (int)g[i].size()-1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		vi a(n);
		rep(i, n) scanf("%d", &a[i]);
		vector<vi> g(n);
		rep(i, n-1) {
			int x, y;
			scanf("%d%d", &x, &y), -- x, -- y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		tree_getorder(g, 0);
		vi len(n);
		vector<bool> ok(n);
		len[0] = a[0];
		ok[0] = a[0] <= m;
		reu(ix, 1, n) {
			int i = t_ord[ix], p = t_parent[i];
			len[i] = a[i] == 1 ? len[p] + 1 : 0;
			ok[i] = ok[p] && len[i] <= m;
		}
		int ans = 0;
		rep(i, n) if(i != 0 && g[i].size() <= 1)
			ans += ok[i];
		printf("%d\n", ans);
	}
	return 0;
}