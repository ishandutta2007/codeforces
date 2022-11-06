#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 3e5 + 9;
int a[MxN + 9];
set<int> adj[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
	}

	int ans = 0;
	for (int i = n - 1; i >= 1; --i) {
		assert(i < n);
		int j = i;
		for (; j < n; ++j) {
			if (!adj[a[j]].count(a[j + 1]))
				break;
			swap(a[j], a[j + 1]);
		}
		if (j == n) {
			ans++;
			n--;
		}
	}
	cout << ans;
	return 0;
}