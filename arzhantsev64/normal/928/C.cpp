#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector< pair<int, string> > projects(n);
	map< pair<int, string> , int> list_ids;
	vector< vector< pair<int, string> > > dep(n);
	int index = 0;
	for (auto& project : projects) {
		cin >> project.second >> project.first;
		int sz = 0;
		cin >> sz;
		dep[index].resize(sz);
		for (auto& d : dep[index])
			cin >> d.second >> d.first;
		list_ids[project] = index;
		++index;
	}
	vector< vector<int> > g(n);
	for (int i = 0; i < n; ++i) {
		for (auto& d : dep[i]) {
			g[i].push_back(list_ids[d]);
		}
	}
	deque< pair<int, int> > q;
	vector<bool> visited(n, false);
	q.push_back({0, 0});
	visited[0] = true;
	map< string, pair<int, int> > ans;
	int last_len = 0;
	while (!q.empty()) {
		int len = q.front().second;
		if (len != last_len) {
			for (int index = 0; index < q.size() && q[index].second == len; index++) {
				int v = q[index].first;
				if (v != 0 && projects[v].second != projects[0].second) {
					if (ans.find(projects[v].second) == ans.end()) {
						ans[projects[v].second] = {projects[v].first, len};
					} else {
						auto p = ans[projects[v].second];
						if (p.second > len || (p.second == len && p.first < projects[v].first)) {
							ans[projects[v].second] = {projects[v].first, len};
						}
					}
				}
			}
			last_len = len;
		}
		int v = q.front().first;
		q.pop_front();
		if (v != 0 && (ans[projects[v].second].first != projects[v].first))
			continue;
		for (int to : g[v]) {
			if (!visited[to]) {
				visited[to] = true;
				q.push_back({to, len + 1});
			}
		}
	}
	if (ans.find(projects[0].second) != ans.end()) 
		ans.erase(ans.find(projects[0].second));
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second.first << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}