#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		v[u].push_back(0);
		int cnt = 0;
		while (u != 0) {
			u /= 2;
			v[u].push_back(++cnt);
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 200005; i++) {
		if (v[i].size() < k) continue;
		sort(v[i].begin(), v[i].end());
		int tmp = 0;
		for (int j = 0; j < k; j++) {
			tmp += v[i][j];
		}
		ans = min(ans, tmp);
	}
	cout << ans;
	return 0;
}