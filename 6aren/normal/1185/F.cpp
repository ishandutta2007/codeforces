#include<bits/stdc++.h>

using namespace std;

int n, m, a[100005], b[100005], c[100005];
long long f[2][1024];
int x[1024];
pair<int, int> y[1024];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		while (u--) {
			int t;
			cin >> t;
			a[i] += (1 << (t - 1));
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		int u;
		cin >> u;
		while (u--) {
			int t;
			cin >> t;
			b[i] += (1 << (t - 1));
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1005; j++) {
			f[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 1000; j++) {
			int t = (j | b[i]);
			if (f[0][j] + c[i] < f[1][t]) {
				y[t].first = x[j];
				y[t].second = i;
				f[1][t] = f[0][j] + c[i];
			}
		}
		if (c[i] < f[0][b[i]]) {
			f[0][b[i]] = c[i];
			x[b[i]] = i;
		}
	}
	long long mx = 0, mn = 1e18;
	pair<int, int> res;
	for (int i = 0; i < 1000; i++) {
		if (f[1][i] == 1e18) continue;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if ((i & a[j]) == a[j]) {
				cnt++;
			}
		}
		if (cnt > mx) {
			mx = cnt;
			mn = f[1][i];
			res = y[i];
		} else if (cnt == mx) {
			if (mn < f[1][i]) continue;
			mn = f[1][i];
			res = y[i];
		}
	}
	cout << res.first << ' ' << res.second;
	return 0;
}