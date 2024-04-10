#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = 3e5;
int n, m, k;
int lev[maxn];
vector<int> g[maxn], leaf;
int p[maxn];
int u[maxn];
void dfs(int v, int pa) {
	p[v] = pa;
	lev[v] = lev[pa] + 1;
	u[v] = 1;
	int cnt = 0;
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if(!u[to]) {
			dfs(to, v);
			cnt++;
		}
	}
	if(cnt == 0) leaf.push_back(v);
}
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		if(lev[i] * 1ll * k >= n) {
			printf("PATH\n");
			printf("%d\n", lev[i]);
			for(int j = i; j > 0; j = p[j]) {
				printf("%d ", j);
			}
			return;
		}
	}
	printf("CYCLES\n");
	for(int i = 0; i < k; i++) {
		int v = leaf[i];
		int z = 1;
		vector<int> h;
		for(int j = 0; j < g[v].size(); j++) {
			int to = g[v][j];
			if(to == p[v]) continue;
			int d = lev[v] - lev[to] + 1;
			if(h.size() < 2) h.push_back(to);
			if(d % 3 == 0) continue;
			printf("%d\n", d);
			for(int f = v; ; f = p[f]) {
				printf("%d ", f);
				if(f == to) break;
			}
			printf("\n");
			z = 0;
			break;
		}
		if(z) {
			int v1 = h[0];
			int v2 = h[1];
			if(lev[v1] < lev[v2]) swap(v1, v2);
			printf("%d\n", lev[v1] - lev[v2] + 2);
			for(int f = v1; ; f = p[f]) {
				printf("%d ", f);
				if(f == v2) break;
			}
			printf("%d\n", v);
		}

	}
}
int main(){
	solve();
	return 0;
}