#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct MaximumFlow {
	typedef int Index;
	typedef int Flow;
	static const Flow InfCapacity = INF;
	struct Edge {
		Index to;
		Flow capacity;
		Flow demand;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity, Flow demand = 0) {
		Edge e, f;
		e.to = j, f.to = i;
		e.capacity = capacity, f.capacity = 0;
		e.demand = demand, f.demand = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}

	Flow maximumFlow(int s, int t, bool resolving = false) {
		Flow D = resolving ? 0 : resolveDemand(s, t);
		if(D == -1) return D;
		int n = g.size();
		vector<Index> level(n);
		Flow total = D; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for(Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if(u == t) d = level[u];
				for(const Edge &e : g[u]) if(e.capacity > 0 && level[e.to] == -1)
					q.push(e.to), level[e.to] = level[u] + 1;
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

	Flow resolveDemand(Index orgsrc, Index orgdst) {
		assert(orgsrc != orgdst);
		Index n = (Index)g.size();
		for(Index u = 0; u < n; ++ u) {
			for(const Edge &e : g[u]) {
				if(e.capacity < e.demand)
					return -1;
			}
		}
		vector<Index> degree(n);
		for(Index u = 0; u < n; ++ u)
			degree[u] = (Index)g[u].size();
		Index newsrc = n, newdst = newsrc + 1;
		Index src = newdst + 1, dst = src + 1;
		g.resize(dst + 1);
		for(Index u = 0; u < n; ++ u) {
			Flow in = 0, out = 0;
			for(const Edge &e : g[u]) {
				out += e.demand;
				in += g[e.to][e.rev].demand;
			}
			if(in != 0)
				add(newsrc, u, in);
			if(out != 0)
				add(u, newdst, out);
		}
		for(Index u = 0; u < n; ++ u) {
			for(Edge &e : g[u])
				e.capacity -= e.demand;
		}
		add(src, orgsrc, InfCapacity);
		add(orgdst, dst, InfCapacity);
		add(dst, src, InfCapacity);
		maximumFlow(newsrc, newdst, true);
		bool saturated = true;
		for(const Edge &e : g[newsrc])
			saturated &= e.capacity == 0;
		for(const Edge &e : g[newdst])
			saturated &= g[e.to][e.rev].capacity == 0;
		assert(g[src].size() == 2 && g[src][1].to == dst);
		Flow flow = g[src][1].capacity;
		for(Index u = 0; u < n; ++ u)
			g[u].resize(degree[u]);
		g.resize(n);
		if(!saturated)
			return -1;
		for(Index u = 0; u < n; ++ u) {
			for(Edge &e : g[u])
				e.demand = 0;
		}
		return flow;
	}

private:
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


int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		int cost[2];
		scanf("%d%d", &cost[0], &cost[1]);
		vpii xy(n);
		vi poses[2];
		rep(i, n) {
			int x; int y;
			scanf("%d%d", &x, &y);
			xy[i] = { x,y };
			poses[0].push_back(x);
			poses[1].push_back(y);
		}
		vector<pii> lines[2];
		rep(i, m) {
			int t; int l; int d;
			scanf("%d%d%d", &t, &l, &d), -- t;
			lines[t].emplace_back(l, d);
		}
		rep(k, 2) {
			sort(poses[k].begin(), poses[k].end());
			poses[k].erase(unique(poses[k].begin(), poses[k].end()), poses[k].end());
		}
		vector<int> deg[2];
		rep(k, 2)
			deg[k].assign(poses[k].size(), 0);
		vpii edges(n);
		rep(i, n) {
			int a = (int)(lower_bound(poses[0].begin(), poses[0].end(), xy[i].first) - poses[0].begin());
			int b = (int)(lower_bound(poses[1].begin(), poses[1].end(), xy[i].second) - poses[1].begin());
			++ deg[0][a], ++ deg[1][b];
			edges[i] = { a, b };
		}
		vector<pair<int, int>> bounds[2];
		rep(k, 2) {
			bounds[k].resize(poses[k].size());
			rep(i, poses[k].size())
				bounds[k][i] = { 0, deg[k][i] };
		}
		rep(k, 2) for(auto l : lines[k]) {
			auto it = lower_bound(poses[k].begin(), poses[k].end(), l.first);
			if(it == poses[k].end() || *it != l.first) continue;
			int i = (int)(it - poses[k].begin());
			int p = deg[k][i], q = l.second;
			if(q >= p) continue;
			//-q <= 2x - p <= q
			//p - q <= 2x <= p + q
			int lo = (p - q + 1) / 2;
			int up = (p + q) / 2;
			amax(bounds[k][i].first, lo);
			amin(bounds[k][i].second, up);
		}
		int A = (int)poses[0].size(), B = (int)poses[1].size();
		MaximumFlow mf;
		int src = A + B, dst = src + 1;
		mf.init(dst + 1);
		rep(i, A) {
			int l, u;
			tie(l, u) = bounds[0][i];
			mf.add(src, i, u, l);
		}
		rep(i, B) {
			int l, u;
			tie(l, u) = bounds[1][i];
			mf.add(A + i, dst, u, l);
		}
		map<pair<int, int>, vector<int>> points;
		rep(i, n) {
			int a, b; tie(a, b) = edges[i];
			mf.add(a, A + b, 1);
			points[{a, b}].push_back(i);
		}

		int flow = mf.maximumFlow(src, dst);
		if(flow == -1) {
			puts("-1");
			continue;
		}
		char color[2] = { 'r', 'b' };
		if(cost[0] > cost[1]) {
			swap(cost[0], cost[1]);
			swap(color[0], color[1]);
		}
		ll ans = (ll)flow * cost[0] + (ll)(n - flow) * cost[1];
		printf("%lld\n", ans);
		string config(n, '?');
		rep(a, A) for(auto e : mf.g[a]) {
			int b = e.to - A;
			if(!(0 <= b && b < B)) continue;
			assert(e.capacity == 0 || e.capacity == 1);
			vi &v = points[{a, b}];
			config[v.back()] = color[e.capacity];
			v.pop_back();
		}
		puts(config.c_str());
	}
	return 0;
}