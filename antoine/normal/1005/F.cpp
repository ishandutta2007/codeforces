#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct Edge {
	int id, v;
};

int n, m, k;
vector<Edge> adj[(int)2e5];
int dist[(int)2e5];
int ans[(int)2e5]= { 0 };

void bfs() {
	memset(dist, -1, sizeof dist);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(Edge &edge : adj[u])
			if (dist[edge.v] == -1) {
				dist[edge.v] = dist[u] + 1;
				q.push(edge.v);
			}
	}
}


void f(int i, int &res) {
	if (res >= k) return;
	if (i == n)
		res++;
	else {
		for (auto &&edge : adj[i])
			if (dist[i] == dist[edge.v] + 1)
				f(i + 1, res);
	}
}

void g(int i) {
	if (!k) return;
	if (i == n) {
		--k;
		for (int i = 0; i < m; ++i)
			cout << ans[i];
		cout << '\n';
	}	
	else {
		for(auto &&edge : adj[i])
			if (dist[i] == dist[edge.v] + 1) {
				ans[edge.id] = 1;
				g(i + 1);
				ans[edge.id] = 0;
			}
	}
}


int  main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back({ i, b });
		adj[b].push_back({ i, a });
	}


	bfs();

	int res = 0;
	f(1, res);
	cout << min(k, res) << '\n';
	g(1);
	return 0;
}