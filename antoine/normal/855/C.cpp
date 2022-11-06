#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <queue>
#include <functional>

const long long mod = 1000000007;
int n, m, k, X;
std::vector<int> adj[100001];
std::array<long long, 11> dp[100001][3];
const std::array<long long, 11> emptyarr0 = { 0,0,0,0,0,0,0,0,0,0,0 };
const std::array<long long, 11> emptyarr1 = { 0,0,0,0,0,0,0,0,0,0,0 };

const std::array<long long, 11> &dfs(int, int, int);

std::array<long long, 11> f(int u, int parent, const std::vector<int> &options) {
	std::array<long long, 11> res = emptyarr0;
	for (const int &p : options) {
		const auto &temp = dfs(u, parent, p);
		for (int i = 0; i <= X; ++i) {
			res[i] += temp[i];
			res[i] %= mod;
		}
	}
	return res;
}


std::array<long long, 11> merge(const std::array<long long, 11> &a, const std::array<long long, 11> &b) {
	std::array<long long, 11> res = emptyarr0;
	for (int i = 0; i <= X; ++i)
		for (int j = 0; i + j <= X; ++j) {
			res[i + j] += a[i] * b[j];
			res[i + j] %= mod;
		}
	return res;
}

const std::vector<int> options[] = { {0, 1, 2}, {0}, {0, 2} };

const std::array<long long, 11> &dfs(int u, int parent, int p) {
	if (dp[u][p][0] != -1) return dp[u][p];
	auto &memo = dp[u][p];

	for (int v : adj[u])
		if (v != parent) {
			if (memo[0] == -1)
				memo = f(v, u, options[p]);
			else
				memo = merge(f(v, u, options[p]), memo);
		}

	auto mult = p == 0 ? (k - 1) : p == 1 ? 1 : (m - k);
	if (memo[0] == -1) {
		memo[0] = 0;
		memo[p == 1 ? 1 : 0] = mult;
	}
	else {
		if (p == 1) {
			for (int i = X; i > 0; --i)
				memo[i] = memo[i - 1];
			memo[0] = 0;
		}
		else
			for (auto &&x : memo)
				x *= mult;
	}
	return memo;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m;
	for (int i = 0; i <= n; ++i)
		for (int p : {0, 1, 2}) {
			dp[i][p] = emptyarr0;
			dp[i][p][0] = -1;
		}

	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::cin >> k >> X;

	long long ans = 0;
	for (int p : {0, 1, 2}) {
		for (int x = 0; x <= X; ++x) {
			if (dfs(1, -1, p)[x] < 0)
				exit(1);
			ans += dfs(1, -1, p)[x];
			ans %= mod;
		}
	}
	std::cout << (ans % mod);
	return 0;
}