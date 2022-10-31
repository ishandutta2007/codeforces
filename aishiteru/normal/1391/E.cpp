#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int h[N],nxt[N<<1],adj[N<<1],n,m,T,t,u,v,fa[N],d[N],o1[N],o2[N],mxd,id;
std::vector<int> g[N];
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il void dfs(ct x){
	g[d[x]=d[fa[x]]+1].push_back(x);
	if(d[x]>=mxd) mxd=d[x],id=x;
	for(it i=h[x],j;i;i=nxt[i])
		if(!d[j=adj[i]]) fa[j]=x,dfs(j);
}
int main(){ 
	scanf("%d",&T);it i,j,co;
	while(T--){
		scanf("%d%d",&n,&m);co=mxd=id=0;
		for(i=1;i<=n;++i) d[i]=h[i]=fa[i]=0,g[i].clear();t=0;
		while(m--) scanf("%d%d",&u,&v),add();
		dfs(1);
		for(i=1;i<=mxd;++i)
			for(j=0;j+1<g[i].size();j+=2)
				o1[++co]=g[i][j],o2[co]=g[i][j+1];
		if((co<<1)>=(n+1>>1)){
			puts("PAIRING"),printf("%d\n",co);
			for(i=1;i<=co;++i) printf("%d %d\n",o1[i],o2[i]);
			continue;
		}
		puts("PATH");co=0;
		while(id) o1[++co]=id,id=fa[id];
		printf("%d\n",co);
		for(i=1;i<=co;++i) printf("%d ",o1[i]);
	}
	return 0;
}