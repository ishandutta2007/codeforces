#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int n,m,k,h[N],nxt[N],adj[N],kk,t,u,v,fa[N],ti,dfn[N],d[N],lef[N];
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il void dfs(ct x){
	d[x]=d[fa[x]]+1,dfn[x]=++ti;it fl=1;
	if(d[x]>=kk){puts("PATH"),printf("%d\n",d[x]);for(it i=x;i;i=fa[i]) printf("%d ",i);exit(0);}
	for(it i=h[x],j;i;i=nxt[i])
		if(!dfn[j=adj[i]]) fa[j]=x,dfs(j),fl=0;
	if(fl) lef[++*lef]=x;
}
il void cal(ct x){
	vector<int> p;
	for(it i=h[x],j;i;i=nxt[i]){
		j=adj[i],p.size()^2?p.push_back(j),0:0;
		if((j^fa[x])&&((d[x]-d[j]+1)%3)){printf("%d\n",d[x]-d[j]+1);for(it i=x;i^fa[j];i=fa[i]) printf("%d ",i);puts("");return;}
	}
	std::sort(p.begin(),p.end(),[&](ct p,ct q){return d[p]<d[q];});
	printf("%d\n",d[p[1]]-d[p[0]]+2);it i;
	for(i=p[1];fa[i]^fa[p[0]];i=fa[i]) printf("%d ",i);
	printf("%d %d\n",i,x);
}
int main(){
	scanf("%d%d%d",&n,&m,&k),kk=(n+k-1)/k;it i;
	while(m--) scanf("%d%d",&u,&v),add();
	dfs(1),puts("CYCLES");
	for(i=1;i<=k;++i) cal(lef[i]); 
	return 0;
}