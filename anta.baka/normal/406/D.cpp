#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;

int n, q, esz;
int x[MAXN];
ll y[MAXN];
vector<int> hull;
vector<int> g[MAXN];
vector<int> euler;
int dep[MAXN], last[MAXN];
int lg[4 * MAXN];
pair<int,int> st[4 * MAXN][20];

bool ccw(int x1, ll y1, int x2, ll y2, int x3, ll y3) {
	return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) < 0;
}

void dfs(int v) {
	last[v] = euler.size();
	euler.push_back(v);
	for(int to : g[v]) {
		dep[to] = dep[v] + 1;
		dfs(to);
		last[v] = euler.size();
		euler.push_back(v);
	}
}

int lca(int u, int v) {
	if(last[u] > last[v]) {
		swap(u, v);
	}
	int bar = lg[last[v] - last[u] + 1];
	return min(st[last[u]][bar], st[last[v] - (1 << bar) + 1][bar]).second;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = n - 1; i >= 0; i--) {
		while(hull.size() > 1 && ccw(x[hull[hull.size()-2]], y[hull[hull.size()-2]], x[hull.back()], y[hull.back()], x[i], y[i])) {
			hull.pop_back();
		}
		if(i != n - 1) {
			g[hull.back()].push_back(i);
		}
		hull.push_back(i);
	}
	dfs(n - 1);
	esz = euler.size();
	for(int i = 2; i <= esz; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	for(int i = 0; i < esz; i++) {
		st[i][0] = {dep[euler[i]], euler[i]};
	}
	for(int j = 1; j <= lg[esz]; j++)
		for(int i = 0; i + (1 << j) <= esz; i++) {
			st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
		}
	cin >> q;
	for(int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		cout << lca(u, v) + 1 << "\n";
	}
}