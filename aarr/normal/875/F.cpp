#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;

int par[N];
bool b[N];
int st[N], ed[N];
pair <int, int> e[N];

int get_par(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get_par(par[v]);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> st[i] >> ed[i] >> e[i].first;
		e[i].second = i;
	}
	sort(e + 1, e + m + 1);
	long long ans = 0;
	for (int i = m; i; i--) {
		int u = get_par(st[e[i].second]), v = get_par(ed[e[i].second]);
		if (u == v) {
			if (!b[u]) {
				b[u] = true;
				ans += e[i].first;
			}
		}
		else {
			if (!b[u] || !b[v]) {
				ans += e[i].first;
				par[u] = v;
				b[v] = b[u] || b[v];
			}
		}
	}
	cout << ans;
	return 0;
}