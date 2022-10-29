#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

#define pii pair<int, int>

int n, m;
pii tg[N];
int fa[N], dep[N];
vector<int> G[N];

void print(vector<int> P) {
	printf("%d", (signed) P.size());
	for (auto e : P)
		printf(" %d", e);
	putchar('\n');
}

int lca(int x, int y) {
	while (x ^ y) {
		if (dep[x] < dep[y])
			swap(x, y);
		x = fa[x];
	}
	return x;
}

void solve(pii X, pii Y) {
	puts("YES");
	int a = X.first, b = X.second, c = Y.first, d = Y.second;
	int s = lca(a, c), t = (dep[b] < dep[d]) ? (d) : (b);
	vector<int> P, Q;
	for (int p = s; p ^ t; p = fa[p])
		P.push_back(p);
	P.push_back(t);
	print(P);
	P.clear();
	
	for (int p = a; p ^ s; p = fa[p])
		P.push_back(p);
	P.push_back(s);
	for (int p = t; p ^ b; p = fa[p])
		Q.push_back(p);
	Q.push_back(b);
	reverse(P.begin(), P.end());
	while (!Q.empty()) {
		P.push_back(Q.back());
		Q.pop_back();
	}
	print(P);
	P.clear();
	
	a = c, b = d;
	for (int p = a; p ^ s; p = fa[p])
		P.push_back(p);
	P.push_back(s);
	for (int p = t; p ^ b; p = fa[p])
		Q.push_back(p);
	Q.push_back(b);
	reverse(P.begin(), P.end());
	while (!Q.empty()) {
		P.push_back(Q.back());
		Q.pop_back();
	}
	print(P);
	P.clear();
	exit(0);
}

void put(int u, int v) {
	pii e = pii(u, v);
	for (int p = u; p ^ v; p = fa[p]) {
		if (tg[p].first) {
			solve(e, tg[p]);
		} else {
			tg[p] = e;
		}
	}
}

void dfs(int p, int fa) {
	dep[p] = dep[fa] + 1;
	::fa[p] = fa;
	for (auto e : G[p]) {
		if (e == fa)
			continue;
		if (!dep[e]) {
			dfs(e, p);
		} else if (dep[e] < dep[p]) {
			put(p, e);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!dep[i]) {
			dfs(i, 0);
		}
	}
	puts("NO");
	return 0;
}