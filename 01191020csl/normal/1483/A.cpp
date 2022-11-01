#include<bits/stdc++.h>
using namespace std;
vector<int> f[100001];
int cnt[100001], res[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= m; i++) {
			f[i].clear();
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++) {
				int f0;
				cin >> f0;
				f[i].push_back(f0);
			}
			if (k == 1) ++cnt[f[i][0]], res[i] = f[i][0];
		}
		bool flag = 1;
		for (int i = 1; flag && i <= n; i++)
			if (cnt[i] > (m+1)/2)
				puts("NO"), flag = 0;
		if (!flag) continue;
		for (int i = 1; i <= m; i++)
			if (f[i].size() >= 2) {
				int u = f[i][0], v = f[i][1];
				if (cnt[u] < cnt[v]) res[i] = u, ++cnt[u];
				else res[i] = v, ++cnt[v];
			}
		puts("YES");
		for (int i = 1; i <= m; i++) cout << res[i] << ' ';
		cout << endl;
	}
}