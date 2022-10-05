#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=2e5+3,P=1e9+7;
int he[N],to[M],ne[M],fa[N],low[N],dfn[N],id,o,n,sz[N],sn[N],tp[N],d[N],h[N],bl[N];
basic_string<int>g[N],g2[N];
int qp(int a,int b,int r=1){
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
void tar(int x){
	dfn[x]=low[x]=++id,bl[x]=x;
	for(int i=he[x],j;i;i=ne[i])if(!dfn[j=to[i]]){
		fa[j]=x,tar(j),low[x]=min(low[x],low[j]);
		if(low[j]>dfn[x])g2[x]+=j;
	}else if(dfn[j]>dfn[x]&&fa[j]!=x)for(bl[x]=++o;j!=x;j=fa[j])bl[j]=o;
	else if(j!=fa[x])low[x]=min(low[x],dfn[j]);
}
void dfs(int x){
	sz[x]=1;
	if(x>n)++h[x];
	for(int i:g[x]){
		h[i]=h[x],d[i]=d[x]+1,fa[i]=x,dfs(i),sz[x]+=sz[i];
		if(sz[i]>sz[sn[x]])sn[x]=i;
	}
}
void dfs(int x,int y){
	tp[x]=y;
	if(sn[x])dfs(sn[x],y);
	for(int i:g[x])if(i!=sn[x])dfs(i,i);
}
int lca(int x,int y){
	for(;tp[x]!=tp[y];x=fa[tp[x]])if(d[tp[x]]<d[tp[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
int main(){
	int m,q,i,j,l,t=0;
	scanf("%d%d",&n,&m),o=n;
	while(m--){
		scanf("%d%d",&i,&j);
		ne[++t]=he[i],to[t]=j,he[i]=t;
		ne[++t]=he[j],to[t]=i,he[j]=t;
	}
	tar(1);
	for(i=1;i<=n;++i)for(int j:g2[i])g[bl[i]]+=bl[j];
	dfs(bl[1]),dfs(bl[1],bl[1]),scanf("%d",&q);
	while(q--){
		scanf("%d%d",&i,&j),i=bl[i],j=bl[j],l=lca(i,j);
		printf("%d\n",qp(2,h[i]+h[j]-h[l]-h[fa[l]]));
	}
	return 0;
}