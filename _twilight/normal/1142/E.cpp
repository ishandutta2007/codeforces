#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int query(int u, int v) {
	printf("? %d %d\n", u, v);
	fflush(stdout);
	scanf("%d", &u);
	return u;
}

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Edge {
	public:
		int ed, nx;

		Edge(int ed = 0, int nx = 0) : ed(ed), nx(nx) {	}
} Edge;

typedef class MapManager {
	public:
		int *h;
		vector<Edge> E; 

		MapManager() {	}
		MapManager(int n) {
			h = new int[(n + 1)];
			pfill(h, h + n + 1, -1);
		}

		void add_edge(int u, int v) {
			E.emplace_back(v, h[u]);
			h[u] = (signed) E.size() - 1;
		}
		Edge& operator [] (int p) {
			return E[p];
		}
} MapManager;

#define pii pair<int, int>

pii make_edge(int u, int v) {
	return (u < v) ? (pii(u, v)) : (pii(v, u)); 
}

int n, m;
MapManager G, GS;

int dfs_clock;
int dfn[N], low[N];
boolean vis[N], ins[N];
stack<int> S;

int fin[N], bel[N], deg[N];
vector<vector<int> > SCC;

void tarjan(int p) {
	dfn[p] = low[p] = ++dfs_clock;
	vis[p] = ins[p] = true;
	S.push(p);
	for (int i = G.h[p], e; ~i; i = G[i].nx) {
		e = G[i].ed;
		if (!vis[e]) {
			tarjan(e);
			low[p] = min(low[p], low[e]);
		} else if (ins[e]) {
			low[p] = min(low[p], dfn[e]);
		} 
	}

	if (low[p] == dfn[p]) {
		int now = -1, sccid = SCC.size();
		SCC.push_back(vector<int>());
//		cerr << sccid << ": ";
		do {
			now = S.top();
			S.pop();
			ins[now] = false;
			bel[now] = sccid;
//			cerr << now << ' ';
			SCC.back().push_back(now);
		} while (now != p);
//		cerr << '\n';
	}
}

inline void init() {
	scanf("%d%d", &n, &m);
	G = MapManager(n + 1);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G.add_edge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tarjan(i);
		}
	}
	
	GS = MapManager(SCC.size());
	for (int i = 1, e; i <= n; i++) {
		e = bel[i];
		for (int _ = G.h[i], eu; ~_; _ = G[_].nx) {
			eu = bel[G[_].ed];
			if (e ^ eu) {
				GS.add_edge(e, eu);
				deg[eu]++;
			}
		}
	}
}

inline void solve() {
	int N = SCC.size();
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (!deg[i]) {
			Q.push(i);
		}
	}
	int id = Q.front();
	int tp = SCC[id][0];
	fin[id]++;
	Q.pop();

	while (!Q.empty()) {
		int nid = Q.front();
		int eu = SCC[nid][fin[nid]++];
		if (query(tp, eu)) {
			if (fin[nid] == (signed) SCC[nid].size()) {
				for (int i = GS.h[nid], o; ~i; i = GS[i].nx) {
					o = GS[i].ed;
					if (!--deg[o]) {
						Q.push(o);
					}
				}
				Q.pop();
			}
		} else {
			Q.pop();
			if (fin[id] == (signed) SCC[id].size()) {
				for (int i = GS.h[id], o; ~i; i = GS[i].nx) {
					o = GS[i].ed;
					if (!--deg[o]) {
						Q.push(o);
					}
				}
			} else {
				Q.push(id);
			}
			swap(id, nid);
			tp = eu;
		}
	}

	printf("! %d\n", tp);
	fflush(stdout);
}

int main() {
	init();
	solve();
	return 0;
}