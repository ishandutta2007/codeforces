#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
int n, q, U[N], V[N], W[N];
bool tree[N];
vector<pii> e[N];
int fa[N];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
bool uni(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return false;
	fa[u] = v;
	return true;
}
int st[N], ed[N], Xor[N], clk, dep[N], pa[N][21];
void dfs(int u, int ft) {
	pa[u][0] = ft;
	rep(j, 1, 19) pa[u][j] = pa[pa[u][j - 1]][j - 1];
	dep[u] = dep[ft] + 1;
	st[u] = ++clk;
	for(auto _V : e[u]) {
		int v = _V.fi, w = _V.se;
		if(v == ft) continue;
		Xor[v] = Xor[u] ^ w;
		dfs(v, u);
	}
	ed[u] = clk;
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int t = dep[u] - dep[v];
	rep(j, 0, 19) if(t >> j & 1) u = pa[u][j];
	if(u == v) return u;
	per(j, 0, 19) {
		if(pa[u][j] != pa[v][j]) {
			u = pa[u][j];
			v = pa[v][j];
		}
	}
	return pa[u][0];
}
int D[N];
void add(int p, int v) {for(; p <= n; p += lowbit(p)) D[p] += v;}
int query(int p) {int res = 0; for(; p; p -= lowbit(p)) res += D[p]; return res;}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, q) {
		scanf("%d%d%d", &U[i], &V[i], &W[i]);
		if(uni(U[i], V[i])) {
			e[U[i]].emplace_back(V[i], W[i]);
			e[V[i]].emplace_back(U[i], W[i]);
			tree[i] = 1;
		}
	}
	rep(i, 1, n) {
		if(st[i]) continue;
		dfs(i, 0);
	}
	rep(i, 1, q) {
		if(tree[i]) continue;
		int u = U[i], v = V[i];
		if((Xor[u] ^ Xor[v] ^ W[i]) != 1) continue;
		int l = lca(u, v);
		if(query(st[u]) + query(st[v]) - 2 * query(st[l]) != 0) continue;
		// printf("loop: %d %d\n", u, v);
		tree[i] = 1;
		while(u != l) {
			add(st[u], 1);
			add(ed[u] + 1, -1);
			u = pa[u][0];
		}
		while(v != l) {
			add(st[v], 1);
			add(ed[v] + 1, -1);
			v = pa[v][0];
		}
	}
	rep(i, 1, q) puts(tree[i] ? "YES" : "NO");
	return 0;
}