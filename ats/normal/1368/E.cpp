#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<int> > g(N);
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[b].push_back(a);
		}
		vector<int> X(N, -1);
		vector<int> res;
		for (int i = 0; i < N; i++) {
			X[i] = 0;
			for (int j : g[i]) {
				X[i] = max(X[i], X[j] + 1);
			}
			if (X[i] >= 2) {
				X[i] = -1;
				res.push_back(i);
			}
		}
		cout << res.size() << "\n";
		for (int i = 0; i < res.size(); i++) {
			if (i > 0) cout << " ";
			cout << res[i] + 1;
		}
		cout << "\n";
	}
	return 0;
}