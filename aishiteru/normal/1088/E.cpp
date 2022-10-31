#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
#define P 998244353
typedef long long ll;
#define rll register ll
#define cll const ll
int n,a[N],h[N],nxt[N],adj[N],u,v,t,fa[N],o;
long long ans,f[N];
template<class I>
il I Max(I p,I q){return p>q?p:q;}
template<class I>
il void ckMax(I&p,I q){p=(p>q?p:q);}
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il void dfs(ct x){
	f[x]=a[x];
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa[x])
			fa[j]=x,dfs(j),f[x]+=Max(f[j],0ll);
	ckMax(ans,f[x]);
}
il void DFS(ct x){
	f[x]=a[x];
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa[x])
			fa[j]=x,DFS(j),f[x]+=Max(f[j],0ll);
	if(f[x]==ans) ++o,f[x]=-1e18;
}
int main(){ 
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<n;++i) scanf("%d%d",&u,&v),add();
	ans=-1e18,dfs(1),DFS(1),printf("%lld ",ans*o),printf("%d",o);
	return 0;
}