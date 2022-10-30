#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)

struct MaximumFlow {
	typedef int Index;
	typedef int Flow;
	static const Flow InfCapacity = INF;
	struct Edge {
		Index to;
		Flow capacity;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = capacity;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	//g
	Flow maximumFlow(int s, int t) {
		int n = g.size();
		vector<Index> level(n);
		Flow total = 0; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for(Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if(u == t) d = level[u];
				each(e, g[u]) if(e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for(Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while(1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if(f == 0) break;
				total += f; update = true;
			}
		} while(update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if(u == t || f == 0) return f;
		Index lv = level[u];
		if(lv == -1) return 0;
		level[u] = -1;
		for(; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if(level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if(l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};

void dfs(int i, int p, vector<int> &vis, int &num, vpii &path, const vector<vpii> &gw, vector<vi> &cycles, vi &treeEdges) {
	vis[i] = num ++;
	for(auto e : gw[i]) {
		int j = e.first;
		if(j == p) continue;
		if(vis[j] == -1) {
			path.push_back(e);
			dfs(j, i, vis, num, path, gw, cycles, treeEdges);
			if(path.back().second != -1)
				treeEdges.push_back(path.back().second);
			path.pop_back();
		} else if(vis[i] > vis[j]) {
			int k = (int)path.size();
			while(k > 0 && path[k - 1].first != j) -- k;
			vi cycle;
			for(; k != path.size(); ++ k) {
				cycle.push_back(path[k].second);
				path[k].second = -1;
			}
			cycle.push_back(e.second);
			cycles.emplace_back(cycle);
		}
	}
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<pair<int, int> > > gw(n);
		for(int i = 0; i < m; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v, -- w;
			gw[u].push_back(make_pair(v, w));
			gw[v].push_back(make_pair(u, w));
		}
		vector<vi> cycles;
		vi treeEdges;
		{
			vector<int> vis(n, -1);
			vpii path;
			int num = 0;
			dfs(0, -1, vis, num, path, gw, cycles, treeEdges);
		}
		MaximumFlow mf;
		int src = m + cycles.size(), dst = src + 1;
		mf.init(dst + 1);
		rep(c, m)
			mf.add(src, c, 1);
		for(int c : treeEdges)
			mf.add(c, dst, 1);
		rep(i, cycles.size()) {
			const vi &cycle = cycles[i];
			for(int c : cycle)
				mf.add(c, m + i, 1);
			mf.add(m + i, dst, (int)cycle.size() - 1);
		}
		int ans = mf.maximumFlow(src, dst);
		printf("%d\n", ans);
	}
	return 0;
}