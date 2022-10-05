#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int g[N],he[N],fa[N],to[N<<1],ne[N<<1],c[N],sz[N],d[N],ls[N],rs[N],sn[N],w[N],id,p[N];
long long ans[N];
void dfs(int x,int y){
	d[x]=d[y]+1,fa[x]=y,sz[x]=1,p[ls[x]=++id]=x;
	for(int i=he[x],j;i;i=ne[i])if(j=to[i],j!=y){
		dfs(j,x),sz[x]+=sz[j];
		if(sz[j]>sz[sn[x]])sn[x]=j;
	}
	rs[x]=id;
}
void dp(int x,bool b){
	int i,j,k,l;
	for(i=he[x];i;i=ne[i])if(j=to[i],j!=sn[x]&&j!=fa[x])dp(j,1);
	if(sn[x])dp(sn[x],0),w[x]=w[sn[x]],ans[x]=ans[sn[x]];
	if(++g[c[x]],g[c[x]]>w[x])w[x]=g[c[x]],ans[x]=c[x];
	else if(g[c[x]]==w[x])ans[x]+=c[x];
	for(i=he[x];i;i=ne[i])if(j=to[i],j!=sn[x]&&j!=fa[x]){
		for(k=ls[j];k<=rs[j];++k){
			if(++g[l=c[p[k]]],g[l]>w[x])w[x]=g[l],ans[x]=l;
			else if(g[l]==w[x])ans[x]+=l;
		}
	}
	if(b)for(i=ls[x];i<=rs[x];++i)g[c[p[i]]]=0;
}
int main(){
	int n,i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",c+i);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs(1,0),dp(1,0);
	for(i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}