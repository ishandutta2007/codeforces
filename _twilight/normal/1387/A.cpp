#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

typedef class Edge {
	public:
		int u, v, s;

		Edge() {	}
		Edge(int u, int v, int s) : u(u), v(v), s(s) {	}
} Edge;

int n, m;
vector<Edge> E;
vector<int> G[N];

#define NO { puts("NO"); exit(0); }

int vis[N];
int d[N], f[N];
int xs[N];
bool det[N];
vector<int> C[N];
void dfs(int p, int fa, int id) {
	vis[p] = id;
	C[id].push_back(p);
	for (auto ei : G[p]) {
		int e = E[ei].u ^ E[ei].v ^ p;
		if (!vis[e]) {
			d[e] = -d[p], f[e] = E[ei].s - f[p];
			dfs(e, p, id);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	E.resize(m);
	for (int i = 0, u, v, s; i < m; i++) {
		scanf("%d%d%d", &u, &v, &s);
		E[i].u = u;
		E[i].v = v;
		E[i].s = s << 1;
		G[u].push_back(i);
		G[v].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		det[i] = true; 
		if (!vis[i]) {
			d[i] = 1;
			f[i] = 0;
			dfs(i, 0, i);
			det[i] = false;
		}
	}
	for (auto e : E) {
		int u = e.u, v = e.v;
		if (d[u] != d[v]) {
			if (f[u] + f[v] != e.s) {
				NO;
			}
		} else {
			xs[vis[u]] = (e.s - f[u] - f[v]) / (d[u] + d[v]);
			det[vis[u]] = true;
		}
	}
	for (int p = 1; p <= n; p++) {
		if (!det[p]) {
			vector<int> a;
			for (auto i : C[p]) {
				a.push_back(-f[i] * d[i]);
			}
			sort(a.begin(), a.end());
			xs[p] = a[C[p].size() >> 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i] = d[i] * xs[vis[i]] + f[i];
	}
	for (auto e : E) {
		if (f[e.u] + f[e.v] != e.s) {
			NO
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) {
		if (f[i] < 0) {
			putchar('-');
			f[i] = -f[i];
		}
		printf("%d%s", f[i] >> 1, (f[i] & 1) ? (".5 ") : (".0 "));
	}
	return 0;
}