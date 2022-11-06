#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define inf 1000000000
using namespace std;

struct rec {
	int a, b, c;
	rec() {};
	rec(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	bool operator < (const rec & t) const {
		return a < t.a || (a == t.a && (b < t.b || (b == t.b && c < t.c)));
	}
};

struct reb {
	int x, y;
	reb() {};
	reb(int _x, int _y) {
		x = _x;
		y = _y;
	}
};


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k, x, y, z, i;
	scanf("%d%d%d", &n, &m, &k);
	vector< vector<int> > par(n, vector<int>(n, -1));
	vector< vector<bool> > used(n, vector<bool>(n, false));
	par[0][0] = 0;
	set<rec> mn;
	vector< vector<int> > gr(n);
	vector<int>::iterator it;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		gr[--x].push_back(--y);
		gr[y].push_back(x);
	}
	for (i = 0; i < k; i++) {
		scanf("%d%d%d", &x, &y, &z);
		mn.insert(rec(x - 1, y - 1, z - 1));
	}
	queue<reb> q;
	for (it = gr[0].begin(); it != gr[0].end(); it++) {
		q.push(reb(0, *it));
		par[0][*it] = 0;
		used[0][*it] = true;
	}

	reb v, t;
	bool fl = false;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		if (v.y == n - 1) {
			fl = true;
			break;
		}
		for (it = gr[v.y].begin(); it != gr[v.y].end(); it++) {
			if (!used[v.y][*it] && !mn.count(rec(v.x, v.y, *it))) {
				par[v.y][*it] = v.x;
				used[v.y][*it] = true;
				q.push(reb(v.y, *it));
			}
		}
	}
	if (!fl) {
		cout << -1;
		return 0;
	}
	vector<int> way;
	way.push_back(n - 1);
	int vv, tt;
	vv = par[v.x][v.y];
	if (v.x) {
		way.push_back(v.x);
	}
	while (vv) {
		way.push_back(vv);
		tt = vv;
		vv = par[vv][v.x];
		v.x = tt;
	}
	way.push_back(0);
	printf("%d\n", way.size() - 1);
	for (i = way.size() - 1; i >= 0; i--) {
		printf("%d ", way[i] + 1);
	}	
	return 0;
}//ehvmbc