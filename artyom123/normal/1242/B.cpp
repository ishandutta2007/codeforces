#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9 + 1;
 
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
//
	int n, m;
	cin >> n >> m;
	vector <vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	set <pair<int, int>> blocked;
	for (int i = 0; i < n; i++) {
		blocked.insert({0, i});
	}
	vector <int> now;
	vector <int> usd(n);
	vector <int> cnt(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (usd[i] == 1) {
			continue;
		}
		ans++;
		now.push_back(i);
		blocked.erase({cnt[i], i});
		cnt[i]++;
		blocked.insert({cnt[i], i});
		for (int j = 0; j < now.size(); j++) {
			usd[now[j]] = 1;
			for (auto &to : g[now[j]]) {
				blocked.erase({cnt[to], to});
				cnt[to]++;
				blocked.insert({cnt[to], to});	
			}
			vector <int> p;
			for (auto &to : blocked) {
				if (to.first > 0) {
					break;
				}
				now.push_back(to.second);
				p.push_back(to.second);
			}
			for (auto &to : p) {
				blocked.erase({cnt[to], to});
				cnt[to]++;
				blocked.insert({cnt[to], to});
			}
			for (auto &to : g[now[j]]) {
				blocked.erase({cnt[to], to});
				cnt[to]--;
				blocked.insert({cnt[to], to});
			}
		}
		now.clear();
	}
	cout << ans - 1;
	return 0;
}