#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int n,h[N],nxt[N],adj[N],a[N],w[N],u,v,x,t,fa[N];
long long ans,f[N];
template<class I>
il void ckMax(I&p,I q){p=(p>q?p:q);}
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,w[t]=x,nxt[++t]=h[v],h[v]=t,adj[t]=u,w[t]=x;}
il void dfs(ct x){
	register long long mx1=0,mx2=0;
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa[x]){
			fa[j]=x,dfs(j);
			if(f[j]+w[i]>=mx1) mx2=mx1,mx1=f[j]+w[i];
			else ckMax(mx2,f[j]+w[i]);
		}
	f[x]=mx1+a[x],ckMax(ans,mx1+mx2+a[x]),ckMax(ans,f[x]);
}
int main(){ 
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<n;++i) scanf("%d%d%d",&u,&v,&x),x=-x,add();
	dfs(1),printf("%lld",ans);
	return 0;
}