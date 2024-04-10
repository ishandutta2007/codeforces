#include <bits/stdc++.h>

using namespace std;

int mx[105], n, m, k, p[105], res = 0, u, in[105];

bool check[105];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> u;
		in[i] = u;
		mx[u] = max(mx[u], p[i]);
	}
	for (int i = 1; i <= k; i++) {
		cin >> u;
		if (p[u] != mx[in[u]]) {
			res++;
		}
	}
	cout << res;
	return 0;
}