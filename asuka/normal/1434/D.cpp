#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,x[N],y[N],val[N],max1[N],dep[N],cnt,m;
struct edge{
	int to,next,val;
	edge(){}
	edge(int a,int b,int c){to = a;next = b;val = c;}
}e[N<<1];
int head[N];
void add(int u,int v,int w){
	e[++cnt] = edge(v,head[u],w);
	head[u] = cnt;
}
void dfs1(int u,int fa){
	dep[u] = dep[fa]+1;
	max1[u] = u;
	for(int i = head[u];~i;i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		dfs1(v,u);
		if(dep[max1[v]] > dep[max1[u]]){
			max1[u] = max1[v];
		}
	}
	//cout <<u << ' '<< max1[u] << ' ' << max2[u] << endl;
}
struct seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int dfn[N],rnk[N],siz[N],dis[N],typ[N],f[N],Max[N<<2][2],lazy[N<<2],clk;
	void dfs(int u,int fa){
		dfn[u] = ++clk; rnk[clk] = u;
		siz[u] = 1; dis[u] = dis[fa]+1;
		for(int i = head[u];~i;i = e[i].next){
			int v = e[i].to;
			if(v == fa) continue;
			f[v] = u; typ[v] = typ[u]^e[i].val;
			dfs(v,u);
			siz[u] += siz[v];
		}
	}
	void pushup(int p){rep(i,0,1) Max[p][i] = max(Max[ls][i],Max[rs][i]);}
	void down(int p){lazy[p] ^= 1;swap(Max[p][0],Max[p][1]);}
	void pushdown(int p){
		if(lazy[p]){
			down(ls);down(rs);
			lazy[p] = 0;
		}
	}
	void build(int p,int l,int r){
		if(l == r){
			Max[p][typ[rnk[l]]] = dis[rnk[l]];
			return ;
		}
		int mid = (l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(p);
	}
	void change(int p,int l,int r,int x,int y){
		//cout << l<< ' ' << r << ' ' << x << ' ' << y << endl;
		if(x <= l && r <= y){
			down(p);
			return ;
		}
		int mid = (l+r)>>1;
		pushdown(p);
		if(x <= mid) change(ls,l,mid,x,y);
		if(y > mid) change(rs,mid+1,r,x,y);
		pushup(p);
	}
	int query(){return Max[1][0];}
}t1,t2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	rep(i,1,n-1)
		scanf("%d%d%d",&x[i],&y[i],&val[i]),add(x[i],y[i],val[i]),add(y[i],x[i],val[i]);
	dfs1(1,0); int r1 = max1[1];
	dfs1(r1,0); int r2 = max1[r1];
	//cout << r1 << ' ' << r2 << endl;
	t1.dfs(r1,0);t2.dfs(r2,0);
	t1.build(1,1,n); t2.build(1,1,n);
	scanf("%d",&m);
	rep(i,1,m){
		int uu; scanf("%d",&uu);
		if(t1.f[x[uu]] == y[uu]) t1.change(1,1,n,t1.dfn[x[uu]],t1.dfn[x[uu]]+t1.siz[x[uu]]-1);
		else t1.change(1,1,n,t1.dfn[y[uu]],t1.dfn[y[uu]]+t1.siz[y[uu]]-1);
		if(t2.f[x[uu]] == y[uu]) t2.change(1,1,n,t2.dfn[x[uu]],t2.dfn[x[uu]]+t2.siz[x[uu]]-1);
		else t2.change(1,1,n,t2.dfn[y[uu]],t2.dfn[y[uu]]+t2.siz[y[uu]]-1);
		printf("%d\n",max(t1.query(),t2.query())-1);
	}
	return 0;
}