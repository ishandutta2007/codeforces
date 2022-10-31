#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }



class EvalLink {
public:
	typedef pair<int, int> Val;
	static Val minusInfinity() { return Val(); }
private:

public:
	void init(int n) {
		parent.assign(n + 1, 0);
		child.assign(n + 1, 0);
		size.assign(n + 1, 1);
		size[0] = 0;
		min.assign(n + 1, minusInfinity());
	}

	void set(int v, const Val &val) {
		min[v + 1] = val;
	}

	Val eval(int v) {
		++ v;
		if (parent[v] == 0)
			return min[v];
		compress(v);
		return std::min(min[parent[v]], min[v]);
	}

	void link(int v, int w) {
		++ v, ++ w;
		assert(parent[w] == 0);
		int s = w;
		while (min[w] < min[child[s]]) {
			if (size[s] + size[child[child[s]]] >= 2 * size[child[s]]) {
				parent[child[s]] = s;
				child[s] = child[child[s]];
			} else {
				size[child[s]] = size[s];
				s = parent[s] = child[s];
			}
		}
		min[s] = min[w];
		size[v] = size[v] + size[w];
		if (size[v] < 2 * size[w])
			swap(s, child[v]);
		while (s != 0) {
			parent[s] = v;
			s = child[s];
		}
	}

private:
	void compress(int v) {
		assert(parent[v] != 0);
		if (parent[parent[v]] != 0) {
			compress(parent[v]);
			if (min[parent[v]] < min[v])
				min[v] = min[parent[v]];
			parent[v] = parent[parent[v]];
		}
	}

	vector<int> parent, child, size;
	vector<Val> min;
};

class DominatorTree {
public:
	void build(const vector<vector<int>> &graph, int root) {
		step1(graph, root);
		step2and3(graph, root);
		step4();
	}

	int getIdom(int u) const { return dom[u]; }

private:
	void step1(const vector<vector<int>> &graph, int root) {
		pred.assign(graph.size(), vector<int>());
		semi.assign(graph.size(), -1);
		parent.assign(graph.size(), -1);
		vertex.clear();
		stk.emplace_back(root, 0);
		while (!stk.empty()) {
			int v = stk.back().first;
			int ei = stk.back().second;
			stk.pop_back();
			if (ei == 0) {
				semi[v] = (int)vertex.size();
				vertex.push_back(v);
			}
			if (ei != graph[v].size()) {
				stk.emplace_back(v, ei + 1);
				int w = graph[v][ei];
				if (semi[w] == -1) {
					parent[w] = v;
					stk.emplace_back(w, 0);
				}
				pred[w].push_back(v);
			}
		}
	}

	void step2and3(const vector<vector<int>> &graph, int root) {
		bucket.assign(graph.size(), vector<int>());
		dom.assign(graph.size(), -1);
		evalLink.init((int)graph.size());
		for (int w : vertex)
			evalLink.set(w, make_pair(semi[w], w));
		for (int i = (int)vertex.size() - 1; i > 0; -- i) {
			int w = vertex[i];
			for (int v : pred[w]) {
				int u = evalLink.eval(v).second;
				if (semi[u] < semi[w])
					semi[w] = semi[u];
			}
			evalLink.set(w, make_pair(semi[w], w));
			bucket[vertex[semi[w]]].push_back(w);
			evalLink.link(parent[w], w);
			for (int v : bucket[parent[w]]) {
				int u = evalLink.eval(v).second;
				dom[v] = semi[u] < semi[v] ? u : parent[w];
			}
			bucket[parent[w]].clear();
		}
	}

	void step4() {
		for (int i = 1; i < (int)vertex.size(); ++ i) {
			int w = vertex[i];
			if (dom[w] != vertex[semi[w]])
				dom[w] = dom[dom[w]];
		}
		dom[vertex[0]] = -1;
	}

	vector<int> parent;
	vector<vector<int>> pred;
	vector<int> semi;
	vector<int> vertex;
	vector<vector<int>> bucket;
	vector<int> dom;
	vector<pair<int, int>> stk;
	EvalLink evalLink;
};


vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	int n; int m; int s;
	while (~scanf("%d%d%d", &n, &m, &s)) {
		-- s;
		vector<vector<pair<int, int> > > gw(n);
		for (int i = 0; i < m; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			gw[u].push_back(make_pair(v, w));
			gw[v].push_back(make_pair(u, w));
		}
		vector<ll> dist(n, INFL);
		{
			priority_queue<pair<ll, int>> pq;
			vector<bool> vis(n);
			pq.push(make_pair(0LL, s));
			while (!pq.empty()) {
				ll d = -pq.top().first;
				int i = pq.top().second;
				pq.pop();
				if (vis[i]) continue;
				dist[i] = d;
				vis[i] = true;
				for (auto e : gw[i])
					pq.push(make_pair(-(d + e.second), e.first));
			}
		}
		vector<vi> dag(n);
		rep(i, n) if (dist[i] < INFL) {
			for (auto e : gw[i]) if (dist[i] + e.second == dist[e.first])
				dag[i].push_back(e.first);
		}
		DominatorTree dt;
		dt.build(dag, s);
		vector<vi> tree(n);
		rep(i, n) {
			int p = dt.getIdom(i);
			if (p != -1) {
				tree[p].push_back(i);
				tree[i].push_back(p);
			}
		}
		tree_getorder(tree, s);
		vector<int> subtsize(n, 1);
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		int ans = 0;
		for (int i : tree[s])
			amax(ans, subtsize[i]);
		printf("%d\n", ans);
	}
	return 0;
}