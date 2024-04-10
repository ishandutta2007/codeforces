#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5 + 9;
vector<int> adj[MaxN + 9];
bool visited[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);

	while (!pq.empty()) {
		const int u = pq.top();
		pq.pop();
		if (visited[u])
			continue;
		visited[u] = 1;
		cout << u << ' ';

		for (const int &v : adj[u])
			if (!visited[v])
				pq.push(v);
	}
	return 0;
}