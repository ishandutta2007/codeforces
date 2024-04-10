#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int f[N],h[N],nxt[N],adj[N],u,v,t,n,m,T,ans[N],o;
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il int Max(ct p,ct q){return p>q?p:q;}
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i) h[i]=0;t=o=0;
		while(m--) scanf("%d%d",&u,&v),add(),f[u]=f[v]=0;
		for(i=1;i<=n;++i){
			for(j=h[i];j;j=nxt[j])
				f[i]=Max(f[i],f[adj[j]]+1);
			if(f[i]>2) f[i]=-1,ans[++o]=i;
		}
		printf("%d\n",o);
		for(i=1;i<=o;++i) printf("%d ",ans[i]);puts("");
	}
	return 0;
}