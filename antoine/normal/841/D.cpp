#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <map> 
#include <set>

// D
//http://codeforces.com/contest/841/problem/D

struct Link { int v, i; };
int n, m;
int d[300001];
std::pair<bool, bool> ans[300001];
std::vector<Link> adj[300001];
std::vector<Link> children[300001];
bool visited[300001];

std::set<int> edgesAdded;

void dfs1(int u) {
	visited[u] = true;
	ans[u] = { false , d[u] == -1 }; // do i miss an edge | am i flexible
	
	int degree = 0;

	for (auto &&e : adj[u]) {
		int v = e.v;
		if (visited[v]) continue;
		children[u].push_back({ v, e.i });
		dfs1(v);
		if (ans[v].second)
			ans[u].second = true;
		else if (ans[v].first) {
			edgesAdded.insert(e.i);
			++degree;
		}
	}

	if (!ans[u].second)
		ans[u].first = (degree & 1) != d[u];
}

void dfs2(int u, int degree) {
	for (auto &&e : children[u]) {
		int v = e.v;
		if (!ans[v].second)
			degree += ans[v].first;
	}

	bool missing = d[u] != -1 && (degree & 1) != d[u];
	for (auto &&e : children[u]) {
		int v = e.v;
		if (!ans[v].second)
			dfs2(v, ans[v].second);
		else {
			if (missing)
				edgesAdded.insert(e.i);
			dfs2(v, missing);
			missing = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> d[i];
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back({ v, i });
		adj[v].push_back({ u, i });
	}

	std::memset(visited, false, sizeof visited);
	dfs1(1);
	if (ans[1].first && !ans[1].second) {
		std::cout << -1;
		return 0;
	}
	
	dfs2(1, 0);

	std::cout << edgesAdded.size();
	for (int i : edgesAdded)
		std::cout << '\n' << i;
	return 0;
}