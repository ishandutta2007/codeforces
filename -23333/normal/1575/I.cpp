#include <bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long ll;
int n,q,head[N],tot;
int p[N][22],deep[N],a[N];
int siz[N],dfn[N];
ll tr[N];
struct edge{
	int n,to;
}e[N<<1];
inline void add(int u,int v){
	e[++tot].n=head[u];
	e[tot].to=v;
	head[u]=tot; 
}
void upd(int x,ll c){
	while(x<=n)tr[x]+=c,x+=x&-x;
}
ll query(int x){
	ll ans=0;
	while(x)ans+=tr[x],x-=x&-x;
	return ans;
}
inline void sol(int l,int r,int c){
	upd(l,c);if(r<n)upd(r+1,-c);
}
inline int getlca(int u,int v){
	if(deep[u]<deep[v])swap(u,v);
	for(int i=20;i>=0;--i)if(deep[u]-(1<<i)>=deep[v])
		u=p[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;--i)if(p[u][i]!=p[v][i])
		u=p[u][i],v=p[v][i];
	return p[u][0]; 
}
void dfs(int u,int fa){
	siz[u]=1;
	dfn[u]=++dfn[0];
	for(int i=1;(1<<i)<=deep[u];++i)
		p[u][i]=p[p[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].n)if(e[i].to!=fa){
		int v=e[i].to;
		deep[v]=deep[u]+1;
		p[v][0]=u;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
inline void work(int i,int tag){
	if(i!=1)sol(dfn[i],dfn[i]+siz[i]-1,a[i]*tag);
	if(siz[i]!=1){
		sol(dfn[i]+1,dfn[i]+siz[i]-1,a[i]*tag);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);a[i]=abs(a[i]);
	}
	int opt,u,v,c;
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i){
		work(i,1);
	}
	while(q--){
		scanf("%d%d",&opt,&u);
		if(opt==1){
			scanf("%d",&c);c=abs(c);
			work(u,-1);
			a[u]=c;
			work(u,1);
		}
		else{
			scanf("%d",&v);
			printf("%lld\n",query(dfn[u])+query(dfn[v])-2*query(dfn[getlca(u,v)]));
		}
	}
	return 0; 
}

/*%4=0
0110
1001 */ 
//0110 1001 1001