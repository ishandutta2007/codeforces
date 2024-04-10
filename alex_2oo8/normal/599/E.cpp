#include<bits/stdc++.h>

using namespace std;

long long dp[1 << 13][13], g[1 << 13];
bool good[1 << 13];
int parent[1 << 13], root[1 << 13], n;

long long solve(int mask, int root);

long long f(int mask) {
	if (g[mask] == -1) {
		if (root[mask] == -1) {
			g[mask] = 0;
			for (int i = 0; i < n; i++)
				if (((mask >> i) & 1) == 1)
					g[mask] += solve(mask ^ (1 << i), i);
		}
		else g[mask] = solve(mask ^ (1 << root[mask]), root[mask]);
	}
	
	return g[mask];
}

long long solve(int mask, int root) {
	if (mask == 0) return 1;
	
	if (dp[mask][root] == -1) {
		dp[mask][root] = 0;
		
		for (int i = mask; i > 0; i = (i - 1) & mask) {
			if ((i & mask & -mask) == 0 || !good[i] || (parent[i] != -1 && parent[i] != root)) continue;
			
			dp[mask][root] += solve(mask ^ i, root) * f(i);
		}
	}
	
	return dp[mask][root];
}

int u[100], v[100], a[100], b[100], c[100];

int main() {
	int m, q;
	scanf("%d %d %d", &n, &m, &q);
	
	if (n == 1) {
		printf("1\n");
		
		return 0;
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", u + i, v + i);
		
		u[i]--;
		v[i]--;
	}
	
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", a + i, b + i, c + i);
		
		a[i]--;
		b[i]--;
		c[i]--;
	}
	
	for (int i = 0; i < (1 << n); i++) {
		good[i] = true;
		parent[i] = root[i] = -1;
		g[i] = -1;
		for (int j = 0; j < n; j++) dp[i][j] = -1;
		
		for (int j = 0; j < m; j++) {
			int w = -1;
			if (((i >> u[j]) & 1) == 1 && ((i >> v[j]) & 1) == 0) w = v[j];
			if (((i >> v[j]) & 1) == 1 && ((i >> u[j]) & 1) == 0) w = u[j];
			
			if (w != -1) {
				if (parent[i] == -1) parent[i] = w, root[i] = u[j] + v[j] - w;
				else good[i] = false;
			}
		}
		
		for (int j = 0; j < q; j++) {
			int cnt = 0;
			if (((i >> a[j]) & 1) == 1) cnt++;
			if (((i >> b[j]) & 1) == 1) cnt++;
			if (((i >> c[j]) & 1) == 1) cnt++;
			
			if (cnt == 2 || (cnt == 1 && ((i >> c[j]) & 1) == 1)) good[i] = false;
		}
	}
	
	printf("%I64d\n", solve((1 << n) - 2, 0));
	
	return 0;
}