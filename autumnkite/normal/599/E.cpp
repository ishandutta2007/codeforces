#include <cstdio>
#include <cstring>
int n, m, q, edge[15][15];
struct Edge{ int x, y; } E[15];
struct node{ int x, y, z; } a[105];
long long dp[15][100005];
bool in(int x, int s){ return s & (1 << x); }
long long dfs(int u, int mask){
	long long &res = dp[u][mask];
	if (~res) return res;
	res = 0, mask -= 1 << u;
	int pos;
	for (pos = 0; pos < n; ++pos) if (in(pos, mask)) break;
	for (register int submask = mask; submask; submask = (submask - 1) & mask)
		if (in(pos, submask)){
			int flag = 1, v, cnt = 0;
			for (register int i = 1; i <= q; ++i)
				if (a[i].z == u && in(a[i].x, submask) && in(a[i].y, submask))
					{ flag = 0; break; }
			if (!flag) continue;
			for (register int i = 1; i <= q; ++i) 
				if (in(a[i].z, submask) && (!in(a[i].x, submask) || !in(a[i].y, submask)))
					{ flag = 0; break; }
			for (register int i = 1; i <= m; ++i)
					if (E[i].x != u && E[i].y != u && (in(E[i].x, submask) ^ in(E[i].y, submask)))
						{ flag = 0; break; }
			if (!flag) continue;
			for (register int i = 0; i < n; ++i)
				if (edge[u][i] && in(i, submask)){ ++cnt; v = i; }
			if (cnt > 1) continue;
			if (cnt == 1) res += dfs(v, submask) * dfs(u, mask ^ submask ^ (1 << u));
			else{
				for (v = 0; v < n; ++v)
					if (in(v, submask)) res += dfs(v, submask) * dfs(u, mask ^ submask ^ (1 << u));
			}
		}
	return res;
}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (register int i = 1; i <= m; ++i)
		scanf("%d%d", &E[i].x, &E[i].y), --E[i].x, --E[i].y, 
		edge[E[i].x][E[i].y] = edge[E[i].y][E[i].x] = 1;
	for (register int i = 1; i <= q; ++i)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z), --a[i].x, --a[i].y, --a[i].z;
	memset(dp, -1, sizeof dp);
	for (register int i = 0; i < n; ++i) dp[i][1 << i] = 1;
	printf("%lld", dfs(0, (1 << n) - 1));
}