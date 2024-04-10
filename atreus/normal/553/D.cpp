#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
const int inf = 1e9;
int mark[maxn];
vector <int> g[maxn];
int d[maxn], dinset[maxn];

int main () {
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		mark[x] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		g[v].PB (u);
		g[u].PB (v);
		d[v] ++;
		d[u] ++;
	}
	for (int v = 1; v <= n; v++) {
		if (mark[v] == false) {
			for (auto u : g[v]) {
				dinset[u] ++;
			}
		}
	}
	set <pair <ld, int> > s;
	for (int v = 1; v <= n; v++) {
		if (mark[v] == 0) {
			s.insert ({1. * dinset[v] / d[v], v});
		}
	}
	ld ans = 0;
	while (!s.empty()) {
		ans = max (ans, (*s.begin()).F);
		auto v = (*s.begin()).S;
		mark[v] = 2;
		s.erase (s.begin());
		for (auto u : g[v]) {
			if (mark[u] == 0) {
				s.erase ({1. * dinset[u] / d[u], u});
				dinset[u] --;
				s.insert ({1. * dinset[u] / d[u], u});
			}
		}
	}

	memset (dinset, 0, sizeof dinset);
	for (int v = 1; v <= n; v++) {
		if (mark[v] == 2) {
			for (auto u : g[v]) {
				dinset[u] ++;
			}
		}
	}
	s.clear();
	for (int v = 1; v <= n; v++) {
		if (mark[v] == 2) {
			s.insert ({1. * dinset[v] / d[v], v});
		}
	}
	while (!s.empty()) {
		if ((*s.begin()).F == ans) {
			cout << s.size() << endl;
			for (auto it : s)
				cout << it.S << " ";
			cout << endl;
			return 0;
		}
		ans = max (ans, (*s.begin()).F);
		auto v = (*s.begin()).S;
		mark[v] = 0;
		s.erase (s.begin());
		for (auto u : g[v]) {
			if (mark[u] == 2) {
				s.erase ({1. * dinset[u] / d[u], u});
				dinset[u] --;
				s.insert ({1. * dinset[u] / d[u], u});
			}
		}
	}
	cout << ans << endl;
}