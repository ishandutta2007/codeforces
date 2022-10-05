#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=4e5+3;
typedef int arr[N];
int id,to[M],ne[M],a[M];
arr he,sz,tp,fa,sn,d,p,c,u,x,y,s,f;
vector<int>v[N];
void dfs1(int x,int y){
	fa[x]=y,d[x]=d[y]+1,sz[x]=1;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y){
		dfs1(j,x),sz[x]+=sz[j];
		if(sz[sn[x]]<sz[j])sn[x]=j;
	}
}
void dfs2(int x,int y){
	p[x]=++id,tp[x]=y;
	if(sn[x])dfs2(sn[x],y);
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=fa[x]&&j!=sn[x])dfs2(j,j);
}
int lca(int x,int y){
	for(;tp[x]!=tp[y];x=fa[tp[x]])if(d[tp[x]]<d[tp[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
bool cmp(int x,int y){return p[x]<p[y];}
int main(){
	int n,q,i,j,k,t=0,m,o,nx,ny;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs1(1,0),dfs2(1,1),scanf("%d",&q);
	while(q--){
		scanf("%d%d",&k,&m),o=0;
		for(i=1;i<=k;++i)scanf("%d%d",&j,s+i),c[j]=i,a[++o]=j;
		for(i=1;i<=m;++i)if(scanf("%d",u+i),!c[u[i]])a[++o]=u[i];
		sort(a+1,a+o+1,cmp),n=o;
		for(i=1;i<o;++i)a[++n]=lca(a[i],a[i+1]);
		sort(a+1,a+n+1,cmp),n=unique(a+1,a+n+1)-a-1;
		for(i=2;i<=n;++i)j=lca(a[i-1],a[i]),v[j].push_back(a[i]),f[a[i]]=j;
		for(i=n;i>1;--i)if(c[k=a[i]]){
			j=f[k],ny=y[k]+d[k]-d[j],nx=(ny+s[c[k]]-1)/s[c[k]];
			if(!c[j]||nx<x[j]||(nx==x[j]&&c[k]<c[j]))c[j]=c[k],x[j]=nx,y[j]=ny;
		}
		for(i=1;i<=n;++i)for(int k:v[j=a[i]]){
			ny=y[j]+d[k]-d[j],nx=(ny+s[c[j]]-1)/s[c[j]];
			if(!c[k]||nx<x[k]||(nx==x[k]&&c[j]<c[k]))c[k]=c[j],x[k]=nx,y[k]=ny;
		}
		for(i=1;i<=m;++i)printf("%d ",c[u[i]]);
		for(puts(""),i=1;i<=n;++i)j=a[i],c[j]=x[j]=y[j]=0,v[j].clear();
	}
	return 0;
}