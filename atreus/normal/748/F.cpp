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
const int maxn = 2e5 + 10;

bool c[maxn];
int pnt[maxn];
vector <int> s[maxn], t[maxn];

void dfs2 (int v, int par = -1) {
	pnt[v] = v;
	for (auto u : t[v]) {
		if (u != par) {
			dfs2 (u, v);
			if (s[pnt[u]].size() > s[pnt[v]].size())
				pnt[v] = pnt[u];
		}
	}
	if (par != -1) {
		for (auto u : t[v]) {
			if (u != par and pnt[u] != pnt[v]) {
				for (auto it : s[pnt[u]]) {
					s[pnt[v]].PB (it);
				}
				s[pnt[u]].clear();
			}
		}
		if (c[v]) {
			s[pnt[v]].PB (v);
		}
	}
}

int sz[maxn];
int dfs (int v, int par = -1) {
	sz[v] = c[v];
	for (auto u : t[v]) {
		if (u != par) {
			sz[v] += dfs (u, v);
		}
	}
	return sz[v];
}

int centroid () {
	int v = 1;
	int Max = dfs(v), par = -1;
	bool found = 1;
	while (found) {
		found = 0;
		for (auto u : t[v]) {
			if (u != par and sz[u] > Max / 2) {
				par = v;
				v = u;
				found = 1;
				break;
			}
		}
	}
	return v;
}

int main () {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].PB (u);
		t[u].PB (v);
	}
	for (int i = 1; i <= 2 * k; i++) {
		int v;
		cin >> v;
		c[v] = 1;
	}
	int v = centroid();
	cout << 1 << '\n' << v << '\n';
	dfs2 (v);
	set <pii> S;
	for (auto u : t[v]) {
		if (!s[pnt[u]].empty())
			S.insert ({-s[pnt[u]].size(), pnt[u]});
	}
	if (c[v]) {
		s[v].PB(v);
		S.insert ({-s[v].size(), v});
	}
	while (!S.empty()) {
		auto it = *S.begin();
		S.erase (S.begin());
		auto it2 = *S.begin();
		S.erase (S.begin());
		int u = it.S, w = it2.S;
		cout << s[u].back() << " " << s[w].back() << " " << v << '\n';
		s[u].pop_back();
		s[w].pop_back();
		if (!s[u].empty()) {
			S.insert ({-s[u].size(), u});
		}
		if (!s[w].empty()) {
			S.insert ({-s[w].size(), w});
		}
	}
}