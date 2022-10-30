#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool topologicalSort(const vector<vi> &g, vi &ord) {
	int n = g.size();
	vi deg(n);
	rep(i, n) for(int j : g[i]) deg[j] ++;
	ord.assign(n, -1);
	int t = 0;
	rep(i, n) if(deg[i] == 0) ord[t ++] = i;
	for(int h = 0; h < t; h ++) {
		int v = ord[h];
		for(int j : g[v])
			if(-- deg[j] == 0)
				ord[t ++] = j;
	}
	return t == n;
}

int main() {
	int n; int m; int T;
	while(~scanf("%d%d%d", &n, &m, &T)) {
		vector<vector<int> > g(n);
		vector<vector<pair<int, int> > > gw(n);
		for(int i = 0; i < m; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			g[u].push_back(v);
			gw[u].push_back(make_pair(v, w));
		}
		vi ord;
		topologicalSort(g, ord);
		vector<vpii> dp(n, vpii(n + 1, make_pair(INF, -1)));
		dp[0][1] = { 0, -1 };
		for(int i : ord) rep(j, n + 1) {
			int x = dp[i][j].first;
			if(x == INF) continue;
			for(auto e : gw[i]) if(x + e.second <= T)
				amin(dp[e.first][j + 1], make_pair(x + e.second, i));
		}
		int j = n;
		while(dp[n - 1][j].first == INF)
			-- j;
		vi ans;
		for(int i = n - 1; i != -1; ) {
			ans.push_back(i);
			i = dp[i][j].second;
			-- j;
		}
		printf("%d\n", (int)ans.size());
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}