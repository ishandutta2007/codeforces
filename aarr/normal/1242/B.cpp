#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int N = 100 * 1000 + 5;
int nparts;

set <int> adj[N];
set <int> s;
bool mark[N];
queue <int> q;
void bfs(int v) {
	q.push(v);
	while (q.size()) {
		int v = q.front();
	//	cout << v << endl;
		s.erase(v);
		q.pop();
		mark[v] = true;
		int u = 0;
		while (s.upper_bound(u) != s.end()) {
			u = *s.upper_bound(u);
		//	cout << v << " " << u << endl;
			if (adj[v].find(u) == adj[v].end() && !mark[u]) {
				q.push(u);
				s.erase(u);
				mark[u] = true;
			}
		}
	}
	
}
int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			bfs(i);
			nparts++;
		}
	}
	cout << nparts - 1 << endl;
	return 0;
}