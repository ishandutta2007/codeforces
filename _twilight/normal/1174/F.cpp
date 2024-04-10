#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n;
vector<int> G[N];
vector<int> C[N];
int sz[N], zson[N], tp[N];

void dfs1(int p, int fa) {
	int &id = zson[p], mx = 0;
	sz[p] = 1;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs1(e, p);
			sz[p] += sz[e];
			if (sz[e] > mx) {
				mx = sz[e];
				id = e;
			}
		}
	}
}

void dfs2(int p, int fa, boolean ontop) {
	tp[p] = ((ontop) ? (p) : (tp[fa]));
	C[tp[p]].push_back(p);
	if (zson[p])
		dfs2(zson[p], p, false);
	for (auto e : G[p]) {
		if ((e ^ fa) && (e ^ zson[p])) {
			dfs2(e, p, true);
		}
	}
}

int qryd(int u) {
	printf("d %d\n", u);
	fflush(stdout);
	int rt;
	scanf("%d", &rt);
	return rt;
}

int qrys(int u) {
	printf("s %d\n", u);
	fflush(stdout);
	int rt;
	scanf("%d", &rt);
	return rt;
}

void answer(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0, true);
	int p = 1, bt, d1 = qryd(1), d2, L, x, d;
	while (true) {
		if (!d1)
			answer(p);
		bt = C[p].back();
		d2 = qryd(bt);
		L = (signed) C[p].size() - 1;
		d = (d1 + d2 - L) >> 1;
		x = d1 - d;
		p = C[p][x];
		if (!d) {
			answer(p);
		} else {
			d1 = d - 1;
			p = qrys(p);
		}
	}
	return 0;
}