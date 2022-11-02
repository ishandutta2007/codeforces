#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include<vector>


using namespace std;
int n, m;
vector < int > t[1001000];
vector < int > g[100100];
int a[100100], b[100100];
int ans[100100];
int p[100100];

int get(int v) {
	if (p[v] == v) return v;
	return p[v] = get(p[v]);
}
void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) return;
	if (rand() & 1)  p[a] = b;
	else p[b] = a;
}

bool used[100100];
int timer, tin[100100], fup[100100];
map < pair < int, int >, int > cnt, is_b;
void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				is_b[make_pair(to, v)] = 1;
				is_b[make_pair(v, to)] = 1;
			}
		}
	}
}
void calc(int x) {
	if (t[x].empty()) return;
	vector < int > cc;
	cnt.clear();
	is_b.clear();
	for (int y : t[x]) {
		a[y] = get(a[y]);
		b[y] = get(b[y]);
		if (a[y] == b[y]) continue;
		cnt[make_pair(a[y], b[y])]++;
		cnt[make_pair(b[y], a[y])]++;
		cc.push_back(a[y]);
		cc.push_back(b[y]);
	}
	sort(cc.begin(), cc.end());
	cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
	for (int y : cc) {
		used[y] = 0;
		g[y].clear();
	}
	for (int y : t[x]) {
		if (a[y] == b[y]) continue;
		g[a[y]].push_back(b[y]);
		g[b[y]].push_back(a[y]);
	}
	timer = 0;
	for (int y : cc) {
		if (!used[y]) dfs(y);
	}
	for (int y : t[x]) {
		if (a[y] == b[y]) continue;
		if (is_b[make_pair(a[y], b[y])] && (cnt[make_pair(a[y], b[y])] == 1)) {
			ans[y] = 1;
		}
		else ans[y] = 2;
		merge(a[y], b[y]);
	}
}

int main() {
        scanf("%d %d",&n, &m);
	for (int i = 0, c; i < m; i++) {
scanf("%d %d %d", &a[i], &b[i], &c);
		t[c].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		p[i] = i;

	for (int i = 1; i < 1001000; i++)
		calc(i);
	for (int i = 0; i < m; i++) {
		if (ans[i] == 0) printf("none\n");
		else if (ans[i] == 1) printf("any\n");
		else printf("at least one\n");
	}
	return 0;
}