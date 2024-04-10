#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int f[N],g[N*9],ls[N],rs[N],p[N],sn[N],he[N],len[N],ne[N],sz[N],d[N],ans[N],id;
void dfs(int x,int y){
	sz[x]=1,p[ls[x]=++id]=x,d[x]=d[y]+1;
	for(int i=he[x];i;i=ne[i]){
		f[i]=f[x]^len[i],dfs(i,x),sz[x]+=sz[i];
		if(sz[i]>sz[sn[x]])sn[x]=i;
	}
	rs[x]=id;
}
void dp(int x,bool b){;
	int i,j,k,o,u,v;
	for(i=he[x];i;i=ne[i])if(i!=sn[x])dp(i,1),ans[x]=max(ans[x],ans[i]);
	if(sn[x])dp(sn[x],0),ans[x]=max(ans[x],ans[sn[x]]);
	if(k=g[f[x]])ans[x]=max(ans[x],k-d[x]);
	for(i=0;i<22;++i)if(k=g[f[x]^(1<<i)])ans[x]=max(ans[x],k-d[x]);
	g[f[x]]=max(d[x],g[f[x]]);
	for(i=he[x];i;i=ne[i])if(i!=sn[x]){
		for(j=ls[i];j<=rs[i];++j){
			u=f[p[j]],v=d[p[j]]-(d[x]<<1);
			if(k=g[u])ans[x]=max(ans[x],k+v);
			for(o=0;o<22;++o)if(k=g[u^(1<<o)])ans[x]=max(ans[x],k+v);
		}
		for(j=ls[i];j<=rs[i];++j)g[f[k=p[j]]]=max(g[f[k]],d[k]);
	}
	if(b)for(i=ls[x];i<=rs[x];++i)g[f[p[i]]]=0;
}
int main(){
	char c;
	int n,i,j;
	scanf("%d",&n);
	for(i=2;i<=n;++i)scanf("%d %c",&j,&c),ne[i]=he[j],len[i]=1<<c-'a',he[j]=i;
	dfs(1,0),dp(1,0);
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}