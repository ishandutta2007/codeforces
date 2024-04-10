
#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

void answer(int v) {
	printf("! %d\n", v + 1);
	fflush(stdout);
	exit(0);
}

int ask(int u, int v) {
	printf("? %d %d\n", u + 1, v + 1);
	fflush(stdout);
	
	ignore = scanf("%d", &v);
	return v - 1;
}

vector<int> G[MX];
bool dead[MX];
int t[MX], par[MX], sz[MX];

int dfs(int v, int p, int tt) {
	par[v] = p;
	t[v] = tt;
	sz[v] = 1;
	
	for (int u : G[v]) {
		if (u == p) continue;
		if (dead[u]) continue;
		
		sz[v] += dfs(u, v, tt);
	}
	
	return sz[v];
}

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		ignore = scanf("%d %d", &u, &v);
		u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	int v = 0, it = 0;
	while (true) {
		it++;
		dfs(v, -1, it);
		
		if (sz[v] == 1) answer(v);
		
		bool ok = false;
		for (int u = 0; u < n; u++)
			if (t[u] == it && sz[u] >= 2 && sz[v] - sz[u] >= 2) {
				int w = ask(u, par[u]);
				
				dead[w ^ u ^ par[u]] = true;
				
				v = w;
				
				ok = true;
				break;
			}
		
		if (ok) continue;
		
		for (int u = 0; u < n; u++)
			if (t[u] == it && sz[u] > 1 && u != v) {
				v = u;
				break;
			}
		
		it++;
		dfs(v, -1, it);
		
		int u = 0;
		while (t[u] != it || u == v) u++;
		
		if (sz[v] == 2) {
			int w = ask(u, v);
			dead[w ^ u ^ v] = true;
			v = w;
			continue;
		}
		
		int w = u + 1;
		while (t[w] != it || w == v) w++;
		
		int g = ask(u, w);
		if (g == u || g == w) answer(g);
		
		dead[u] = dead[w] = true;
	}
	
	return 0;
}