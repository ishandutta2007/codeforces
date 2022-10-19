#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

vector<int> g[N];
int col[N];
int n, m;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		deque<int> dq;
		dq.push_front(1);
		col[1] = 1;
		vector<int> ans;

		while (!dq.empty()) {
			int u = dq.front();
			dq.pop_front();
			if (col[u] == 1) {
				ans.push_back(u);
				for (int e : g[u]) {
					if (col[e] == 0) {
						col[e] = 2;
						dq.push_back(e);
					}
				}
			} else {
				int found = -1;
				for (int e : g[u]) {
					if (col[e] == 0) {
						found = e;
						break;
					}
				}
				if (found != -1) {
					col[found] = 1;
					dq.push_front(found);
					dq.push_back(u);
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (col[i] > 0) cnt++;
		}

		for (int i = 1; i <= n; i++) {
			col[i] = 0;
			g[i].clear();
		}

		if (cnt != n) {
			cout << "NO\n";
			continue;
		}
		sort(ans.begin(), ans.end());
		cout << "YES\n";
		cout << ans.size() << '\n';
		for (int e : ans) {
			cout << e << ' ';
		}
		cout << '\n';
	} 

	return 0;
}