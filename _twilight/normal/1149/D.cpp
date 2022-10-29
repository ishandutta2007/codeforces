#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 71, S = 1 << 17;
const signed int inf = (signed) (~0u >> 2);

#define pii pair<int, int>

template <typename T>
boolean smin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}

int n, m, a, b;
int f[S][N];
vector<pii> G[N];
int uf[N], id[N], sz[N];

int find(int x) {
	return (uf[x] ^ x) ? (uf[x] = find(uf[x])) : (x);
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if (x ^ y) {
		uf[x] = y;
		sz[y] += sz[x];
	}
}

queue<pii> Q1, Q2, Q3;
boolean empty() {
	return Q1.empty() && Q2.empty() && Q3.empty();
}
pii top_pop(int* f) {
	pii rt;
	int dist = inf;
	queue<pii> *qres = NULL;
	if (!Q1.empty() && smin(dist, f[Q1.front().first])) {
		qres = &Q1;
		rt = Q1.front();
	}
	if (!Q2.empty() && smin(dist, f[Q2.front().first])) {
		qres = &Q2;
		rt = Q2.front();
	}
	if (!Q3.empty() && smin(dist, f[Q3.front().first])) {
		qres = &Q3;
		rt = Q3.front();
	}
	qres->pop();
	return rt;
}
void clear3() {
	while (!Q1.empty()) Q1.pop();
	while (!Q2.empty()) Q2.pop();
	while (!Q3.empty()) Q3.pop();
}

void bfs(int status) {
	clear3();
	int* f = ::f[status];
	vector<int> tmp;
	for (int i = 1; i <= n; i++) {
		if (f[i] < inf) {
			tmp.push_back(i);
		}
	}
	sort(tmp.begin(), tmp.end(), [&] (int a, int b) {
			return f[a] < f[b];
		});
	for (auto p : tmp) {
		Q3.push(pii(p, f[p]));
	}
	while (!empty()) {
		pii __ = top_pop(f);
		int e = __.first;
		if (__.second != f[e]) {
			continue;
		}
		for (auto _ : G[e]) {
			int eu = _.first, w = _.second;
			if (w == a && smin(f[eu], f[e] + w)) {
				Q1.push(pii(eu, f[eu]));
			}
			if (w == b && (uf[eu] ^ uf[e]) && !~id[eu] && smin(f[eu], f[e] + w)) {
				Q2.push(pii(eu, f[eu]));
			}
			if (w == b && ~id[eu] && !((status >> id[eu]) & 1)) {
				smin(::f[status | (1 << id[eu])][eu], f[e] + w);
			}
		}
	}
}

int ans[N];
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
		sz[i] = 1;
		id[i] = -1;
	}
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
		if (w == a) {
			unit(u, v);
		}
	}
	int comp = 0;
	for (int i = 1; i <= n; i++) {
		if (uf[i] == i && sz[i] >= 4) {
			id[i] = comp++;
		}
	}
	for (int i = 1; i <= n; i++) {
		id[i] = id[find(i)];
	}
	for (int i = 0; i < (1 << comp); i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = inf;
	}
	(id[1] == -1) ? (f[0][1] = 0) : (f[1 << id[1]][1] = 0);
	for (int s = 0; s < (1 << comp); s++) {
		bfs(s);
		for (int i = 1; i <= n; i++) {
			smin(ans[i], f[s][i]);
		} 
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}