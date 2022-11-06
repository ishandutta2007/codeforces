#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <vector>

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a%b); }

long long n;
long long a[200001];
int ans[200001];
std::vector<long long> adj[200001];

void dfs(int u, int p, int g, std::set<int> s) {
	std::set<int> S;
	S.insert(g);
	for (int i : s)
		S.insert(gcd(i, a[u]));
	g = gcd(g, a[u]);
	ans[u] = *(S.rbegin());
	for (int v : adj[u])
		if(v != p)
			dfs(v, u, g, S);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (long long i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (long long i = 1; i < n; ++i) {
		long long x, y;
		std::cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (long long v : adj[1]) {
		dfs(v, 1, a[1], { 0 });
	}
	std::cout << a[1];
	for (long long i = 2; i <= n; ++i)
		std::cout << ' ' << ans[i];
	return 0;
}