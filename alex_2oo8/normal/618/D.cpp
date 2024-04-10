#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

vector<int> G[MX];
int can[MX];

int dfs(int v, int p = -1) {
	can[v] = 2;
	
	int res = 0;
	for (int u : G[v]) {
		if (u == p) continue;
		
		res += dfs(u, v);
		
		if (can[u] > 0 && can[v] > 0) {
			can[u]--;
			can[v]--;
			
			res++;
		}
	}
	
	return res;
}

int main() {
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if (x < y) {
		int f = dfs(0);
		
		printf("%lld\n", x * 1ll * f + y * 1ll * (n - 1 - f));
	}
	else {
		int mx = 0;
		for (int i = 0; i < n; i++) mx = max((int)G[i].size(), mx);
		
		if (mx == n - 1) printf("%lld\n", x + (n - 2) * 1ll * y);
		else printf("%lld\n", (n - 1) * 1ll * y);
	}
	
	return 0;
}