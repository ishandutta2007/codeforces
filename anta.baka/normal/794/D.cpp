#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000;

int n, m;
vector<int> g[maxn];
map<vector<int>, int> hs;
int h = 0;
int hh[maxn];
vector<int> g1[maxn];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		g[i].push_back(i);
		sort(g[i].begin(), g[i].end());
		if(hs.count(g[i]) == 0)
			hs[g[i]] = h++;
		hh[i] = hs[g[i]];
	}
	for(int i = 0; i < n; i++)
		for(int j : g[i])
			if(hh[i] != hh[j])
				g1[hh[i]].push_back(hh[j]);
	int rt;
	for(int i = 0; i < h; i++) {
		sort(g1[i].begin(), g1[i].end());
		g1[i].erase(unique(g1[i].begin(), g1[i].end()), g1[i].end());
		if(g1[i].size() > 2)
			return cout << "NO", 0;
		if(g1[i].size() < 2)
			rt = i;
	}
	vector<int> col(h, -1);
	for(int i = 0; i < h; i++) {
		col[rt] = i;
		for(int to : g1[rt])
			if(col[to] == -1)
				rt = to;
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
		cout << col[hh[i]] + 1 << ' ';
}