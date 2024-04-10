#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000005;

int minP[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	for (int i = 2; i < N; i++) {
		if (minP[i] == 0) {
			minP[i] = i;
			for (int j = i + i; j < N; j += i) {
				if (minP[j] == 0) minP[j] = i;
			}
		}
	}

	// cout << minP[3] << endl;

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		map<vector<int>, int> mp;
		map<vector<int>, int> mp0;
		for (int i = 0; i < n; i++) {
			int u;
			cin >> u;
			// cout << u << endl;
			vector<int> foo;
			while (u != 1) {
				int p = minP[u];
				// cout << p << endl;
				// cout << u << ' ' << p << endl;
				int cnt = 0;
				while (u % p == 0) {
					cnt++;
					u /= p;
				}
				if (cnt % 2) foo.push_back(p);
			}
			if (foo.size() != 0) mp[foo]++;
		}

		int mx0 = 0;
		int sum0 = 0;

		for (auto e : mp) {
			mx0 = max(mx0, e.second);
			sum0 += e.second;
		}

		mx0 = max(mx0, n - sum0);

		int mx = 0;
		int sum = 0;

		for (auto e : mp) {
			if (e.second % 2) mx = max(mx, e.second);
			if (e.second % 2) sum += e.second;
		} 

		mx = max(mx, n - sum);

		int q;
		cin >> q;
		while (q--) {
			int w;
			cin >> w;
			if (w == 0) {
				cout << mx0 << '\n';
			} else cout << mx << '\n';
		}

	}

	return 0;
}