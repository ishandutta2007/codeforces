#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

vector<vector<int>> g;
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    int max_v = -1, max_s = -1;
    for (int i = 0; i < n; i++) {
	int ss = g[i].size();
	if (ss > max_s) {
	    max_s = ss;
	    max_v = i;
	}
    }
    vector<int> min_e(n, 1e9), sel_e(n, -1);
    min_e[max_v] = 0;
    set<pair<int, int>> q;
    q.insert({0, max_v});
    for (int i = 0; i < n; i++) {
	int v = q.begin()->second;
	q.erase(q.begin());
	if (sel_e[v] != -1) {
	    cout << v + 1 _ sel_e[v] + 1 << endl;
	}
	for (int to : g[v]) {
	    if (1 < min_e[to]) {
		q.erase({min_e[to], to});
		min_e[to] = 1;
		sel_e[to] = v;
		q.insert({min_e[to], to});
	    }
	}
    }
}