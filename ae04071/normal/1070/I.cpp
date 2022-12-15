#include <bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
typedef pair<int,int> pii;

struct Edmond {
	int n;
	vector<vector<pii> > edg;
	vector<vector<int> > rev;
	Edmond(int n) : n(n) {
		edg = vector<vector<pii> >(n + 1);
		rev = vector<vector<int> >(n + 1);
	}
	void addEdge(int u, int v, int r) {
		edg[u].push_back({v, r});
		edg[v].push_back({u, 0});
		rev[u].push_back(sz(edg[v]) - 1);
		rev[v].push_back(sz(edg[u]) - 1);
	}
	int flow(int src, int dst) {
		int ret = 0;
		while(1) {
			vector<pair<int,int> > par(n + 1, {-1,-1});
			queue<int> q;
			q.push(src);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				for(int i=0; i<sz(edg[u]); i++) {
					auto& it = edg[u][i];
					if(it.second > 0 && par[it.first].first == -1) {
						par[it.first] = {u,i};
						q.push(it.first);
					}
				}
			}
			if(par[dst].first == -1) break;
			int mn = 1e9;
			for(int u=dst; u!=src; u=par[u].first)
				mn = min(mn, edg[par[u].first][par[u].second].second);
			for(int u=dst; u!=src; u=par[u].first) {
				edg[par[u].first][par[u].second].second -= mn;
				edg[u][rev[par[u].first][par[u].second]].second += mn;
			}
			ret += mn;
		}
		//printf("ret:%d\n", ret);
		return ret;
	}
};

int T;
int n, m, K, deg[601], ans[601];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &K);
		Edmond mf(n + m + 10);
		for(int i=1; i<=n; i++) deg[i] = 0;
		for(int i=1; i<=m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			mf.addEdge(u, n+i, 1);
			mf.addEdge(v, n+i, 1);
			mf.addEdge(n+i, n+m+1, 1);
			deg[u]++;
			deg[v]++;
		}

		bool flag = 1;
		for(int i=1; i<=n; i++){
			if(deg[i] > 2*K) { flag = 0; break; }
			mf.addEdge(0, i, max(0, 2*K-deg[i]));
		}
		if(!flag) {
			for(int i=1; i<=m; i++) printf("0 ");
			puts("");
			continue;
		}
		if(mf.flow(0, n+m+1) == m) {
			int cur = 1;
			for(int i=1; i<=n; i++) {
				vector<int> v1, v2;
				for(auto& it : mf.edg[i]) {
					if(it.first == 0) continue;
					//printf("%d\n", it.first);
					if(it.second == 0) v1.push_back(it.first - n);
					else v2.push_back(it.first - n);
				}
				int j = 0;
				for(int k=0; k<v2.size(); k+=2) {
					ans[v2[k]] = cur;
					if(k+1 < v2.size()) ans[v2[k+1]] = cur;
					cur++;
				}
			}
			for(int i=1; i<=m; i++) printf("%d ", ans[i]);
			puts("");
		} else {
			for(int i=1; i<=m; i++) printf("0 ");
			puts("");
		}
	}
	return 0;
}