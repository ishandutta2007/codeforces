#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		vector<int> w(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> w[i];
		}

		vector<int> deg(n + 1, 0);

		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			deg[u]++;
			deg[v]++;
		}

		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += w[i];
		}

		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++) {
			pq.push({w[i], deg[i] - 1});
		}

		for (int i = 1; i < n; i++) {
			cout << ans << ' ';
			while (true) {
				if (pq.empty()) {
					break;
				}
				auto foo = pq.top();
				pq.pop();
				if (foo.second == 0) {
					continue;
				}
				ans += foo.first;
				foo.second--;
				pq.push(foo);
				break;
			}
		}
		cout << '\n';
	}

	return 0;
}