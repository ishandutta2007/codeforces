#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,q,cnt,w[N<<1];
multiset<int> S[N<<1];
VI g[N],e[N<<1];
void Add(int u,int v){
	e[u].pb(v); e[v].pb(u);
}
namespace BCT{
	int dfn[N],low[N],stk[N],clk,top;
	void Tarjan(int u){
		dfn[u] = low[u] = ++clk; stk[++top] = u;
		rep(i,0,SZ(g[u])-1){
			int v = g[u][i];
			if(!dfn[v]){
				Tarjan(v); low[u] = min(low[u],low[v]);
				if(low[v] == dfn[u]){
					cnt++;
					for(int _ = 0;_ != v; top--){
						_ = stk[top];
						Add(_,cnt);
					}
					Add(cnt,u);
				}
			}else low[u] = min(low[u],dfn[v]);
		}
	}
	void build(){
		cnt = n;
		Tarjan(1);
	}
}
namespace SP{
	int fa[N<<1],son[N<<1],dfn[N<<1],id[N<<1],clk,siz[N<<1],top[N<<1],dep[N<<1];
	void dfs0(int u,int f){
		siz[u] = 1; fa[u] = f; dep[u] = dep[f]+1;
		rep(i,0,SZ(e[u])-1){
			int v = e[u][i];
			if(v == f) continue;
			dfs0(v,u);
			siz[u] += siz[v];
			if(siz[v] > siz[son[u]]) son[u] = v;
		}
	}
	void dfs1(int u,int f,int tp){
		dfn[u] = ++clk; id[dfn[u]] = u; top[u] = tp;
		if(son[u]) dfs1(son[u],u,tp);
		rep(i,0,SZ(e[u])-1){
			int v = e[u][i];
			if(v == f || v == son[u]) continue;
			dfs1(v,u,v);
		}
	}
	#define ls (p<<1)
	#define rs (p<<1|1)
	int t[N<<3];
	void pushup(int p){return t[p] = min(t[ls],t[rs]),void();}
	void build(int p,int l,int r){
		if(l == r){t[p] = w[id[l]];return;}
		int mid = (l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
		pushup(p);
	}
	void change(int p,int l,int r,int pos,int val){
		if(l == r){return t[p] = val,void();}
		int mid = (l+r)>>1;
		if(pos <= mid) change(ls,l,mid,pos,val);
		else change(rs,mid+1,r,pos,val);
		pushup(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x <= l && r <= y) return t[p];
		int res = inf,mid = (l+r)>>1;
		if(x <= mid) res = min(res,query(ls,l,mid,x,y));
		if(y > mid) res = min(res,query(rs,mid+1,r,x,y));
		return res;
	}
	void init(){
		dfs0(1,0); dfs1(1,0,1);
		rep(i,1,n) if(fa[i]) S[fa[i]].insert(w[i]);
		rep(i,n+1,cnt) w[i] = *S[i].begin();
		build(1,1,cnt);
	}
}
using namespace SP;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,m){int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v); g[v].pb(u);
	}
	BCT::build();
	init();
	while(q--){
		char opt[3];
		int u,v;
		scanf("%s%d%d",opt,&u,&v);
		if(opt[0] == 'C'){
			if(fa[u]){
				S[fa[u]].erase(S[fa[u]].find(w[u]));
				S[fa[u]].insert(v);
				if(w[fa[u]] != *S[fa[u]].begin()){
					w[fa[u]] = *S[fa[u]].begin();
					change(1,1,cnt,dfn[fa[u]],w[fa[u]]);
				}
			}
			change(1,1,cnt,dfn[u],v);
			w[u] = v;
		}else{
			int ans = inf;
			while(top[u] != top[v]){
				if(dep[top[u]] < dep[top[v]]) swap(u,v);
				ans = min(ans,query(1,1,cnt,dfn[top[u]],dfn[u]));
				u = fa[top[u]]; 
			}
			if(dfn[u] > dfn[v]) swap(u,v);
			ans = min(ans,query(1,1,cnt,dfn[u],dfn[v]));
			// printf("u: %d fa[u]: %d\n",u,fa[u]);
			if(u > n) ans = min(ans,w[fa[u]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}