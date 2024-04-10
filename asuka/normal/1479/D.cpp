#include<bits/stdc++.h>
#define ll long long
#define N 600015
#define B 776
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
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
int n,m,a[N],cnt[N],ccnt[N];
VI e[N];
int st[N],ed[N],rev[N],clk;
int fa[N][25],dep[N];
struct query{
	int l,r,L,R,lca,id;
	bool operator <(const query& rhs) const{
		if(l/B != rhs.l/B) return l/B < rhs.l/B;
		if((l/B)&1) return r/B < rhs.r/B;
		return r/B > rhs.r/B;
	}
}q[N];
void dfs(int u,int f){
	fa[u][0] = f; dep[u] = dep[f]+1; st[u] = ++clk; rev[clk] = u;
	rep(i,1,19) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(auto v:e[u]) if(v != f){
		dfs(v,u);
	}
	ed[u] = ++clk; rev[clk] = u;
}
int lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	int d = dep[u]-dep[v];
	rep(i,0,19) if((1<<i)&d) u = fa[u][i];
	if(u == v) return u;
	per(i,0,19){
		if(fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
	}
	return fa[u][0];
}
void getq(){
	rep(i,1,m){
		int u,v,l,r; scanf("%d%d%d%d",&u,&v,&l,&r);
		int LCA = lca(u,v);
		q[i].id = i; q[i].L = l,q[i].R = r;
		if(st[u] > st[v]) swap(u,v);
		if(u == LCA) q[i].l = st[u],q[i].r = st[v];
		else q[i].l = ed[u],q[i].r = st[v],q[i].lca = LCA;
	}
	sort(q+1,q+m+1);
}
int ans[N];
void add(int x){
	if(cnt[x]) ccnt[x/B]--;
	else ccnt[x/B]++;
	cnt[x] ^= 1;
}
int getans(int l,int r){
	rep(i,l/B+1,r/B-1){
		if(!ccnt[i]) continue;
		rep(j,i*B,i*B+B-1) if(cnt[j]) return j;
	}
	int R = l/B*B+B-1,L = r/B*B;
	rep(i,l,min(r,R)) if(cnt[i]) return i;
	rep(i,max(l,L),r) if(cnt[i]) return i;
	return -1;
}
void solve(){
	for(int i = 1,l = 1,r = 0;i <= m;++i){
		while(l > q[i].l) add(a[rev[--l]]);
		while(r < q[i].r) add(a[rev[++r]]);
		while(l < q[i].l) add(a[rev[l++]]);
		while(r > q[i].r) add(a[rev[r--]]);
		if(q[i].lca) add(a[q[i].lca]);
		ans[q[i].id] = getans(q[i].L,q[i].R);
		if(q[i].lca) add(a[q[i].lca]);
	}
	rep(i,1,m) printf("%d\n",ans[i]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	rep(i,1,n) scanf("%d",&a[i]);
 	rep(i,2,n){ int u,v; scanf("%d%d",&u,&v);
 		e[u].pb(v); e[v].pb(u);
 	}
 	dfs(1,0);
 	getq();
 	solve();
	return 0;
}