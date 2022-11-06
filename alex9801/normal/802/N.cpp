#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 2222;
typedef pair<lint, lint> pi;
int a[MAXN], b[MAXN], n, k;

struct mincostflow{
	struct edg{ int pos, cap, rev, cost; };
	vector<edg> gph[MAXN];

	void add_edge(int s, int e, int x, int c){
		gph[s].push_back({e, x, (int)gph[e].size(), c});
		gph[e].push_back({s, 0, (int)gph[s].size()-1, -c});
	}

	lint phi[MAXN], inque[MAXN], dist[MAXN];

	void prep(int src, int sink){
		memset(phi, 0x3f, sizeof(phi));
		memset(dist, 0x3f, sizeof(dist));
		queue<int> que;
		que.push(src);
		inque[src] = 1;
		while(!que.empty()){
			int x = que.front();
			que.pop();
			inque[x] = 0;
			for(auto &i : gph[x]){
				if(i.cap > 0 && phi[i.pos]> phi[x] + i.cost){
					phi[i.pos] = phi[x] + i.cost;
					if(!inque[i.pos]){
						inque[i.pos] = 1;
						que.push(i.pos);
					}
				}
			}
		}
		for(int i=0; i<MAXN; i++){
			for(auto &j : gph[i]){
				if(j.cap>0) j.cost += phi[i] - phi[j.pos];
			}
		}
		priority_queue<pi, vector<pi>, greater<pi> > pq;
		pq.push(pi(0, src));
		dist[src] = 0;
		while(!pq.empty()){
			auto x = pq.top(); pq.pop();
			if(dist[x.second] != x.first) continue;
			for(auto &i : gph[x.second]){
				if(i.cap > 0 && dist[i.pos] > x.first + i.cost){
					dist[i.pos] = x.first + i.cost;
					pq.push(pi(dist[i.pos], i.pos));
				}
			}
		}
	}

	bool vis[MAXN];
	int ptr[MAXN];

	int dfs(int pos, int sink, int flow){
		vis[pos] = 1;
		if(pos==sink) return flow;
		for(; ptr[pos] < gph[pos].size(); ptr[pos]++){
			edg &i = gph[pos][ptr[pos]];
			if(!vis[i.pos] && dist[i.pos] == i.cost + dist[pos] &&
				i.cap > 0){
				int ret = dfs(i.pos, sink, min(i.cap, flow));
				if(ret != 0){
					i.cap -= ret;
					gph[i.pos][i.rev].cap += ret;
					return ret;
				}
			}
		}
		return 0;
	}

	lint match(int src, int sink, lint las){
		prep(src, sink);
		for(int i=0; i<=sink; i++) dist[i] += phi[sink] - phi[src];
		lint ret = 0;
		while(las){
			memset(ptr, 0, sizeof(ptr));
			memset(vis, 0, sizeof(vis));
			lint tmp = 0;
			while(las && (tmp = dfs(src, sink, 1e9))){
				ret += dist[sink] * min(tmp, las);
				las -= min(las, tmp);
				memset(vis, 0, sizeof(vis));
			}
			tmp = 1e16;
			for(int i=0; i<=sink; i++){
				if(vis[i]){
					for(auto &j : gph[i]){
						if(j.cap > 0 && !vis[j.pos]){
							tmp = min(tmp, dist[i] + j.cost - dist[j.pos]);
						}
					}
				}
			}
			if(tmp > 1e15) break;
			for(int i=0; i<=sink; i++) if(!vis[i]) dist[i] += tmp;
		}
		return ret;
	}
}mf;

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	for(int i=1; i<=n; i++){
		mf.add_edge(0, i, 1, a[i]);
		mf.add_edge(i, n+1, 1, b[i]);
		if(i > 1) mf.add_edge(i-1, i, k, 0);
	}
	cout << mf.match(0, n+1, k);
}