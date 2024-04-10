#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	
	int n;
	cin >> n;
	vector<pair<string, int>> a(n);
	vector<vector<pair<string, int>>> g(n);
	map<pair<string, int>, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		m[a[i]] = i;
		
		int k;
		cin >> k;
		g[i].resize(k);
		for (auto& x : g[i]) {
			cin >> x.first >> x.second;
		}
	}
	map<string, int> cur = {a[0]};
	map<string, int> used;
	while (!cur.empty()) {
		for (const auto& item : cur) {
			used[item.first] = item.second;
		}
		map<string, int> nxt;
		for (const auto& item : cur) {
			int v = m[item];
			for (const auto& to : g[v]) {
				if (used.count(to.first)) {
					continue;
				}
				nxt[to.first] = max(nxt[to.first], to.second);
			}
		}
		cur = nxt;
	}
	cout << used.size() - 1 << "\n";
	for (const auto& item : used) {
		if (item.first == a[0].first) {
			continue;
		}
		cout << item.first << " " << item.second << "\n";
	}
	
	return 0;
}