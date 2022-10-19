#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int n, m, ed[2][N], U[N << 1], V[N << 1], L[N << 1], R[N << 1], tot, ans[N << 1], id[N], deg[N];
bool vis[N], used[N << 1];
int get(int e, int u) {
	return u ^ U[e] ^ V[e];
}

void redir(int e, int u, int v, int w) {
	// printf("e: %d [%d %d]\n", e, L[e], R[e]);
	used[e] = 1;
	if(!L[e] && !R[e]) {
		ans[e] = U[e] == u ? 1 : 2;
		// printf("add %d -> %d\n", u, v);
		deg[u] += w + 1;
		deg[v] -= w + 1;
		return;
	}
	if(min(U[L[e]], V[L[e]]) == min(U[R[e]], V[R[e]]) && max(U[L[e]], V[L[e]]) == max(U[R[e]], V[R[e]])) {
		int lu = min(U[L[e]], V[L[e]]), ru = max(U[L[e]], V[L[e]]);
		redir(L[e], lu, ru, w);
		redir(R[e], ru, lu, w);
	} else if(U[L[e]] == u || V[L[e]] == u) {
		redir(L[e], u, get(L[e], u), w);
		redir(R[e], get(L[e], u), v, w);
	} else {
		redir(R[e], u, get(R[e], u), w);
		redir(L[e], get(R[e], u), v, w);
	}
}

int add(int u, int v, int w) {
	int cur = ++tot;
	U[cur] = u; V[cur] = v;
	// printf("add %d (%d %d)\n", cur, u, v);
	if(ed[w][u]) {
		int ov = get(ed[w][u], u), l = cur, r = ed[w][u];
		// printf("merge (%d %d) (%d %d)\n", U[l], V[l], U[r], V[r]);
		ed[w][u] = ed[w][ov] = 0;
		int p = add(v, ov, w);
		L[p] = l; R[p] = r;
	} else if(ed[w][v]) {
		int ou = get(ed[w][v], v), l = cur, r = ed[w][v];
		// printf("merge (%d %d) (%d %d)\n", U[l], V[l], U[r], V[r]);
		ed[w][v] = ed[w][ou] = 0;
		int p = add(u, ou, w);
		L[p] = l; R[p] = r;
	} else ed[w][u] = ed[w][v] = cur;
	return cur;
}

void dfs(int u) {
	vis[u] = 1;
	rep(w, 0, 1) {
		int e = ed[w][u], v = get(ed[w][u], u);
		if(!e) continue;
		if(!used[e]) redir(e, u, v, w);
		if(!vis[v]) dfs(v);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		w--;
		id[i] = add(u, v, w);
	}
	rep(i, 1, n) if((!ed[0][i] || !ed[1][i]) && !vis[i]) dfs(i);
	rep(i, 1, n) if(!vis[i]) dfs(i);
	int res = 0;
	rep(i, 1, n) if(abs(deg[i]) == 1) res++;
	printf("%d\n", res);
	rep(i, 1, m) printf("%d", ans[id[i]]);
	return 0;
}
/*
(1 2 0)
(1 3 1)
(2 5 1)
(4 5 0)
*/