#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define pii pair<int, int>

int n, m, q, cnt;
int uf[N * 5];
set<int> S[N];
map<pii, int> id;

int find(int x) {
	return uf[x] == x ? x : (uf[x] = find(uf[x]));
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (x > y) swap(x, y);
	if (y <= n) {
		if (S[x].size() < S[y].size()) {
			swap(x, y);
		}
		uf[y] = x;
		set<int>::iterator hint = S[x].begin();
		for (set<int>::iterator it = S[y].begin(); it != S[y].end(); it++) {
			hint = S[x].insert(hint, *it);
		}
	} else {
		uf[y] = x;
	}
}

void build(int u, int v, int c) {
	if (id.count(pii(u, c))) {
		unit(v, id[pii(u, c)]);
	} else {
		id[pii(u, c)] = ++cnt;
		uf[cnt] = cnt;
		unit(v, cnt);
	}
	if (id.count(pii(v, c))) {
		unit(u, id[pii(v, c)]);
	} else {
		id[pii(v, c)] = ++cnt;
		uf[cnt] = cnt;
		unit(u, cnt);
	}
	S[find(u)].insert(v);
	S[find(v)].insert(u);
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d%d%*d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		uf[i] = i, S[i].insert(i);
	}
	cnt = n;
	for (int i = 1, u, v, c; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		build(u, v, c);
	}
	static char buf[10];
	int x, y, c;
	while (q--) {
		scanf("%s%d%d", buf, &x, &y);
		if (buf[0] == '+') {
			scanf("%d", &c);
			build(x, y, c);
		} else {
			puts(S[find(x)].count(y) ? "Yes" : "No");
		}
	}
	return 0;
}