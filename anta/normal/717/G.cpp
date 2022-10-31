#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct MinimumCostMaximumFlow {
	typedef int Index; typedef int Flow; typedef int Cost;
	static const Flow InfCapacity = INF; static const Cost InfCost = INF;
	struct Edge {
		Index to; Index rev;
		Flow capacity; Cost cost;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity = InfCapacity, Cost cost = Cost()) {
		add(i, j, capacity, cost);
		add(j, i, capacity, cost);
	}
	pair<Cost, Flow> minimumCostMaximumFlow(Index s, Index t, Flow f = InfCapacity, bool useSPFA = false) {
		int n = g.size();
		vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prevEdge(n);
		pair<Cost, Flow> total = make_pair(0, 0);
		vector<Cost> potential(n);
		while(f > 0) {
			fill(dist.begin(), dist.end(), InfCost);
			if(useSPFA || total.second == 0) {
				deque<Index> q;
				q.push_back(s); dist[s] = 0; vector<bool> inqueue(n);
				while(!q.empty()) {
					Index i = q.front(); q.pop_front(); inqueue[i] = false;
					for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
						const Edge &e = g[i][ei]; Index j = e.to; Cost d = dist[i] + e.cost;
						if(e.capacity > 0 && d < dist[j]) {
							if(!inqueue[j]) {
								inqueue[j] = true;
								q.push_back(j);
							}
							dist[j] = d; prev[j] = i; prevEdge[j] = ei;
						}
					}
				}
			} else {
				vector<bool> vis(n);
				priority_queue<pair<Cost, Index> > q;
				q.push(make_pair(-0, s)); dist[s] = 0;
				while(!q.empty()) {
					Index i = q.top().second; q.pop();
					if(vis[i]) continue;
					vis[i] = true;
					for(Index ei = 0; ei < (Index)g[i].size(); ei ++) {
						const Edge &e = g[i][ei];
						if(e.capacity <= 0) continue;
						Index j = e.to; Cost d = dist[i] + e.cost + potential[i] - potential[j];
						if(dist[j] > d) {
							dist[j] = d; prev[j] = i; prevEdge[j] = ei;
							q.push(make_pair(-d, j));
						}
					}
				}
			}
			if(dist[t] == InfCost) break;
			if(!useSPFA) for(Index i = 0; i < n; i ++) potential[i] += dist[i];

			Flow d = f; Cost distt = 0;
			for(Index v = t; v != s; ) {
				Index u = prev[v]; const Edge &e = g[u][prevEdge[v]];
				d = min(d, e.capacity); distt += e.cost; v = u;
			}
			f -= d; total.first += d * distt; total.second += d;
			for(Index v = t; v != s; v = prev[v]) {
				Edge &e = g[prev[v]][prevEdge[v]];
				e.capacity -= d; g[e.to][e.rev].capacity += d;
			}
		}
		return total;
	}
};

int main() {
	int n;
	while(~scanf("%d", &n)) {
		char S[501];
		scanf("%s", S);
		MinimumCostMaximumFlow mcmf;
		mcmf.init(n + 1);
		rep(i, n)
			mcmf.add(i, i + 1);
		int m;
		scanf("%d", &m);
		rep(i, m) {
			char W[100001];
			scanf("%s", W);
			int p;
			scanf("%d", &p);
			int len = strlen(W);
			rer(i, 0, n - len) {
				int j = 0;
				for(; j < len && S[i + j] == W[j]; ++ j);
				if(j == len)
					mcmf.add(i, i + len, 1, -p);
			}
		}
		int x;
		scanf("%d", &x);
		int ans = -mcmf.minimumCostMaximumFlow(0, n, x).first;
		printf("%d\n", ans);
	}
	return 0;
}