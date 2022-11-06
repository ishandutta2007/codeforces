#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

/*
long long gcd(long long a, long long b) {
	return 0LL;
}

long long mod = 1000000007LL;
*/

double ans = 0;

std::vector<int> adj[100001];
int dist[100001];
double p[100001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::memset(dist, -1, sizeof dist);
	std::queue<int> nodes;
	nodes.push(1);
	dist[1] = 0;
	p[1] = 1;
	while (!nodes.empty()) {
		int u = nodes.front();
		nodes.pop();
		int count = 0;
		for (int v : adj[u])
			if (dist[v] == -1)
				++count;
		if (count == 0)
			ans += p[u] * dist[u];
		else {
			for (int v : adj[u])
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					p[v] = p[u] / count;
					nodes.push(v);
				}
		}
	}
	printf("%.*f", 15, ans);
	return 0;
}