#include<bits/stdc++.h>
using namespace std;

const int N = 5005;

int p[N], a[N];

int root(int x) {
	return (p[x] == x ? x : p[x] = root(p[x]));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);


	int ntest;
	cin >> ntest;
	while (ntest--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i], p[i] = i;

		vector<pair<int, int>> ans;

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[i] == a[j])
					continue;
				int u = root(i);
				int v = root(j);
				if (u != v) {
					ans.push_back({i, j});
					p[u] = v;
				}
			}
		}

		if (ans.size() != n - 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (auto e : ans)
				cout << e.first << ' ' << e.second << '\n';
		}

	}

	return 0;
}