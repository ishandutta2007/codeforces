#include<bits/stdc++.h>
#define ll long long
#define N 205
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, K, d[N], f[N][N][N], g[N][N], pa[N], dis[N][N];
struct node{
	int i,j,k;
	node(){}
	node(int a, int b, int c){i = a; j = b; k = c;}
};
node ffrom[N][N][N], gfrom[N][N];
VI e[N], vec;
void dfs1(int rt,int u,int fa){
	dis[rt][u] = dis[rt][fa] + 1;
	for(auto v : e[u]) if(v != fa) {
		dfs1(rt, v, u);
	} 
}
void dfs(int u, int fa) {
	bool flag = 0; pa[u] = fa;
	for (auto v : e[u]) if (v != fa) {
		dfs(v, u);
		flag = 1;
	}
	// printf("CUR: %d\n", u);
	if (flag == 0) {
		rep(j, 1, n) {
			f[u][j][0] = K; ffrom[u][j][0] = node(-1, -1, -1);
			f[u][j][n] = d[j]; ffrom[u][j][n] = node(0, 0, 0);
			if(f[u][j][0] < g[u][j]) g[u][j] = f[u][j][0], gfrom[u][j] = node(u, j, 0);
			if(f[u][j][n] < g[u][j]) g[u][j] = f[u][j][n], gfrom[u][j] = node(u, j, n); 
		}
		return;
	}
	rep(j, 1, n) rep(k, 0, n) {
		ll sum = 0;
		int Min = inf;
		if(k == 0) { // choose u
			for(auto v : e[u]) if(v != fa){
				sum += g[v][1];
			}
			if(sum + K < f[u][j][k]) f[u][j][k] = sum + K, ffrom[u][j][k] = node(-1, -1, -1);
			if(f[u][j][k] < inf) {
				// printf("%d %d -> %d\n", j, k, f[u][j][k]);
			} 
			if(f[u][j][k] < g[u][j]) g[u][j] = f[u][j][k], gfrom[u][j] = node(u, j, k);
			continue;
		}
		if(k == n) { // nothing
			node from = node(0, 0, 0);
			for (auto v : e[u]) if (v != fa) { // not choose u
				// if(g[v][min(j, k) + 1] == inf ||)
				sum += f[v][j + 1][k];
			}
			if(sum + d[j] < f[u][j][k]) f[u][j][k] = sum + d[j], ffrom[u][j][k] = from;
			if(f[u][j][k] < inf) {
				// printf("%d %d -> %d\n", j, k, f[u][j][k]);
			} 
			if(f[u][j][k] < g[u][j]) g[u][j] = f[u][j][k], gfrom[u][j] = node(u, j, k);
			continue;
		}
		node from;
		for (auto v : e[u]) if (v != fa) { // not choose u
			// if(g[v][min(j, k) + 1] == inf ||)
			sum += g[v][min(min(j, k) + 1, n)];
			if(f[v][min(j + 1, n)][k - 1] - g[v][min(min(j, k) + 1, n)] < Min){
				Min = f[v][min(j + 1, n)][k - 1] - g[v][min(min(j, k) + 1, n)];
				from = node(v, min(j + 1, n),k - 1);
			}
		}
		if(sum + Min + d[min(j, k)] < f[u][j][k]) f[u][j][k] = sum + Min + d[min(j, k)], ffrom[u][j][k] = from;
		if(f[u][j][k] < inf) {
			// printf("%d %d -> %d\n", j, k, f[u][j][k]);
		} 
		if(f[u][j][k] < g[u][j]) g[u][j] = f[u][j][k], gfrom[u][j] = node(u, j, k);
	}
}
void tag(node cur){
	if(ffrom[cur.i][cur.j][cur.k].i == 0) return;
	if(ffrom[cur.i][cur.j][cur.k].i == -1){ // choose
		vec.pb(cur.i);
		for(auto v : e[cur.i]) if(v != pa[cur.i]) {
			tag(gfrom[v][1]);
		}
		return;
	}
	tag(ffrom[cur.i][cur.j][cur.k]);
	for(auto v : e[cur.i]) if(v != pa[cur.i] && v != ffrom[cur.i][cur.j][cur.k].i){
		tag(gfrom[v][min(min(cur.j, cur.k) + 1, n)]);
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &K);
	rep(i, 1, n) rep(j, 1, n) rep(k, 0, n) f[i][j][k] = g[i][j] = inf;
	rep(i, 1, n - 1) scanf("%d", &d[i]); d[n] = inf;
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1, 0);
	int ans = inf; node from;
	rep(i, 0, n - 1) if(f[1][n][i] < ans) ans = f[1][n][i], from = node(1, n, i);
	printf("%d\n", ans);
	tag(from);
	rep(i, 1, n) dfs1(i, i, 0);
	rep(i, 1, n){
		int cur = vec[0];
		for(auto v : vec) if(dis[i][v] < dis[i][cur]) cur = v;
		printf("%d ", cur);
	}
	return 0;
}
/*
8 10
2 5 9 11 15 19 20
1 4
1 3
1 7
4 6
2 8
2 3
3 5
*/