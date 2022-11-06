#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int adj[23] = { 0 };
int dp[1 << 22];
int choice[1 << 22];

template<typename T> bool minimize(T &var, const T &val) {
	if (var <= val)
		return false;
	var = val;
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;
	}

	if (m == n*(n - 1) / 2) {
		cout << "0\n";
		return 0;
	}

	dp[(1 << n) - 1] = 0;
	for (int mask = (1 << n) - 2; mask > 0; --mask) {
		dp[mask] = 25;
		for (int i = 0; i < n; ++i)
			if ((mask & (1 << i)) && minimize(dp[mask], 1 + dp[mask | adj[i]]))
				choice[mask] = i;
	}

	dp[0] = 25;
	for (int i = 0; i < n; ++i)
		if (minimize(dp[0], 1 + dp[1 << i | adj[i]]))
			choice[0] = i;

	cout << dp[0] << '\n';
	int i = choice[0];
	cout << (i + 1);
	int mask = 1 << i | adj[i];
	while (dp[mask]) {
		i = choice[mask];
		cout << ' ' << (i + 1);
		mask |= adj[i];
	}
	return 0;
}