#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

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
			for (Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if (u == t) d = level[u];
				each(e, g[u]) if (e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for (Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while (1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if (f == 0) break;
				total += f; update = true;
			}
		} while (update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if (u == t || f == 0) return f;
		Index lv = level[u];
		if (lv == -1) return 0;
		level[u] = -1;
		for (; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if (level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if (l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<array<int, 2>> edges(m);
		rep(i, m) {
			int x; int y;
			scanf("%d%d", &x, &y), -- x, -- y;
			edges[i] = { x, y };
		}
		vector<pair<int, int>> ans(m);
		int lo = 0, up = m + 1;
		while (up - lo > 0) {
			int mid = (lo + up) / 2;
			MaximumFlow mf;
			int src = m + n, dst = src + 1;
			mf.init(dst + 1);
			rep(i, m)
				mf.add(src, i, 1);
			rep(i, m) for(int j : edges[i])
				mf.add(i, m + j, 1);
			rep(j, n)
				mf.add(m + j, dst, mid);
			int f = mf.maximumFlow(src, dst);
			if (f == m) {
				up = mid;
				rep(i, m) {
					for (auto e : mf.g[i]) if (e.capacity == 0 && m <= e.to && e.to < m + n) {
						int x = e.to - m;
						auto p = make_pair(edges[i][0], edges[i][1]);
						if (p.first != x)
							swap(p.first, p.second);
						ans[i] = p;
					}
				}
			} else {
				lo = mid + 1;
			}
		}
		printf("%d\n", up);
		for (int i = 0; i < (int)ans.size(); ++ i)
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	return 0;
}