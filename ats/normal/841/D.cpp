#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int> > e;
vector<vector<int> > ind;
vector<vector<int> > res;
vector<int> d;
vector<int> p;
vector<int> v;
bool h1;
void dfs(int a) {
	v[a] = 1;
	if (d[a] == -1) {
		h1 = true;
	}
	for (int i = 0; i < e[a].size(); i++) {
		if (v[e[a][i]] == 0) {
			dfs(e[a][i]);
			if (p[e[a][i]] == 1) {
				res[a][i] = 1;
				p[e[a][i]] = 0;
				if (p[a] != -1) {
					p[a] = 1 - p[a];
				}
			}
		}
	}
}
signed main() {
	cin >> n >> m;
	e.resize(n);
	d.resize(n);
	ind.resize(n);
	res.resize(n);
	v.resize(n, 0);
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	p = d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
		ind[a].push_back(i + 1);
		ind[b].push_back(i + 1);
		res[a].push_back(0);
		res[b].push_back(0);
	}
	int t;
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0 && (d[i] == -1)) {
			h1 = false;
			dfs(i);
			if (!h1 && (p[i] == 1)) {
				f = false;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			h1 = false;
			dfs(i);
			if (h1) {
				cerr << "ERROR" << endl;
			}
			if (!h1 && (p[i] == 1)) {
				f = false;
				break;
			}
		}
	}
	if (!f) {
		cout << -1 << endl;
	}
	else {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < res[i].size(); j++) {
				if (res[i][j] == 1) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < res[i].size(); j++) {
				if (res[i][j] == 1) {
					cout << ind[i][j] << endl;
				}
			}
		}
	}
	return 0;
}