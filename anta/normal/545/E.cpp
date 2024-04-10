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

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vpii> g(n);
		vi weights(m);
		rep(i, m) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			g[u].push_back(mp(v, i));
			g[v].push_back(mp(u, i));
			weights[i] = w;
		}
		int src;
		scanf("%d", &src), -- src;
		vector<bool> vis(n, false);
		vector<ll> dist(n, INFL);
		vi parentedge(n, -1);
		priority_queue<pair<ll,int> > q;
		q.push(mp(-0LL, src));
		dist[src] = 0;
		while(!q.empty()) {
			int i = q.top().second; q.pop();
			if(vis[i]) continue;
			vis[i] = true;
			each(j, g[i]) {
				ll &d = dist[j->first], e = dist[i] + weights[j->second];
				int &k = parentedge[j->first];
				if(d > e) {
					d = e;
					k = j->second;
					q.push(mp(-d, j->first));
				}else if(d == e && weights[k] > weights[j->second]) {
					k = j->second;
				}
			}
		}
		vi ans;
		ll total = 0;
		rep(i, n) if(parentedge[i] != -1) {
			ans.push_back(parentedge[i]);
			total += weights[parentedge[i]];
		}
		sort(all(ans));
		cout << total << endl;
		rep(i, ans.size()) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}