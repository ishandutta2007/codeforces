#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
	int u, v, w, id;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

int n;
vector<int> adj[(int) 1e5 + 9];
int color[(int) 1e5 + 9];
vector<int> topo;
int pos[(int) 1e5 + 9];

bool dfs(const int u) {
	color[u] = 1;
	for (const int &v : adj[u]) {
		if (!color[v] && dfs(v))
			return true;
		if (color[v] == 1)
			return true;
	}
	color[u] = 2;
	topo.push_back(u);
	return false;
}

bool f(vector<Edge> edges, const int mid) {
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	memset(color, 0, sizeof color);
	topo.clear();

	for (int i = mid; i < (int) edges.size(); ++i)
		adj[edges[i].u].push_back(edges[i].v);

	for (int i = 1; i <= n; ++i)
		if (!color[i] && dfs(i))
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	vector<Edge> edges(m);
	for (int i = 0; i < m; ++i) {
		Edge &e = edges[i];
		e.id = i + 1;
		cin >> e.u >> e.v >> e.w;
	}

	sort(edges.begin(), edges.end());

	int lo = 0;
	int hi = m;
	while (lo < hi) {
		const int mid = (lo + hi) / 2;
		if (f(edges, mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	assert(f(edges, lo));
	for (int i = 0; i < (int) topo.size(); ++i)
		pos[topo[i]] = i;

	edges.erase(edges.begin() + lo, edges.end());
	edges.erase(remove_if(edges.begin(), edges.end(), [&](const Edge &edge) {
		return pos[edge.u] > pos[edge.v];
	}), edges.end());

	if (edges.empty())
		cout << "0 0";
	else {
		cout << edges.back().w << ' ' << edges.size() << '\n';
		for (auto && e : edges)
			cout << e.id << ' ';
	}
	return 0;
}