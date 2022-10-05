#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=2e5+3;
basic_string<int>e[N],g[M];
typedef int an[N];
typedef int am[M];
an dfn,low,st;
am sz,d,fa,sn,tp;
int t,id,ct;
void tar(int x){
	dfn[x]=low[x]=++id,st[++t]=x;
	for(int i:e[x])if(!dfn[i]){
		tar(i),low[x]=min(low[x],low[i]);
		if(low[i]==dfn[x])for(g[x]+=++ct;g[ct]+=st[t],st[t--]!=i;);
	}else low[x]=min(low[x],dfn[i]);
}
void dfs(int x){
	sz[x]=1;
	for(int i:g[x])if(d[i]=d[x]+1,fa[i]=x,dfs(i),sz[i]>sz[sn[x]])sn[x]=i;
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
	int n,m,q,i,j;
	scanf("%d%d%d",&n,&m,&q),ct=n;
	while(m--)scanf("%d%d",&i,&j),e[i]+=j,e[j]+=i;
	tar(1),dfs(1),dfs(1,1);
	while(q--)scanf("%d%d",&i,&j),printf("%d\n",(d[i]+d[j])/2-d[lca(i,j)]);
	return 0;
}