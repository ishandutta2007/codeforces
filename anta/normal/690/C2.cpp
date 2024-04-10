#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

pii dfs(int i, int p, const vector<vi> &g) {
	pii r(0, i);
	for(int j : g[i]) if(j != p) {
		pii p = dfs(j, i, g);
		amax(r, make_pair(p.first + 1, p.second));
	}
	return r;
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		auto p = dfs(0, -1, g);
		auto q = dfs(p.second, -1, g);
		int ans = q.first;
		printf("%d\n", ans);
	}
	return 0;
}