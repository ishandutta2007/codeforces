#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

void dijkstra(int src, const vector<vpii> &gw, vi &dist, vi *prev = nullptr) {
	int n = (int)gw.size();
	priority_queue<pii, vpii, greater<pii>> pq;
	dist.assign(n, INF);
	vector<bool> vis(n);
	dist[src] = 0;
	if(prev) prev->assign(n, -1);
	pq.push(make_pair(0, src));
	while(!pq.empty()) {
		int i = pq.top().second; pq.pop();
		if(vis[i]) continue;
		vis[i] = true;
		for(auto e : gw[i]) {
			int j = e.first;
			int nd = dist[i] + e.second;
			if(dist[j] > nd) {
				dist[j] = nd;
				if(prev) (*prev)[j] = i;
				pq.push(make_pair(nd, j));
			}
		}
	}
}

int main() {
	int n; int m; int L;
	while(~scanf("%d%d%d", &n, &m, &L)) {
		int src; int dst;
		scanf("%d%d", &src, &dst);
		vector<vector<pair<int, int> > > gw(n);
		vpii eis;
		for(int i = 0; i < m; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if(w == 0) {
				w = INF;
				eis.emplace_back(u, (int)gw[u].size());
				eis.emplace_back(v, (int)gw[v].size());
			}
			gw[u].push_back(make_pair(v, w));
			gw[v].push_back(make_pair(u, w));
		}
		vi dist;
		dijkstra(src, gw, dist);
		if(dist[dst] < L) {
			puts("NO");
			continue;
		}
		for(auto e : eis)
			gw[e.first][e.second].second = 1;
		dijkstra(src, gw, dist);
		if(dist[dst] > L) {
			puts("NO");
			continue;
		}
		int lo = 1, up = (int)1e9;
		while(up - lo > 0) {
			int mid = (lo + up + 1) / 2;
			for(auto e : eis)
				gw[e.first][e.second].second = mid;
			dijkstra(src, gw, dist);
			if(dist[dst] <= L)
				lo = mid;
			else
				up = mid - 1;
		}
		vi distT, prev;
		for(auto e : eis)
			gw[e.first][e.second].second = lo;
		dijkstra(src, gw, dist, &prev);
		dijkstra(dst, gw, distT);
		while(dist[dst] < L) {
			rep(ei, eis.size()) {
				auto e1 = eis[ei], e2 = eis[ei ^ 1];
				pii &p = gw[e1.first][e1.second], &q = gw[e2.first][e2.second];
				while(prev[p.first] == q.first && dist[dst] == (ll)dist[q.first] + p.second + distT[p.first] && dist[dst] < L) {
					++ p.second, ++ q.second;
					dijkstra(src, gw, dist, &prev);
					dijkstra(dst, gw, distT);
				}
			}
		}
		assert(dist[dst] == L);
		puts("YES");
		rep(i, n) for(auto e : gw[i]) if(i < e.first)
			printf("%d %d %d\n", i, e.first, e.second);
	}
	return 0;
}