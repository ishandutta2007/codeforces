#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

bool augmentDFS(const int u, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &match) {
	if (u == -1) return 1;
	if (visited[u]) return 0;
	visited[u] = true;
	for (auto &&v : adj[u])
		if (augmentDFS(match[v], adj, visited, match)) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	return false;
}

pair<int, vector<int>> maxMatching(const int n, const int m, const vector<vector<int>> &adj) {
	vector<bool> visited(n);
	vector<int> match(n + m, -1);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		fill(visited.begin(), visited.end(), 0);
		res += augmentDFS(i, adj, visited, match);
	}
	return{ res, match };
}

// 0	+
// +	+
// ?	+
// 0	?
// +	?
// ?	?

map<pair<int, int>, int> getNeed(const int n, const vector<int> &pre, const vector<int> &cycle, const set<int> &cycleSet) {
	map<pair<int, int>, int> need;
	map<int, int> pre0CycleCnt;

	for (auto &&x : cycleSet)
		pre0CycleCnt[x] = 0;

	for (int i = 0; i < n; ++i)
		if (cycle[i] > 0) {
			if (!pre[i])
				++pre0CycleCnt[cycle[i]];
			else
				for (int j = 1; j < pre[i]; ++j)
					need[{j, cycle[i]}] = 1;
		}

	for (int i = 0; i < n; ++i)
		if (pre[i] > 0 && cycle[i] > 0) {
			auto it = need.find({ pre[i], cycle[i] });
			if (it != need.end())
				need.erase(it);
		}


	for (auto &&x : pre0CycleCnt) {
		auto&&y = need[{0, x.first}];
		if (!x.second)
			y = x.first;
		else
			y = ((-x.second % x.first) + x.first) % x.first;
	}
	return need;
}

void f(const int n, vector<int> &pre, vector<int> &cycle, const set<int> &cycleSet) {

	auto need = getNeed(n, pre, cycle, cycleSet);

	vector<int> left;
	vector<pair<int, int>> right;

	for (int i = 0; i < n; ++i)
		if (pre[i] < 0 || cycle[i] < 0)
			left.push_back(i);

	for (auto &&x : need)
		for (int i = x.second; i > 0; --i)
			right.push_back(x.first);

	vector<vector<int>> adj(left.size());

	for (int i = 0; i < left.size(); ++i)
		for (int j = 0; j < right.size(); ++j) {
			auto &&x = left[i];
			auto &&y = right[j];
			if ((pre[x] < 0 || pre[x] == y.first) && (cycle[x] < 0 || cycle[x] == y.second))
				adj[i].push_back(j + left.size());
		}

	auto res = maxMatching(left.size(), right.size(), adj);
	if (res.first != right.size())
		return;
	auto &&match = res.second;

	for (int j = 0; j < right.size(); ++j) {
		auto &&x = left[match[j + left.size()]];
		auto &&y = right[j];
		pre[x] = y.first;
		cycle[x] = y.second;
	}

	// out

	int bestPre = 0;
	int cycleWithBestPre = 0;
	for (int i = 0; i < n; ++i)
		if (pre[i] > bestPre) {
			bestPre = pre[i];
			cycleWithBestPre = cycle[i];
		}

	for (int i = 0; i < n; ++i)
		if (pre[i] <= 0 && cycle[i] < 0) {
			pre[i] = 0;
			cycle[i] = 1;
		}
		else if (cycle[i] < 0)
			cycle[i] = cycleWithBestPre;
		else if (pre[i] < 0)
			pre[i] = 1;

	map<int, vector<int>> pre0Nodes;
	map<pair<int, int>, int> someNode;

	for (int i = 0; i < n; ++i) {
		if (!pre[i])
			pre0Nodes[cycle[i]].push_back(i);
		someNode[{pre[i], cycle[i]}] = i;
	}

	vector<int> ans(n);

	for (auto &&x : pre0Nodes) {
		while (!x.second.empty()) {
			vector<int> v(x.second.end() - x.first, x.second.end());
			x.second.erase(x.second.end() - x.first, x.second.end());
			for (int i = 0; i < v.size(); ++i)
				ans[v[i]] = v[(i + 1) % v.size()];
		}
	}

	for (int i = 0; i < n; ++i)
		if (pre[i] > 0)
			ans[i] = someNode[{pre[i] - 1, cycle[i]}];

	for (int i = 0; i < n; ++i) {
		if (i)
			cout << ' ';
		cout << ans[i] + 1;
	}
	exit(0);
}

void f() {
	int n;
	cin >> n;
	vector<int> pre(n), cycle(n);
	int maxPQI = -1;
	for (int i = 0; i < n; ++i) {
		string x, y;
		cin >> x >> y;
		pre[i] = x == "?" ? -1 : stoi(x);
		cycle[i] = y == "?" ? -1 : stoi(y);
		if (pre[i] >= 0 && cycle[i] < 0 && (maxPQI < 0 || pre[i] > pre[maxPQI]))
			maxPQI = i;
	}
	set<int> cycleSet(cycle.begin(), cycle.end());
	cycleSet.erase(-1);
	int sum = 0;
	for (auto &&x : cycleSet)
		sum += x;
	if (sum > n)
		return;
	if (maxPQI < 0)
		f(n, pre, cycle, cycleSet);
	else {
		cycle[maxPQI] = 1;
		f(n, pre, cycle, cycleSet);
		for (auto &&x : cycleSet) {
			cycle[maxPQI] = x;
			f(n, pre, cycle, cycleSet);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f();
	cout << -1;
	return 0;
}