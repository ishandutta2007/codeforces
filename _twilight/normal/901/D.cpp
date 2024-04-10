#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll long long
#define pii pair<int, int>

int n, m;
int d[N];
ll a[N], w[N];
boolean vis[N];
vector<pii> G[N];
int fap[N], fae[N];

void dfs(int p, int fa, int fe) {
	fap[p] = fa, fae[p] = fe;
	vis[p] = true;
	for (auto par : G[p]) {
		int e = par.first;
		int id = par.second;
		if (!vis[e]) {
			dfs(e, p, id);
		}
	}
	if (fe) {
		w[fe] = a[p];
		a[p] -= w[fe];
		a[fa] -= w[fe];
	}
} 

int bt, tp;
void find_cir(int p, int fa) {
	d[p] = d[fa] ^ 1;
	vis[p] = true;
	for (auto par : G[p]) {
		int e = par.first;
		int id = par.second;
		if (!vis[e]) {
			find_cir(e, p);
		} else if (d[e] == d[p]) {
			bt = p, tp = e;
			throw id;
		}
	}
}

void putans() {
	puts("YES");
	for (int i = 1; i <= m; i++) {
		printf("%lld\n", w[i]);
	}
	exit(0);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}
	dfs(1, 0, 0);
	if (!a[1])
		putans();
	memset(vis, 0, sizeof(vis));
	try {
		find_cir(1, 0);
	} catch (int id) {
		assert(!(a[1] & 1));
		ll dlt = a[1] >> 1;
		if (!d[tp]) 
			dlt = -dlt;
		w[id] += dlt;
		for (int p = bt; p ^ tp; p = fap[p])
			w[fae[p]] += (dlt = -dlt);
		dlt <<= 1;
		for (int p = tp; p; p = fap[p])
			w[fae[p]] += (dlt = -dlt);
		putans();
	}
	puts("NO");
	return 0;
}