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

using namespace std;

long long n, m;
vector<long long> adj[(long long)3e5 + 1];

void dfs(const long long u, const long long p, vector<long long> &color, vector<long long> &nodes, vector<pair<long long, long long>> &cycles) {
	color[u] = 1;
	nodes.push_back(u);
	for (auto &&v : adj[u])
		if (!color[v])
			dfs(v, u, color, nodes, cycles);
		else if (v != p && color[v] == 1) {
			cycles.push_back({ v, v });
			for (;;) {
				const long long w = nodes.back();
				nodes.pop_back();
				color[w] = 2;
				if (w == v)
					break;
				cycles.back().first = min(cycles.back().first, w);
				cycles.back().second = max(cycles.back().second, w);
			}
		}
}

auto dfs() {
	vector<long long> color(n + 1, false);
	vector<long long> nodes;
	vector<pair<long long, long long>> cycles;
	for(long long i = 1; i <= n; ++i)
		if(!color[i])
			dfs(i, -1, color, nodes, cycles);
	sort(cycles.begin(), cycles.end());

	vector<pair<long long, long long>> ranges;
	for (auto &&x : cycles) {
		if (!ranges.empty() && ranges.back().first == x.first)
			continue;
		while (!ranges.empty() && x.second <= ranges.back().second)
			ranges.pop_back();
		ranges.push_back(x);
	}
	return ranges;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (long long i = 0; i < m; ++i) {
		long long a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	auto ranges = dfs();

	vector<long long> to(n + 1);
	vector<long long> cs(n + 1, 0);
	for (long long i = 1; i <= n; ++i) {
		auto it = lower_bound(ranges.begin(), ranges.end(), pair<long long, long long>{i, -1});
		if (it == ranges.end())
			to[i] = n;
		else
			to[i] = it->second - 1;
		cs[i] = cs[i - 1] + (to[i] - i + 1);
	}

	long long q;
	cin >> q;
	while (q-- > 0) {
		long long x, y;
		cin >> x >> y;
		long long i = lower_bound(to.begin() + x, to.begin() + y, y) - to.begin();
		auto ans = cs[i - 1] - cs[x - 1]; // [x ... i-1]
		ans += (y - i + 1) * (y - i + 2) / 2; // [i ... y]; (y - i + 1) + (y - i) + ... + 1
		cout << ans << '\n';
	}
	return 0;
}