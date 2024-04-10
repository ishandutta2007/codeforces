#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m; int k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		vector<vector<int> > g(n);
		vector<vector<pair<int, int> > > gw(n);
		for(int i = 0; i < m; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
			gw[u].push_back(make_pair(v, w));
			gw[v].push_back(make_pair(u, w));
		}
		vector<bool> a(n);
		rep(i, k) {
			int x;
			scanf("%d", &x), -- x;
			a[x] = true;
		}
		int ans = INF;
		rep(i, n) if(a[i]) for(auto e : gw[i]) if(!a[e.first])
			amin(ans, e.second);
		if(ans == INF)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}