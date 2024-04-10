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
int n, sg[N], fa[N], ans, nodes;
VI e[N];
bool used[N], vis[N];
void dfs(int u, int pa) {
	fa[u] = pa;
	for(auto v : e[u]) {
		if(v == pa) continue;
		dfs(v, u);
		sg[u] ^= sg[v] + 1;
	}
}
void add(int u) {
	used[u] = 1;
	nodes++;
	if(vis[u]) ans ^= sg[u] + 1, vis[u] = 0;
	for(auto v : e[u]) {
		if(!used[v] && !vis[v] && v != fa[u]) {
			ans ^= sg[v] + 1;
			vis[v] = 1;
		}
	}
}
void ins(int u) {
	while(u && !used[u]) {
		add(u);
		u = fa[u];
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	rep(i, 1, n) {
		ins(i);
		putchar((ans ^ ((nodes - 1) & 1)) ? '1' : '2');
	}
	return 0;
}