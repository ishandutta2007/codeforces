#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=2e5+3;
bool f[N],g[N];
int he[N],to[M],ne[M],dfn[N],low[N],id,st[N],tp,ed[N],et;
void tar(int x){
	dfn[x]=low[x]=++id,st[++tp]=x;
	for(int i=he[x],j,k,t,o;i;i=ne[i]){
		if(k=et,!g[i/2])g[ed[++et]=i/2]=1;
		if(!dfn[j=to[i]]){
			tar(j),low[x]=min(low[x],low[j]);
			if(low[j]==dfn[x]){
				for(t=2;st[tp--]!=j;++t);
				for(o=t==et-k;et!=k;f[ed[et--]]=o);
			}
		}else low[x]=min(low[x],dfn[j]);
	}
}
int main(){
	int n,m,i,j,k,t=1;
	scanf("%d%d",&n,&m);
	for(k=1;k<=m;++k){
		scanf("%d%d",&i,&j);
		ne[++t]=he[i],to[t]=j,he[i]=t;
		ne[++t]=he[j],to[t]=i,he[j]=t;
	}
	for(i=1;i<=n;++i)if(!dfn[i])tar(i);
	for(i=1,j=0;i<=m;++i)j+=f[i];
	for(i=1,printf("%d\n",j);i<=m;++i)if(f[i])printf("%d ",i);
	return 0;
}