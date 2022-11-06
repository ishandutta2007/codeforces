#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <set>
#include <climits>
#include <functional>
#include <queue>

int N, M, L, S, T;

std::unordered_map<int, int> adj[1000];
std::vector<std::pair<int, int>> adj_e;

long long dist[1000];

long long dijkstra() {
	std::fill(dist, dist + N, LLONG_MAX);
	dist[S] = 0;
	std::priority_queue <std::pair<long long, int>, std::vector <std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
	pq.push({ 0, S });
	while (!pq.empty()) {
		int u = pq.top().second;
		if (u == T)
			break;
		long long d = pq.top().first;
		pq.pop();
		if (d != dist[u])
			continue;
		for (auto dest : adj[u]) {
			int v = dest.first;
			int w = dest.second;
			d = dist[u] + w;
			if (d < dist[v]) {
				dist[v] = d;
				pq.push({ d, v });
			}
		}
	}
	return dist[T];
}

long long f(int count) {
	for (int i = 0; i < count; ++i) {
		int u = adj_e[i].first;
		int v = adj_e[i].second;
		adj[u][v] = adj[v][u] = 1;
	}
	for (int i = count; i < adj_e.size(); ++i) {
		int u = adj_e[i].first;
		int v = adj_e[i].second;
		adj[u][v] = adj[v][u] = L + 1;
	}
	return dijkstra();
}

void no() {
	std::cout << "NO";
	exit(0);
}

void yes() {
	std::cout << "YES";
	for (int u = 0; u < N; ++u) {
		for (auto x : adj[u]) {
			int v = x.first;
			int w = x.second;
			if (u < v)
				std::cout << "\n" << u << " " << v << " " << w;
		}
	}
	exit(0);
}

int main() {
	std::cin >> N >> M >> L >> S >> T;
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		if (w == 0)
			adj_e.push_back({ u, v });
		else {
			adj[u][v] = w;
			adj[v][u] = w;
		}
	}

	if (!adj_e.size()) {
		if (f(0) == L)
			yes();
		no();
	}
	int lo = 0;
	int hi = adj_e.size();

	long long result;

	// bs first value x / f(x) <= L
	while (lo < hi) {
		int mid = ((lo + hi) >> 1);
		result = f(mid);
		if (result == L)
			yes();
		if (result < L)
			hi = mid;
		else {
			lo = mid + 1;
			if (lo == hi) {
				result = f(lo);
				break;
			}
		}
	}

	if (lo == adj_e.size()) {
		if (result > L)
			no();
		if (result == L)
			yes();
	}
	else if (lo == 0)
		no();

	int u = adj_e[lo - 1].first;
	int v = adj_e[lo - 1].second;
	adj[u][v] = adj[v][u] = 1 + L - result;
	yes();

	return 0;
}